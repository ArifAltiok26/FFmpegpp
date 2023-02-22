#include "ffmpegpp.h"
#include <iostream>
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/audio_fifo.h>
#include <libavutil/channel_layout.h>
}
#include <atomic>
#include <memory>
#include <thread>
int main(int argc, char const *argv[])
{
    // First of all, If you're wondering what we're doing here, first read the explanations in the simple_read_write.cpp
    // file.

    using namespace ygv;

    InputFormatContextObject input("rtsp://admin:admin@192.168.1.14");

    input(find);

    int videoIndex = input(find, MediaType::VIDEO);
    int audioIndex = input(find, MediaType::AUDIO);

    std::cout << "ifvi" << videoIndex << std::endl;
    std::cout << "ifai" << audioIndex << std::endl;
    // There is no magic here.
    // I created a pattern myself. I want to see what parameters I am using on which object and what it returns me.
    // I achieved this by directing the initials of each word to the printout in the camel case spelling.
    // Accually, you dont need to do this.
    // I just want to redirect results to std::cout.

    const AVStream *inVideoStream = input->streams[videoIndex];
    const AVStream *inAudioStream = input->streams[audioIndex];

    const char *filename = "test.mp4";

    OutputFormatContextObject output(filename);

    AVStream *outVideoStream = output(create, nullptr);

    if (!outVideoStream)
    {
        throw std::runtime_error("couldn't create a new stream named outVideoStream into output");
    }

    {

        // Avoid scope leak.
        // Thus FFmpegpp objecs will be destroyed immediately when their lifecycle ends.

        // We just copied input video stream params to output video stream params.

        AVCodecParametersObject inVideoParams;
        std::cout << "ivpfivs" << inVideoParams(from, inVideoStream) << std::endl;
        std::cout << "inptovs" << inVideoParams(to, outVideoStream) << std::endl;

        // If you wonder that how we copied params to another one.
        // Please keep going and look at below scopes.
        // You will find more explanations below.
    }

    AVStream *outAudioStream = output(create);
    if (!outAudioStream)
    {
        throw std::runtime_error("couldn't create a new stream named outAudioStream into output");
    }

    DecoderContextObject decoder;
    EncoderContextObject encoder;
    SwrContextObject resampler;
    AVAudioFifoObject fifo;
    AVFrameObject resampler_buff[2];

    {
        // Avoid scope leak.
        // Thus FFmpegpp objecs will be destroyed immediately when their lifecycle ends.

        // Here, we prepare the transcoding parameters for audio.

        AVCodecParametersObject inAudioParams;
        AVCodecParametersObject outAudioParams;

        // Of course, we will use our object classes.

        // AVCodecParametersObject can take the data from some structures.
        // These structures are AVCodecParameters, AVCodecContext and AVStream.
        // And at the same thing it can load its data to them.

        // It means you can use "from and to" tags.

        // Use "from" tag when you want to take info from any structure.
        // Use "to" tag when you want to load info to any structure.

        // Also, it return its operation result.
        // If you want to check result.
        // 0 is succesful.
        // Otherwise the operation failed.

        // Accually, FFmpeg function returned it.

        // Here is example.

        std::cout << "iapfias" << inAudioParams(from, inAudioStream) << std::endl;
        inAudioParams->channel_layout = av_get_default_channel_layout(inAudioParams->channels);

        std::cout << "oapfias" << outAudioParams(from, inAudioStream) << std::endl;

        // We change destination audio codec,format and frame_size.
        // As you guessed, now, we are preparing transcoding options :)

        outAudioParams->channel_layout = av_get_default_channel_layout(outAudioParams->channels);

        outAudioParams->codec_id = AV_CODEC_ID_AAC;
        outAudioParams->format = AV_SAMPLE_FMT_FLTP;
        outAudioParams->frame_size = 1024;

        // The decoder will be opened with input audio params...
        std::cout << "doiap" << decoder(open, inAudioParams) << std::endl;

        // The encoder will be opened with output audio params...
        std::cout << "eooap" << encoder(open, outAudioParams) << std::endl;

        // If you want to record encoded packet to output.
        // Then you must copy the output audio params to the output audio stream.
        // Otherwise, your output file won't recognize this stream and
        // if you put to output them you won't see the result or you will get an error during the muxing.

        std::cout << "oaptoas" << outAudioParams(to, outAudioStream) << std::endl;

        // Format conversion between input and output is done with swr_context in FFmpeg.
        // It means resampling the input to the output.
        // Fortunately, we wrapped it in SwrContextObject.
        // Let's open the resampling context.

        std::cout << "rooap...iap..."
                  << resampler(open, outAudioParams->channel_layout, outAudioParams->format,
                               outAudioParams->sample_rate, inAudioParams->channel_layout, inAudioParams->format,
                               inAudioParams->sample_rate)
                  << std::endl;

        // Normally, opening some contexts in FFmpeg requires operations that are step-by-step.
        // As you can see here, we have provided the direct opening functionality.

        // Another issuu for resampling;
        // We need to have two buffers. One is required for resampling and the other for encoding.
        // Then Let's create them.
        for (int i = 0; i < 2; i++)
        {
            // Also, You don't have to use an array. You can use two seperate variable.
            // But i preferred to use an array.
            resampler_buff[i]->format = outAudioParams->format;
            resampler_buff[i]->channel_layout = outAudioParams->channel_layout;
            resampler_buff[i]->nb_samples = outAudioParams->frame_size;
            std::cout << "av_frame_get_buffer" << av_frame_get_buffer(resampler_buff[i], 0) << std::endl;
        }

        // Of course, the input and output audio frames are not the same sizes.
        // We should first put them to fifo.
        // Also, fifo stands for first in first out.
        // As you guessed, the input frames come in chunks.
        // So it can be larger or smaller than the output frame size.
        // First, we will take it and put into fifo.
        // Then we get the samples as much as output frame size when fifo size is bigger than output frame size.
        // The, we can resample it.
        // Accually, This is not releated to FFmpegpp, it is just an audio transcoding algorithm.
        // Our purpose is to present algorithm components easily.
        // The implementation of the algorithm is in the while loop. You can look at that.

        // Last of all, dont forget to open the fifo :).

        fifo(open, inAudioParams->format, inAudioParams->channels);
    }

    std::cout << "oof" << output(open, filename) << std::endl;

    std::cout << "ofn" << output(from, nullptr) << std::endl;

    std::atomic_bool isRunning(true);
    auto X = std::chrono::minutes(1);

    // You don't need to use any thread. But I want to terminate the program automatically after X time.

    std::thread worker([&] {
        AVPacketObject packet;
        AVFrameObject frame;

        int64_t pts = 0;

        while (isRunning)
        {

            // read packet from input.
            int retval = input(read, packet);
            if (retval >= 0)
            {
                // The packet is checked that is a video packet.
                if (packet->stream_index == inVideoStream->index)
                {
                    // We don't want to transcode it. Let's send it to the output as is.
                    packet->stream_index = outVideoStream->index;
                    packet(rescale, inVideoStream->time_base, outVideoStream->time_base);
                    retval = output(write, packet);
                }
                // The packet is checked that is a audio packet.
                else if (packet->stream_index == inAudioStream->index)
                {
                    // First, Let's decode packet in order to get a frame.
                    decoder(write, packet);
                    // Let's get a frame.
                    decoder(read, frame);

                    // Then, We should write the frame to the fifo.
                    // Dont process directly on it.
                    fifo(write, frame);

                    // Check fifo size
                    // fifo(read) call return fifo size.

                    if (fifo(read) >= resampler_buff[0]->nb_samples)
                    {
                        // We must here if the fifo size is enough as output frame size.
                        // Now we can read as much data as the output frame size.
                        fifo(read, resampler_buff[0]);

                        // Let's transcode buff[0] to buff[1] as resampled audio.
                        resampler(rescale, resampler_buff[0], resampler_buff[1]);
                        if (encoder(write, resampler_buff[1]) >= 0)
                        {
                            // As final step, Let's encode the resampled audio, then write to the output as audio.
                            AVPacketObject encoded;
                            if (encoder(read, encoded) >= 0)
                            {
                                encoded->stream_index = outAudioStream->index;
                                encoded->pts = pts;
                                encoded->dts = pts;
                                pts += encoded->duration;

                                encoded(rescale, inAudioStream->time_base, outAudioStream->time_base);
                                output(write, encoded);
                            }
                        }
                    }
                }
            }
        }
        av_write_trailer(output);

        std::cout << pts << std::endl;
    });

    std::this_thread::sleep_for(X);
    isRunning = false;
    worker.join();

    return 0;
}

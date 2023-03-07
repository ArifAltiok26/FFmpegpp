#include <iostream>

#include "ffmpegpp.h"
extern "C"
{
#include <libavformat/avformat.h>
}

#include <atomic>
#include <thread>

int main(int argc, char const *argv[])
{

    // In this example, We will see how, why and when to use "rescale" tag with AVPacketObject class.
    // Keep going towards to "thread loop", Magic is there :).

    using namespace ygv;

    InputFormatContextObject input("rtsp://admin:admin@192.168.1.3");

    if (input(find) < 0)
    {
        throw std::runtime_error("Couldn't found any stream in the input");
    }

    int inVideoIndex = input(find, MediaType::VIDEO);

    if (inVideoIndex < 0)
    {
        throw std::runtime_error("Couldn't found video stream in the input");
    }

    AVCodecParametersObject inVideoParams;

    if (inVideoParams(from, input->streams[inVideoIndex]) < 0)
    {
        throw std::runtime_error("Couldn't take the video params **FROM** the input");
    }

    const char *filename = "test.avi";

    OutputFormatContextObject output(filename);

    AVStream *outputVideoStream = output(create);

    if (nullptr == outputVideoStream)
    {
        throw std::runtime_error("outputVideoStream couldn't create");
    }

    int outVideoIndex = outputVideoStream->index;

    if (inVideoParams(to, outputVideoStream) < 0)
    {
        throw std::runtime_error("Couldn't load the video params **TO** the input");
    }

    if (output(open, filename) < 0)
    {
        throw std::runtime_error("Couldn't open the output context");
    }

    if (output(from, nullptr) < 0)
    {
        throw std::runtime_error("Couldn't write header to the output context");
    }

    // av_dump_format(output, 0, filename, 1);

    auto X = std::chrono::seconds(32);

    // You don't have to use any thread. But i want to terminate the program automatically after X time(s).

    std::atomic_bool isRunning(true);

    std::thread worker([&isRunning, inVideoIndex, outVideoIndex, &input, &output] {
        // If you want to play the video fast or slow such as +2x, -2x or any fold ( with NumberX ).

        // You can do that easily that way.

        // Just rescale the packet's pts :).

        // The pts means Packet TimeStamps.
        // This is important for media containers.
        // Else if, they won't know when to show which packet.

        // Lets back to idea, We want to show video packet as fast or slow.

        // Fortunately, we wrapped it in the AVPacketObject class.
        // It can be use like "packet(rescale,src_tb,dest_tb)".
        // The suffix "tb" means it is timebase that will be used in any stream which is input or output.
        // Actually, timabase is a rational number that is used in calculation of the packet timestamps (pts).

        // This seems like it's gone too far, but what we're actually doing isn't magic.

        // We have to know the timebase of the output video stream, and then we will able to rescale the pts of the
        // video packet.

        // First, let's decide what folding is.

        AVRational fold = {2, 1}; // It means it is +2x. :)
        // Positive fold -> {x,1}
        // Negative fold -> {1,x}

        // Second, let's find the timebase of source. This is easy just read it.
        AVRational src = input->streams[inVideoIndex]->time_base;

        // Next one, let's find the timebase of destination. It is easy, just read it and then multiply the fold.

        AVRational dest = av_mul_q(output->streams[outVideoIndex]->time_base, fold);

        while (isRunning)
        {
            AVPacketObject packet;
            if (!input(read, packet))
            {
                int index = packet->stream_index;
                if (inVideoIndex == index)
                {
                    packet->stream_index = outVideoIndex;
                    // Finally, let's rescale the pts of the packet. Just use like below.
                    packet(rescale, src, dest);

                    output(write, packet);
                }
            }
        }
        av_write_trailer(output);
    });

    std::this_thread::sleep_for(X);
    isRunning = false;
    worker.join();

    return 0;
}

#include "ffmpegpp.h"
extern "C"
{
#include <libavformat/avformat.h>
    // if you don't need to access details of FFmpeg components you don't need to include them individually.
    // FFmpegpp library already has enough information about FFmpeg components with Forward Declaration.
}

#include <atomic>
#include <iostream>
#include <thread>
int main(int argc, char const *argv[])
{
    // First of all, If you're wondering what we're doing here, first read the explanations in the simple_read.cpp file.
    using namespace ygv;

    // Also, you don't need to use any threads, but I want to terminate the program automatically after 10 seconds.

    std::atomic_bool isStop(false);
    std::thread worker([&isStop] {
        InputFormatContextObject input("rtsp://admin:admin@192.168.1.14");
        if (!input)
            throw "Input couldn't open";

        // We have another tag that is named find.
        // It calls FFmpeg function which is avformat_find_stream_info(input);
        input(find);

        int video_index = input(find, MediaType::VIDEO);
        // It calls FFmpeg function which is av_find_best_stream(input,AVMEDIA_TYPE_VIDEO,-1,-1,nullptr,0);
        // Also, default parameters of this calls are -1,-1,nullptr,0.
        // You can put another parameters which is FFmpeg function wants.

        int audio_index = input(find, MediaType::AUDIO);

        // Let's have a look at our tags with the examples and try to understand the main idea behind them.

        // For now, In alphabetical order tags are below;
        // create, find, from, open, read, rescale, to, write

        // Tags are useful when FFmpegpp objects have the same parameter package but need to call different functions.
        // Its main purpose is to bring them closer to colloquialism of the work to be done.
        // Also, you can create a new one if you want.

        // Moreover, the compiler optimizes these calls well at compile time and doesn't incur additional runtime costs.

        // Feel at home again :)

        // Assume that object is any FFmpegpp Object.
        // Assume that params is a variadic parameters pack.

        // object(create,params...);    -> when we create something on the object
        // object(find,params...);      -> when we search something on object
        // object(from,params...);      -> when we redirect information from params to object
        // object(open,params...);      -> if the object is a context we will open it with parameters
        // object(read,params...);      -> when perform read function and load into parameters if possible.
        // object(rescale,params...);   -> if the object is a scalable object.
        // object(to,params...);        -> when we redirect information from object to params
        // object(write,params...);     -> when perform write function and load into parameters if possible.

        // As you can see from the explanations, we actually have a static function in response to the tags and
        // parameter package implemented in an Object's policies class.

        // We will see later how to create a new tag and a new policy.

        std::cout << video_index << std::endl;
        std::cout << audio_index << std::endl;

        const char *filename = "test.avi";

        OutputFormatContextObject output(filename);

        AVStream *video = avformat_new_stream(output, nullptr);
        AVStream *audio = avformat_new_stream(output, nullptr);

        std::cout << avcodec_parameters_copy(video->codecpar, input->streams[video_index]->codecpar) << std::endl;
        std::cout << avcodec_parameters_copy(audio->codecpar, input->streams[audio_index]->codecpar) << std::endl;

        std::cout << avio_open(&output->pb, filename, AVIO_FLAG_WRITE) << std::endl;

        std::cout << avformat_write_header(output, nullptr) << std::endl;

        // As you can see that FFmpegpp Object Classes can be used with FFmpeg functions directly.
        // Why and How ?
        // Why -> We don't know what everyone is using FFmpeg for.
        // For this, FFmpegpp Objects are designed to work directly with ffmpeg functions.
        // But if you are using this library to avoid polluting your code and not dealing with FFmpeg
        // directly, have a look at what has been done for it instead of using them.

        // How -> Almost all of compilers is smart.
        // Also, FFmpegpp Object class has a operator DataType*(). It means it a casting operator :).
        // The compiler converts the object to be used in the call at compile time, if it is possible to cast it.
        // It does this thanks to the casting operator.

        AVPacketObject packet;

        while (!isStop)
        {
            if (!input(read, packet))
            {
                packet(rescale, input->streams[packet->stream_index]->time_base,
                       output->streams[packet->stream_index]->time_base);

                output(write, packet);
            }
        }
        av_write_trailer(output);
    });

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(10s);
    isStop = true;
    worker.join();
    return 0;
}

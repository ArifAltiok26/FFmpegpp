#include "ffmpegpp.h"
#include "operators/operators.h"
extern "C"
{
#include <libavformat/avformat.h>
}

#include <atomic>
#include <iostream>
#include <thread>
int main(int argc, char const *argv[])
{
    using namespace ygv;

    std::atomic_bool isStop(false);

    std::thread worker([&isStop] {
        InputFormatContextObject input("rtsp://admin:admin@192.168.1.14");
        if (!input)
            throw "Input couldn't open";

        self(input);
        int video_index = self(input, MediaType::VIDEO);

        int audio_index = input(SelfExecutionTag, MediaType::AUDIO);
        // instead of self operator you can do it like this way too

        // Lets have look at examples about Self,To and From operators usage.

        // The expressions on the left and on the right are the same.
        // Moreover, the compiler optimizes well regardless of the type of these calls.
        // It means You don't have to worry about which one to choose.

        // Feel at home again :)

        // Assume that object is any FFmpegpp Object.
        // Assume that params is a variadic parameters pack.

        //        Left                                  Right
        //    self(object,params...)      object(SelfExecutionTag,params...)
        //    to(object,params...)        object(ToExecutionTag,params...)
        //    from(object,params...)      object(FromExecutionTag,params...)

        // As you can see from the examples, we actually have a static function in response to the ExectionTag and
        // parameter package implemented in an Object's policies class.

        // The main idea behind this is that we can implement three different types of routing with the same parameter
        // package.

        // We have a rule that you don't have to follow when you add a new functionality. However, in order not to
        // conflict with motivation, it is important to understand what the Self, To and From tags do.

        // As you guessed;

        // The Self tag means that the object takes something from the parameters and will use it within itself.

        // The To tag means that the object will place something in the parameters.

        // The From tag means that it will take something from the parameters and it will load the results onto the
        // parameters.

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

        AVPacketObject packet;

        while (!isStop)
        {
            if (!to(input, packet))
            {
                self(packet, input->streams[packet->stream_index]->time_base,
                     output->streams[packet->stream_index]->time_base);

                from(output, packet);
                //  instead of to operator you can do like this
                // output(ToExecutionTag, packet);
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

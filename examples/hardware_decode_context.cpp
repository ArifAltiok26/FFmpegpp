#include "ffmpegpp.h"
extern "C"
{
#include <libavformat/avformat.h>
}
#include <atomic>
#include <iostream>
#include <thread>

// We didn't directly add headers about hardware.
// We have a few reason for this. But you can easily include them this way.
#include "types/hardware/decoder_context_object.h"
int main()
{
    using namespace ygv;

    InputFormatContextObject input("rtsp://admin:admin@192.168.1.3");

    input(find);

    int video_index = input(find, MediaType::VIDEO);

    // Computers have lots of component as such cpu, ram, rom etc.
    // Media streaming packets come as coded data.
    // We can decode them on the cpu.
    // But the cpu is not designed to do matrix operations.
    // Matrix operations is done in vector space.
    // Even if the cpu can do some of vector space operation, but there is a good device that desinged for matrix
    // operations.
    // Ta ta, The device is the gpu.

    // In media streaming, cpu means software device:).
    //
    // If the hardware opening is successful, then data comes from the gpu.
    // Otherwise it comes from cpu.
    // FFmpegpp library wrapped this function. You dont have to care, where the data comes from. :)

    // That's all.

    hardware::DecoderContextObject decoder_ctx;
    {

        // If You select the DeviceType as None, the context will be opened on the cpu.
        std::cout << decoder_ctx(create, hardware::DeviceType::VAAPI) << std::endl;

        decoder_ctx(open, input->streams[video_index]->codecpar);
    }

    std::atomic_bool isRunning(true);

    // Now, You know this that is done in this loop. :).
    // Steps:
    // Read packet from input
    // Check the packet is a video packet.
    // then write the packet to decoder.
    // then, read the frame from decoder.
    // Actually, decoder is working in gpu, but it knows how to transfer data to cpu.
    // Finally, you can do the image whatever you want.

    // By the way, have you ever worried about how Contexts or Data Objects are allocated or destroyed or transferred?

    // Dont worry, FFmpegpp library already come into play here.
    // Have a good day with implementing your algorithm.

    auto X = std::chrono::seconds(15);
    std::thread worker([&] {
        while (isRunning)
        {
            AVPacketObject packet;
            AVFrameObject frame;
            int retval = input(read, packet);
            if (!retval && packet->stream_index == video_index)
            {
                retval = decoder_ctx(write, packet);
                while (retval >= 0)
                {
                    retval = decoder_ctx(read, frame);
                    if (retval == AVERROR(EAGAIN) || retval == AVERROR_EOF)
                    {
                        retval = 0;
                        break;
                    }
                    else if (retval < 0)
                        break;

                    // Now, you can do whatever you want on the image data waiting for your use here:).
                }
            }
        }
    });
    std::this_thread::sleep_for(X);
    isRunning = false;
    worker.join();

    return 0;
}
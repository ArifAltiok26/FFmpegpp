#include "ffmpegpp.h"
extern "C"
{

#include <libavcodec/packet.h> // Packet Details

    // if you don't need to access details of FFmpeg components you don't need to include them individually.
    // FFmpegpp library already has enough information about FFmpeg components with Forward Declaration.
}

#include <atomic>
#include <iostream>
#include <thread>
int main(int argc, char const *argv[])
{

    // Also, you don't need to use any threads, but I want to terminate the program automatically after 10 seconds.

    std::atomic_bool isStop(false);
    std::thread worker([&isStop] {
        using namespace ygv;
        InputFormatContextObject input("rtsp://admin:admin@192.168.1.14");

        // if context couldn't open then we throw exception.
        // It means object is converted bool operator by compiler.

        // All of FFmpegpp objects can be converted bool operator :)

        if (!input)
            throw "Input couldn't open";

        // FFmpegpp Object classes are automatically allocated and destroyed.
        // Destruction is done when the lifecycle ends.
        // No need to be afraid of problems like Memory Leak.

        // This means that if the object is a context, the context is closed.
        // If it is an object that only holds data in memory, it is deleted from memory.

        // Actually, we didn't do this just for AVPacketObject.
        // You actually used this when you wanted to open an input above.
        // Be aware and Feel at home :)

        AVPacketObject packet;

        while (!isStop)
        {
            // Object with policy can be used like a function.
            // The function call can also be made on the variadic parameters.
            // If the Object has a matching function according to its own policies, it will redirect it.
            // If not, you will get an error at compile time.
            // To be honest, The FFmpegpp library tries to implement function overloading well.
            // Thus, the compiler understands them at compile time and does not incur additional overhead at runtime.

            // Also, using an object as a function brings it closer to colloquialism.
            // Let's look at the example below.

            if (!input(read, packet))
            {
                std::cout << packet->stream_index << std::endl;
            }

            // We have tags so that object functions can be implemented with the same parameter package but for
            // different purposes.
            // Also, You can create your own tags. We will see this later.

            // Going back to the example above, it doesn't seem too hard to think of it the way we want to read a packet
            // from the input, does it?

            // Feel at home and keep going.
        }
    });

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(10s);
    isStop = true;
    worker.join();
    return 0;
}

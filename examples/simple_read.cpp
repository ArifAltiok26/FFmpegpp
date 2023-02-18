#include "ffmpegpp.h"
#include "operators/operators.h"
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
            // The From operator is an operator that redirects to Object classes.
            // This redirection is determined by the compiler at compile time and invokes the correct execution method
            // of the policies class used by the object class, based on the parameter types.

            // To be honest, The FFmpegpp library tries to implement function overloading well.
            // Also, There are two more operators, their names are To and Self, such as the From operator.
            // Your will see them in other examples.

            // These operators are also useful for getting closer to colloquialism.
            // It can be read as follows:

            // Please, Give me a packet from input. :)
            if (!from(input, packet))
            {
                std::cout << packet->stream_index << std::endl;
            }
        }
    });

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(10s);
    isStop = true;
    worker.join();
    return 0;
}

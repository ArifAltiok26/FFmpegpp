#include "ffmpegpp.h"
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/hwcontext.h>
}
#include <atomic>
#include <functional>
#include <iostream>
#include <thread>
template <AVPixelFormat format> AVPixelFormat get_format(AVCodecContext *context, const AVPixelFormat *formats)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    while (*formats != AV_PIX_FMT_NONE)
    {
        if (*formats == format)
            return format;
        formats++;
    }
    std::cout << "failed to get HW surface format" << std::endl;
    return AV_PIX_FMT_NONE;
}

int main()
{
    using namespace ygv;

    InputFormatContextObject input("rtsp://admin:admin@192.168.1.14");

    input(find);

    AVBufferRef *hw_device_ctx = nullptr;
    int video_index = input(find, MediaType::VIDEO);

    // The purpose of this function is to solve where is data came from.
    // If the hardware opening is successful, then data comes from the gpu.
    // Otherwise it comes from cpu.
    // This function is assigned by us after hardware context is created or not.
    // That's all.

    std::function<AVFrame *(const AVFrame *src)> transfer_data;
    DecoderContextObject decoder_ctx;
    {

        AVCodecParametersObject inputVideoParams;
        av_hwdevice_ctx_create(&hw_device_ctx, AV_HWDEVICE_TYPE_VAAPI, nullptr, nullptr, 0);
        inputVideoParams(from, input->streams[video_index]);

        if (hw_device_ctx)
        {
            decoder_ctx->hw_device_ctx = hw_device_ctx;
            // You should change the template of get_format function if you changed AV_HWDEVICE_TYPE_XXX.
            // Have look at that in FFmpeg, which device wants which pixel format.
            // Let me give you a hint.
            // Generally, the pixel format template is AV_PIX_FMT_XXX and XXX is the device type :).
            decoder_ctx->get_format = get_format<AV_PIX_FMT_VAAPI>;
            transfer_data = [](const AVFrame *src) {
                AVFrame *dest = av_frame_alloc();
                // The data is in gpu, let's transfer it to cpu.
                av_hwframe_transfer_data(dest, src, 0);
                return dest;
            };
        }
        else
        {
            // The data is in cpu. Let's just copy it.
            transfer_data = [](const AVFrame *src) { return av_frame_clone(src); };
        }

        // Our open tag will open the decoder_ctx.
        decoder_ctx(open, inputVideoParams);
    }

    std::atomic_bool isRunning(true);

    // Now, You know this that is done in this loop. :).
    // Steps:
    // Read packet from input
    // Check the packet is a video packet.
    // then write the packet to decoder.
    // then, read the frame from decoder.
    // Specificially, the frame may come from gpu or cpu.
    // Our data transfer function will  solve this problem.
    // Finally, you can do the image whatever you want.

    // By the way, have you ever worried about how Contexts or Data Objects are allocated or destroyed?

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

                    AVFrameObject transferred_data = transfer_data(frame);
                    if (transferred_data)
                    {
                        // You can do whatever you want on the image coming from taransfer cpu or gpu.
                    }
                }
            }
        }
    });
    std::this_thread::sleep_for(X);
    isRunning = false;
    worker.join();

    return 0;
}
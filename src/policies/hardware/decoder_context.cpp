#include "types/hardware/decoder_context.h"
#include "decoder_context.h"
#include "types/avframe_object.h"
#include "types/avpacket_object.h"
#include "types/hardware/device_type.h"
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavutil/hwcontext.h>
}
namespace ygv
{

template <AVPixelFormat format> AVPixelFormat get_format(AVCodecContext *context, const AVPixelFormat *formats)
{

    while (*formats != AV_PIX_FMT_NONE)
    {
        if (*formats == format)
            return format;
        formats++;
    }

    return AV_PIX_FMT_NONE;
}

namespace hardware
{
struct DecoderContext;
enum class DeviceType;

namespace policies
{

int DecoderContext_w::execute(DecoderContext *context, const Write &write, AVPacket *packet)
{
    return context->decoder(write, packet);
}

int DecoderContext_w::execute(DecoderContext *context, const Read &read, AVFrame *dest)
{
    AVFrameObject src;
    context->decoder(read, src);
    return av_hwframe_transfer_data(dest, src, 0);
}

int DecoderContext_w::execute(DecoderContext *context, const Create, DeviceType type, const char *device,
                              AVDictionary *opts, int flags)
{

    AVPixelFormat (*get_format_callback)(AVCodecContext * context, const AVPixelFormat *formats) = nullptr;
    AVHWDeviceType ffmpeg_hw_type = AV_HWDEVICE_TYPE_NONE;
    switch (type)
    {
    case DeviceType::VDPAU:
        get_format_callback = get_format<AV_PIX_FMT_VDPAU>;
        ffmpeg_hw_type = AV_HWDEVICE_TYPE_VDPAU;
        break;
    case DeviceType::CUDA:
        get_format_callback = get_format<AV_PIX_FMT_CUDA>;
        ffmpeg_hw_type = AV_HWDEVICE_TYPE_CUDA;
        break;
    case DeviceType::VAAPI:
        get_format_callback = get_format<AV_PIX_FMT_VAAPI>;
        ffmpeg_hw_type = AV_HWDEVICE_TYPE_VAAPI;
        break;
    case DeviceType::DXVA2:
        get_format_callback = get_format<AV_PIX_FMT_DXVA2_VLD>;
        ffmpeg_hw_type = AV_HWDEVICE_TYPE_DXVA2;
        break;
    case DeviceType::QSV:
        get_format_callback = get_format<AV_PIX_FMT_QSV>;
        ffmpeg_hw_type = AV_HWDEVICE_TYPE_QSV;
        break;
    case DeviceType::VIDEOTOOLBOX:
        break;
    case DeviceType::D3D11VA:
        get_format_callback = get_format<AV_PIX_FMT_D3D11>;
        ffmpeg_hw_type = AV_HWDEVICE_TYPE_D3D11VA;
        break;
    case DeviceType::DRM:
        break;
    case DeviceType::OPENCL:
        break;
    case DeviceType::MEDIACODEC:
        break;
    case DeviceType::VULKAN:
        break;
    }

    if (!get_format_callback)
        return AVERROR(EINVAL);

    if (context->hw_context)
    {
        av_buffer_unref(&context->hw_context);
    }

    int retval = av_hwdevice_ctx_create(&context->hw_context, ffmpeg_hw_type, device, opts, flags);
    context->decoder->hw_device_ctx = context->hw_context;
    context->decoder->get_format = get_format_callback;
    return retval;
}

int DecoderContext_w::execute(DecoderContext *context, const Open &open, const AVCodecParameters *params,
                              AVDictionary **options)
{
    return context->decoder(open, params, options);
}

} // namespace policies
} // namespace hardware
} // namespace ygv
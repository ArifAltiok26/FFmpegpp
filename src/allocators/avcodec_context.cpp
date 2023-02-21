#include "avcodec_context.h"
extern "C"
{
#include <libavcodec/avcodec.h>
}

namespace ygv::allocators
{

AVCodecContext *AVCodecContext_w::allocate(const AVCodec *codec)
{
    return avcodec_alloc_context3(codec);
}

void AVCodecContext_w::destroy(AVCodecContext *context)
{
    avcodec_free_context(&context);
}
} // namespace ygv::allocators
#include "avcodec_context_allocator.h"
extern "C"
{
#include <libavcodec/avcodec.h>
}

namespace ygv
{

AVCodecContext *AVCodecContextAllocator::allocate(const AVCodec *codec)
{
    return avcodec_alloc_context3(codec);
}

void AVCodecContextAllocator::destroy(AVCodecContext *context)
{
    avcodec_free_context(&context);
}
} // namespace ygv
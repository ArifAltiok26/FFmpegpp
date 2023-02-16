#include "avcodec_context_allocator.h"
extern "C"
{
#include <libavcodec/avcodec.h>
}
AVCodecContext *AVCodecContextAllocator::allocate()
{
    return allocate(nullptr);
}

AVCodecContext *AVCodecContextAllocator::allocate(const AVCodec *codec)
{
    return avcodec_alloc_context3(codec);
}

void AVCodecContextAllocator::destroy(AVCodecContext *context)
{
    avcodec_free_context(&context);
}
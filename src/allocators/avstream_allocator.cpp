#include "avstream_allocator.h"
extern "C"
{
#include <libavformat/avformat.h>
}

AVStream *AVStreamAllocator::allocate(AVFormatContext *context)
{
    return allocate(context, nullptr);
}

AVStream *AVStreamAllocator::allocate(AVFormatContext *context, const AVCodec *codec)
{
    return avformat_new_stream(context, codec);
}

void AVStreamAllocator::destroy(AVStream *stream)
{
}

#include "codec_context_executor.h"
extern "C"
{
#include <libavcodec/avcodec.h>
}
int CodecContextExecutor::execute(AVCodecContext *context, const AVCodecParameters *params)
{
    return avcodec_parameters_to_context(context, params);
}

int CodecContextExecutor::execute(AVCodecContext *context)
{
    return execute(context, nullptr, nullptr);
}

int CodecContextExecutor::execute(AVCodecContext *context, const AVCodec *codec)
{
    return execute(context, codec, nullptr);
}

int CodecContextExecutor::execute(AVCodecContext *context, const AVCodec *codec, AVDictionary **options)
{
    return avcodec_open2(context, codec, options);
}
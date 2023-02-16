#include "avstream_executor.h"
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}
int AVStreamExecutor::execute(AVStream *stream, AVCodecParameters *params)
{
    return avcodec_parameters_copy(stream->codecpar, params);
}

int AVStreamExecutor::execute(AVStream *stream, AVStream *src)
{
    return execute(stream, src->codecpar);
}

int AVStreamExecutor::execute(AVStream *stream, AVCodecContext *context)
{
    AVCodecParameters params;
    avcodec_parameters_from_context(&params, context);
    return execute(stream, &params);
}

#include "output_format_context.h"
extern "C"
{
#include <libavformat/avformat.h>
}
namespace ygv::policies
{

int OutputFormatContext_w::execute(AVFormatContext *context, const Write &, AVPacket *packet)
{
    return av_interleaved_write_frame(context, packet);
}

int OutputFormatContext_w::execute(AVFormatContext *context, const From &, AVDictionary **options)
{
    return avformat_write_header(context, options);
}

int OutputFormatContext_w::execute(AVFormatContext *context, const Open &, const char *filename)
{
    return avio_open(&context->pb, filename, AVIO_FLAG_WRITE);
}

AVStream *OutputFormatContext_w::execute(AVFormatContext *context, const Create &, const AVCodec *codec)
{
    return avformat_new_stream(context, codec);
}
} // namespace ygv::policies
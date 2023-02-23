#include "input_format_context.h"
extern "C"
{
#include <libavformat/avformat.h>
}
namespace ygv::policies
{

int InputFormatContext_w::execute(AVFormatContext *context, const Read &, AVPacket *packet)
{
    return av_read_frame(context, packet);
}

int InputFormatContext_w::execute(AVFormatContext *context, const Find &find, MediaType type, const AVCodec **decoder)
{

    return execute(context, find, type, -1, -1, decoder, 0);
}

int InputFormatContext_w::execute(AVFormatContext *context, const Find &, MediaType type, int wanted_stream_nb,
                                  int related_stream, const AVCodec **decoder, int flags)
{
    AVMediaType ff_type;
    switch (type)
    {
    case MediaType::VIDEO:
        ff_type = AVMEDIA_TYPE_VIDEO;
        break;
    case MediaType::AUDIO:
        ff_type = AVMEDIA_TYPE_AUDIO;
        break;
    default:
        return -1;
    }
    return av_find_best_stream(context, ff_type, wanted_stream_nb, related_stream, decoder, flags);
}

int InputFormatContext_w::execute(AVFormatContext *context, const Find &, AVDictionary **options)
{
    return avformat_find_stream_info(context, options);
}

} // namespace ygv::policies
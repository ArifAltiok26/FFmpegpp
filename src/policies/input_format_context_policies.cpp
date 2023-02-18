#include "input_format_context_policies.h"
extern "C"
{
#include <libavformat/avformat.h>
}
namespace ygv
{

int InputFormatContextPolicies::execute(const ToExecution &, AVFormatContext *context, AVPacket *packet)
{
    return av_read_frame(context, packet);
}

int InputFormatContextPolicies::execute(const SelfExecution &, AVFormatContext *context, MediaType type)
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
    return av_find_best_stream(context, ff_type, -1, -1, nullptr, 0);
}

int InputFormatContextPolicies::execute(const SelfExecution &, AVFormatContext *context, AVDictionary **options)
{
    return avformat_find_stream_info(context, options);
}

} // namespace ygv
#include "avcodec_context_policies.h"
extern "C"
{
#include <libavcodec/avcodec.h>
}
namespace ygv
{

int AVCodecContextPolicies::execute(AVCodecContext *context, const Write &, const AVCodecParameters *params)
{
    return avcodec_parameters_to_context(context, params);
}

int AVCodecContextPolicies::execute(AVCodecContext *context, const Read &, AVCodecParameters *params)
{
    return avcodec_parameters_from_context(params, context);
}

int AVCodecContextPolicies::execute(AVCodecContext *context, const Open &, const AVCodec *codec, AVDictionary **options)
{
    return avcodec_open2(context, codec, options);
}

} // namespace ygv
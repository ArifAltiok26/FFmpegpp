#include "avcodec_context_policies.h"
extern "C"
{
#include <libavcodec/avcodec.h>
}
namespace ygv
{

int AVCodecContextPolicies::execute(const FromExecution &, AVCodecContext *context, const AVCodecParameters *params)
{
    return avcodec_parameters_to_context(context, params);
}

int AVCodecContextPolicies::execute(const ToExecution &, AVCodecContext *context, AVCodecParameters *params)
{
    return avcodec_parameters_from_context(params, context);
}

int AVCodecContextPolicies::execute(const SelfExecution &, AVCodecContext *context, const AVCodec *codec,
                                    AVDictionary **options)
{
    return avcodec_open2(context, codec, options);
}

} // namespace ygv
#include "avcodec_parameters_policies.h"
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}
namespace ygv
{

int AVCodecParametersPolicies::execute(AVCodecParameters *params, const From &, const AVCodecParameters *src)
{
    return avcodec_parameters_copy(params, src);
}

int AVCodecParametersPolicies::execute(AVCodecParameters *params, const To &, AVCodecParameters *dest)
{
    return avcodec_parameters_copy(dest, params);
}

int AVCodecParametersPolicies::execute(AVCodecParameters *params, const From &, const AVStream *stream)
{
    return avcodec_parameters_copy(params, stream->codecpar);
}

int AVCodecParametersPolicies::execute(const AVCodecParameters *params, const To &, AVStream *stream)
{
    return avcodec_parameters_copy(stream->codecpar, params);
}

int AVCodecParametersPolicies::execute(const AVCodecParameters *params, const To &, AVCodecContext *context)
{
    return avcodec_parameters_to_context(context, params);
}

int AVCodecParametersPolicies::execute(AVCodecParameters *params, const From &, const AVCodecContext *context)
{
    return avcodec_parameters_from_context(params, context);
}

} // namespace ygv
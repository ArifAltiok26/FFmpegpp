#include "avcodec_parameters.h"
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}
namespace ygv::policies
{

int AVCodecParameters_w::execute(AVCodecParameters *params, const From &, const AVCodecParameters *src)
{
    return avcodec_parameters_copy(params, src);
}

int AVCodecParameters_w::execute(AVCodecParameters *params, const To &, AVCodecParameters *dest)
{
    return avcodec_parameters_copy(dest, params);
}

int AVCodecParameters_w::execute(AVCodecParameters *params, const From &, const AVStream *stream)
{
    return avcodec_parameters_copy(params, stream->codecpar);
}

int AVCodecParameters_w::execute(const AVCodecParameters *params, const To &, AVStream *stream)
{
    return avcodec_parameters_copy(stream->codecpar, params);
}

int AVCodecParameters_w::execute(const AVCodecParameters *params, const To &, AVCodecContext *context)
{
    return avcodec_parameters_to_context(context, params);
}

int AVCodecParameters_w::execute(AVCodecParameters *params, const From &, const AVCodecContext *context)
{
    return avcodec_parameters_from_context(params, context);
}

} // namespace ygv::policies
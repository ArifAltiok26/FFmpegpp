#include "avcodec_context.h"
extern "C"
{
#include <libavcodec/avcodec.h>
}
namespace ygv::policies
{

int AVCodecContext_w::execute(AVCodecContext *context, const From &, const AVCodecParameters *params)
{
    return avcodec_parameters_to_context(context, params);
}

int AVCodecContext_w::execute(AVCodecContext *context, const To &, AVCodecParameters *params)
{
    return avcodec_parameters_from_context(params, context);
}

int AVCodecContext_w::execute(AVCodecContext *context, const Open &, const AVCodec *codec, AVDictionary **options)
{
    return avcodec_open2(context, codec, options);
}

} // namespace ygv::policies
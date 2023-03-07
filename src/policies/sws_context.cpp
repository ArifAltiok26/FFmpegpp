#include "sws_context.h"
extern "C"
{
#include <libavcodec/codec_par.h>
#include <libswscale/swscale.h>
}

namespace ygv::policies
{

int SwsContext_w::execute(SwsContext *&context, const Open &, int srcW, int srcH, int srcFormat, int dstW, int dstH,
                          int dstFormat, int flags, SwsFilter *srcFilter, SwsFilter *dstFilter, const double *param)
{
    context = sws_getCachedContext(context, srcW, srcH, (AVPixelFormat)srcFormat, dstW, dstH, (AVPixelFormat)dstFormat,
                                   flags, srcFilter, dstFilter, param);
    return nullptr == context;
}

int SwsContext_w::execute(SwsContext *&context, const Open &tag, const AVCodecParameters *src,
                          const AVCodecParameters *dest, int flags, SwsFilter *srcFilter, SwsFilter *dstFilter,
                          const double *param)
{
    return execute(context, tag, src->width, src->height, src->format, dest->width, dest->height, dest->format, flags,
                   srcFilter, dstFilter, param);
}

int SwsContext_w::execute(SwsContext *context, const Rescale &, const AVFrame *src, AVFrame *dest)
{
    // return sws_scale(context, src->data, src->linesize, 0, src->height, dest->data, dest->linesize);
    int retval = sws_scale_frame(context, dest, src);
    if (retval >= 0)
    {
        dest->pts = src->pts;
        dest->pkt_dts = src->pkt_dts;
        dest->pkt_duration = src->pkt_duration;
    }
    return retval;
}

} // namespace ygv::policies
#include "sws_context.h"
#include "types/video_frame_params.h"
extern "C"
{
#include <libswscale/swscale.h>
}

namespace ygv::allocators
{

SwsContext *SwsContext_w::allocate()
{

    return sws_alloc_context();
}

SwsContext *SwsContext_w::allocate(int srcW, int srcH, int srcFormat, int dstW, int dstH, int dstFormat, int flags,
                                   SwsFilter *srcFilter, SwsFilter *dstFilter, const double *param)
{
    return sws_getContext(srcW, srcH, (AVPixelFormat)srcFormat, dstW, dstH, (AVPixelFormat)dstFormat, flags, srcFilter,
                          dstFilter, param);
}

SwsContext *SwsContext_w::allocate(const VideoFrameParams &src, const VideoFrameParams &dest, int flags,
                                   SwsFilter *srcFilter, SwsFilter *dstFilter, const double *param)
{
    return allocate(src.width, src.height, src.format, dest.width, dest.height, dest.format, flags, srcFilter,
                    dstFilter, param);
}

void SwsContext_w::destroy(SwsContext *context)
{
    sws_freeContext(context);
}

} // namespace ygv::allocators
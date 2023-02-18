#include "sws_context_allocator.h"
#include "types/video_frame_params.h"
extern "C"
{
#include <libswscale/swscale.h>
}

namespace ygv
{

SwsContext *SwsContextAllocator::allocate(int srcW, int srcH, int srcFormat, int dstW, int dstH, int dstFormat,
                                          int flags, SwsFilter *srcFilter, SwsFilter *dstFilter, const double *param)
{
    return sws_getContext(srcW, srcH, (AVPixelFormat)srcFormat, dstW, dstH, (AVPixelFormat)dstFormat, flags, srcFilter,
                          dstFilter, param);
}

SwsContext *SwsContextAllocator::allocate(const VideoFrameParams &src, const VideoFrameParams &dest, int flags,
                                          SwsFilter *srcFilter, SwsFilter *dstFilter, const double *param)
{
    return allocate(src.width, src.height, src.format, dest.width, dest.height, dest.format, flags, srcFilter,
                    dstFilter, param);
}

void SwsContextAllocator::destroy(SwsContext *context)
{
    sws_freeContext(context);
}

} // namespace ygv
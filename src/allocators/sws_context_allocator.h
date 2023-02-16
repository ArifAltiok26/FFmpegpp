#pragma once
struct SwsContext;
struct VideoFrameParams;
struct SwsFilter;

struct SwsContextAllocator
{
    static SwsContext *allocate(int srcW, int srcH, int srcFormat, int dstW, int dstH, int dstFormat, int flags,
                                SwsFilter *srcFilter = nullptr, SwsFilter *dstFilter = nullptr,
                                const double *param = nullptr);

    static SwsContext *allocate(const VideoFrameParams &src, const VideoFrameParams &dest, int flags,
                                SwsFilter *srcFilter = nullptr, SwsFilter *dstFilter = nullptr,
                                const double *param = nullptr);

    static void destroy(SwsContext *context);
};
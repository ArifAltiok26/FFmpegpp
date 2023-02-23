#pragma once
struct SwsContext;
struct SwsFilter;

namespace ygv
{

struct VideoFrameParams;

namespace allocators
{

struct SwsContext_w
{
    static SwsContext *allocate();

    static SwsContext *allocate(int srcW, int srcH, int srcFormat, int dstW, int dstH, int dstFormat, int flags,
                                SwsFilter *srcFilter = nullptr, SwsFilter *dstFilter = nullptr,
                                const double *param = nullptr);

    static SwsContext *allocate(const VideoFrameParams &src, const VideoFrameParams &dest, int flags,
                                SwsFilter *srcFilter = nullptr, SwsFilter *dstFilter = nullptr,
                                const double *param = nullptr);

    static void destroy(SwsContext *context);
};

} // namespace allocators
} // namespace ygv
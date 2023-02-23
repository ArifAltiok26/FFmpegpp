#pragma once
#include "tags/open.h"
#include "tags/rescale.h"
struct SwsContext;
struct AVFrame;
struct SwsFilter;
struct AVCodecParameters;

namespace ygv::policies
{

struct SwsContext_w
{
    static int execute(SwsContext *&context, const Open &, int srcW, int srcH, int srcFormat, int dstW, int dstH,
                       int dstFormat, int flags, SwsFilter *srcFilter = nullptr, SwsFilter *dstFilter = nullptr,
                       const double *param = nullptr);

    static int execute(SwsContext *&context, const Open &, const AVCodecParameters *src, const AVCodecParameters *dest,
                       int flags, SwsFilter *srcFilter = nullptr, SwsFilter *dstFilter = nullptr,
                       const double *param = nullptr);

    static int execute(SwsContext *context, const Rescale &, const AVFrame *src, AVFrame *dest);
};

} // namespace ygv::policies
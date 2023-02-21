#pragma once
#include "tags/rescale.h"
struct SwsContext;
struct AVFrame;

namespace ygv::policies
{

struct SwsContext_w
{
    static int execute(SwsContext *context, const Rescale &, AVFrame *src, AVFrame *dest);
};

} // namespace ygv::policies
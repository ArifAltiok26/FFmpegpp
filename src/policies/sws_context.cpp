#include "sws_context.h"
extern "C"
{
#include <libswscale/swscale.h>
}

namespace ygv::policies
{

int SwsContext_w::execute(SwsContext *context, const Rescale &, AVFrame *src, AVFrame *dest)
{
    return sws_scale(context, src->data, src->linesize, 0, src->height, dest->data, dest->linesize);
}

} // namespace ygv::policies
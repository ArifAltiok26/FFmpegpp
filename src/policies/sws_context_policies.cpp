#include "sws_context_policies.h"
extern "C"
{
#include <libswscale/swscale.h>
}

namespace ygv
{

int SwsContextPolicies::execute(const FromExecution &, SwsContext *context, AVFrame *src, AVFrame *dest)
{
    return sws_scale(context, src->data, src->linesize, 0, src->height, dest->data, dest->linesize);
}

} // namespace ygv
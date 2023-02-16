#include "sws_context_executor.h"
extern "C"
{
#include <libswscale/swscale.h>
}

int SwsContextExecutor::execute(SwsContext *context, AVFrame *src, AVFrame *dest)
{
    return sws_scale(context, src->data, src->linesize, 0, src->height, dest->data, dest->linesize);
}
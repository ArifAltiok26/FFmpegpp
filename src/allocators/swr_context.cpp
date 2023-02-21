#include "swr_context.h"
extern "C"
{
#include <libswresample/swresample.h>
}

namespace ygv::allocators
{

SwrContext *SwrContext_w::allocate()
{
    return swr_alloc();
}

void SwrContext_w::destroy(SwrContext *context)
{
    if (!swr_is_initialized(context))
    {
        swr_close(context);
    }
    swr_free(&context);
}

} // namespace ygv::allocators

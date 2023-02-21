#include "swr_context_allocator.h"
extern "C"
{
#include <libswresample/swresample.h>
}

namespace ygv
{

SwrContext *SwrContextAllocator::allocate()
{
    return swr_alloc();
}

void SwrContextAllocator::destroy(SwrContext *context)
{
    if (!swr_is_initialized(context))
    {
        swr_close(context);
    }
    swr_free(&context);
}

} // namespace ygv

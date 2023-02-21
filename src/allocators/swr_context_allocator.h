#pragma once
#include <stdint.h>
struct SwrContext;
namespace ygv
{

struct SwrContextAllocator
{

    SwrContext *allocate();

    void destroy(SwrContext *context);
};

} // namespace ygv

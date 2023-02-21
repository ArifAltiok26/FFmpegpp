#pragma once
#include <stdint.h>
struct SwrContext;
namespace ygv::allocators
{

struct SwrContext_w
{

    SwrContext *allocate();

    void destroy(SwrContext *context);
};

} // namespace ygv::allocators

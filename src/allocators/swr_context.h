#pragma once
struct SwrContext;
namespace ygv::allocators
{

struct SwrContext_w
{

    static SwrContext *allocate();

    static void destroy(SwrContext *context);
};

} // namespace ygv::allocators

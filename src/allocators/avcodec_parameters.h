#pragma once
struct AVCodecParameters;

namespace ygv::allocators
{

struct AVCodecParameters_w
{
    static AVCodecParameters *allocate();

    static void destroy(AVCodecParameters *params);
};

} // namespace ygv::allocators
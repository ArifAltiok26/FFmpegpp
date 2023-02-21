#pragma once
struct AVCodecParameters;

namespace ygv::allocators
{

struct AVCodecParameters_w
{
    AVCodecParameters *allocate();

    void destroy(AVCodecParameters *params);
};

} // namespace ygv::allocators
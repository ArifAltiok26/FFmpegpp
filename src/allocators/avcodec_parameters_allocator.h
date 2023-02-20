#pragma once
struct AVCodecParameters;

namespace ygv
{

struct AVCodecParametersAllocator
{
    AVCodecParameters *allocate();

    void destroy(AVCodecParameters *params);
};

} // namespace ygv
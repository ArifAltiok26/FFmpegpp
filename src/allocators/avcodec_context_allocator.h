#pragma once
struct AVCodecContext;
struct AVCodec;

namespace ygv
{

struct AVCodecContextAllocator
{
    static AVCodecContext *allocate(const AVCodec *codec = nullptr);

    static void destroy(AVCodecContext *context);
};

} // namespace ygv
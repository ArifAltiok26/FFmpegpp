#pragma once
struct AVCodecContext;
struct AVCodec;

namespace ygv::allocators
{

struct AVCodecContext_w
{
    static AVCodecContext *allocate(const AVCodec *codec = nullptr);

    static void destroy(AVCodecContext *context);
};

} // namespace ygv::allocators
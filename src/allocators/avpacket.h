#pragma once

struct AVPacket;
namespace ygv::allocators
{

struct AVPacket_w
{
    static AVPacket *allocate();

    static void destroy(AVPacket *packet);
};

} // namespace ygv::allocators
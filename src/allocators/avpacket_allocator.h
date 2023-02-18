#pragma once

struct AVPacket;
namespace ygv
{

struct AVPacketAllocator
{
    static AVPacket *allocate();

    static void destroy(AVPacket *packet);
};

} // namespace ygv
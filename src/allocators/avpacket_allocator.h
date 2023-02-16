#pragma once

struct AVPacket;
struct AVPacketAllocator
{
    static AVPacket *allocate();

    static void destroy(AVPacket *packet);
};
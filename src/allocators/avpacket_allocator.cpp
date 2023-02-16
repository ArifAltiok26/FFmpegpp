#include "avpacket_allocator.h"
extern "C"
{
#include <libavcodec/packet.h>
}

AVPacket *AVPacketAllocator::allocate()
{
    return av_packet_alloc();
}

void AVPacketAllocator::destroy(AVPacket *packet)
{
    av_packet_free(&packet);
}
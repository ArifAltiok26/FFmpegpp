#include "avpacket.h"
extern "C"
{
#include <libavcodec/packet.h>
}

namespace ygv::allocators
{

AVPacket *AVPacket_w::allocate()
{
    return av_packet_alloc();
}

void AVPacket_w::destroy(AVPacket *packet)
{
    av_packet_free(&packet);
}

} // namespace ygv::allocators
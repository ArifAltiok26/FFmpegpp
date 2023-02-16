#include "avpacket_executor.h"
extern "C"
{
#include <libavcodec/packet.h>
}

void AVPacketExecutor::execute(AVPacket *packet, const AVRational &src, const AVRational &dest)
{
    av_packet_rescale_ts(packet, src, dest);
}
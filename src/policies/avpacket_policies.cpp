#include "avpacket_policies.h"
extern "C"
{
#include <libavcodec/packet.h>
#include <libavutil/avutil.h>
}

namespace ygv
{

void AVPacketPolicies::execute(AVPacket *packet, const Rescale &, const AVRational &src, const AVRational &dest)
{
    av_packet_rescale_ts(packet, src, dest);
}

} // namespace ygv

#include "avpacket.h"
extern "C"
{
#include <libavcodec/packet.h>
#include <libavutil/avutil.h>
}

namespace ygv::policies
{

void AVPacket_w::execute(AVPacket *packet, const Rescale &, const AVRational &src, const AVRational &dest)
{
    av_packet_rescale_ts(packet, src, dest);
}

} // namespace ygv::policies

#pragma once
#include "tags/rescale.h"
struct AVPacket;
struct AVRational;

namespace ygv::policies
{
struct AVPacket_w
{
    static void execute(AVPacket *packet, const Rescale &, const AVRational &src, const AVRational &dest);
};

} // namespace ygv::policies
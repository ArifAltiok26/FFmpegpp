#pragma once
#include "tags/self_execution.h"
struct AVPacket;
struct AVRational;

namespace ygv
{
struct AVPacketPolicies
{
    static void execute(const SelfExecution &, AVPacket *packet, const AVRational &src, const AVRational &dest);
};

} // namespace ygv
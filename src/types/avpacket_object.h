#pragma once
#include "allocators/avpacket.h"
#include "object.h"
#include "policies/avpacket.h"
struct AVPacket;
namespace ygv
{

using AVPacketObject = Object<AVPacket, allocators::AVPacket_w, policies::AVPacket_w>;

}
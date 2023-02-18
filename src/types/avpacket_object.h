#pragma once
#include "allocators/avpacket_allocator.h"
#include "object.h"
#include "policies/avpacket_policies.h"
struct AVPacket;
namespace ygv
{
using AVPacketObject = Object<AVPacket, AVPacketAllocator, AVPacketPolicies>;
}
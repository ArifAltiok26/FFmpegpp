#pragma once
#include "allocators/avpacket_allocator.h"
#include "executors/avpacket_executor.h"
#include "object.h"

using Packet = ygv::Object<AVPacket, AVPacketAllocator, AVPacketExecutor>;
#pragma once
#include "allocators/avpacket_allocator.h"
#include "executors/avpacket_executor.h"
#include "wrapper.h"

using Packet = ygv::Wrapper<AVPacket, AVPacketAllocator, AVPacketExecutor>;
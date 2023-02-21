#pragma once
#include "allocators/avaudio_fifo_allocator.h"
#include "object.h"
#include "policies/avaudio_fifo_policies.h"
namespace ygv
{

using AVAudioFifoObject = Object<AVAudioFifo, AVAudioFifoAllocator, AVAudioFifoPolicies>;

} // namespace ygv
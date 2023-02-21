#pragma once
#include "allocators/avaudio_fifo.h"
#include "object.h"
#include "policies/avaudio_fifo.h"
namespace ygv
{

using AVAudioFifoObject = Object<AVAudioFifo, allocators::AVAudioFifo_w, policies::AVAudioFifo_w>;

} // namespace ygv
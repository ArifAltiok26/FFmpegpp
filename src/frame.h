#pragma once
#include "allocators/avframe_allocator.h"
#include "wrapper.h"

using Frame = ygv::Wrapper<AVFrame, AVFrameAllocator, void>;
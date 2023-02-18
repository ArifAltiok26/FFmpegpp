#pragma once
#include "allocators/avframe_allocator.h"
#include "object.h"

using Frame = ygv::Object<AVFrame, AVFrameAllocator, void>;
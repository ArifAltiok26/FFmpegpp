#pragma once
#include "allocators/avframe_allocator.h"
#include "object.h"

namespace ygv
{
using AVFrameObject = ygv::Object<AVFrame, AVFrameAllocator, void>;
}
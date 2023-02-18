#pragma once
#include "allocators/default_allocator.h"
#include "object.h"
#include "video_frame_params.h"
namespace ygv
{
using VideoFrameParamsObject = Object<VideoFrameParams, DefaultAllocator<VideoFrameParams>, void>;
};
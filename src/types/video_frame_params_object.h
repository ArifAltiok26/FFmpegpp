#pragma once
#include "allocators/default.h"
#include "object.h"
#include "video_frame_params.h"
namespace ygv
{

using VideoFrameParamsObject = Object<VideoFrameParams, allocators::Default_w<VideoFrameParams>, void>;

};
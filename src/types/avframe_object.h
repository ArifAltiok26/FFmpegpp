#pragma once
#include "allocators/avframe.h"
#include "object.h"

namespace ygv
{

using AVFrameObject = ygv::Object<AVFrame, allocators::AVFrame_w, void>;

}
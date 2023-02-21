#pragma once
#include "allocators/avcodec_parameters.h"
#include "object.h"
#include "policies/avcodec_parameters.h"

struct AVCodecParameters;

namespace ygv
{

using AVCodecParametersObject =
    Object<AVCodecParameters, allocators::AVCodecParameters_w, policies::AVCodecParameters_w>;

}
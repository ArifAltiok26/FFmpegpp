#pragma once
#include "allocators/avcodec_parameters_allocator.h"
#include "object.h"
#include "policies/avcodec_parameters_policies.h"

struct AVCodecParameters;

namespace ygv
{
using AVCodecParametersObject = Object<AVCodecParameters, AVCodecParametersAllocator, AVCodecParametersPolicies>;
}
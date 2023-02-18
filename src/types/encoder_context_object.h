#pragma once
#include "allocators/avcodec_context_allocator.h"
#include "object.h"
#include "policies/encoder_context_policies.h"

namespace ygv
{
using EncoderContextObject = Object<AVCodecContext, AVCodecContextAllocator, EncoderContextPolicies>;
}
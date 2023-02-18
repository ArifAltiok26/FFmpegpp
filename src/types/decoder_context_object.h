#pragma once
#include "allocators/avcodec_context_allocator.h"
#include "object.h"
#include "policies/decoder_context_policies.h"

namespace ygv
{
using DecoderContextObject = Object<AVCodecContext, AVCodecContextAllocator, DecoderContextPolicies>;
}
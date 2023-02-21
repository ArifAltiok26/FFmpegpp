#pragma once
#include "allocators/avcodec_context.h"
#include "object.h"
#include "policies/decoder_context.h"

namespace ygv
{

using DecoderContextObject = Object<AVCodecContext, allocators::AVCodecContext_w, policies::DecoderContext_w>;

}
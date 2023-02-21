#pragma once
#include "allocators/avcodec_context.h"
#include "object.h"
#include "policies/encoder_context.h"

namespace ygv
{

using EncoderContextObject = Object<AVCodecContext, allocators::AVCodecContext_w, policies::EncoderContext_w>;

}
#pragma once
#include "allocators/hardware/decoder_context.h"
#include "decoder_context.h"
#include "device_type.h"
#include "policies/hardware/decoder_context.h"
#include "types/object.h"
namespace ygv
{
namespace hardware
{
using DecoderContextObject = Object<DecoderContext, allocators::DecoderContext_w, policies::DecoderContext_w>;
}
} // namespace ygv
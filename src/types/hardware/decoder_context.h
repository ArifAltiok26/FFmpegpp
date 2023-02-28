#pragma once
#include "types/decoder_context_object.h"

struct AVBufferRef;

namespace ygv
{

namespace hardware
{

struct DecoderContext
{
    DecoderContextObject decoder;
    AVBufferRef *hw_context = nullptr;
};

} // namespace hardware

} // namespace ygv
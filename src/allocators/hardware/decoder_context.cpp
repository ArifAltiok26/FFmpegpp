#include "decoder_context.h"
#include "types/hardware/decoder_context.h"
extern "C"
{
#include <libavutil/buffer.h>
}

namespace ygv
{

namespace hardware
{
namespace allocators
{

DecoderContext *DecoderContext_w::allocate()
{
    return new DecoderContext();
}

void DecoderContext_w::destroy(DecoderContext *context)
{
    av_buffer_unref(&context->hw_context);
    delete context;
}
} // namespace allocators
}; // namespace hardware
} // namespace ygv
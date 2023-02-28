#pragma once
namespace ygv
{

namespace hardware
{
struct DecoderContext;
namespace allocators
{

struct DecoderContext_w
{

    static DecoderContext *allocate();

    static void destroy(DecoderContext *context);
};
} // namespace allocators
}; // namespace hardware
} // namespace ygv
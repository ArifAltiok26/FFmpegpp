#pragma once
#include "tags/create.h"
#include "tags/open.h"
#include "tags/read.h"
#include "tags/write.h"
struct AVPacket;
struct AVFrame;
struct AVDictionary;
struct AVCodecParameters;

namespace ygv
{
namespace hardware
{
struct DecoderContext;
enum class DeviceType;

namespace policies
{

struct DecoderContext_w
{
    static int execute(DecoderContext *context, const Write &write, AVPacket *packet);

    static int execute(DecoderContext *context, const Read &read, AVFrame *dest);

    static int execute(DecoderContext *context, const Create, DeviceType type, const char *device = nullptr,
                       AVDictionary *opts = nullptr, int flags = 0);

    static int execute(DecoderContext *context, const Open &open, const AVCodecParameters *params,
                       AVDictionary **options = nullptr);
};
} // namespace policies
} // namespace hardware
} // namespace ygv
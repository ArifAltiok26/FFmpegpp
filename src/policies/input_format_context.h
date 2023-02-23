#pragma once
#include "tags/find.h"
#include "tags/read.h"
struct AVFormatContext;
struct AVPacket;
struct AVCodec;
struct AVDictionary;

namespace ygv
{

enum class MediaType
{
    VIDEO,
    AUDIO
};

namespace policies
{

struct InputFormatContext_w
{
    static int execute(AVFormatContext *context, const Read &, AVPacket *packet);

    static int execute(AVFormatContext *context, const Find &, MediaType type, const AVCodec **decoder);

    static int execute(AVFormatContext *context, const Find &, MediaType type, int wanted_stream_nb = -1,
                       int related_stream = -1, const AVCodec **decoder = nullptr, int flags = 0);

    static int execute(AVFormatContext *context, const Find &, AVDictionary **options = nullptr);
};

} // namespace policies
} // namespace ygv
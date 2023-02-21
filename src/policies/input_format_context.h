#pragma once
#include "tags/find.h"
#include "tags/read.h"
struct AVFormatContext;
struct AVPacket;
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

    static int execute(AVFormatContext *context, const Find &, MediaType type);

    static int execute(AVFormatContext *context, const Find &, AVDictionary **options = nullptr);
};

} // namespace policies
} // namespace ygv
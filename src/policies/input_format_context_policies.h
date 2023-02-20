#pragma once
#include "tags/find.h"
#include "tags/read.h"
struct AVFormatContext;
struct AVPacket;
struct AVDictionary;

enum class MediaType
{
    VIDEO,
    AUDIO
};

namespace ygv
{

struct InputFormatContextPolicies
{
    static int execute(AVFormatContext *context, const Read &, AVPacket *packet);

    static int execute(AVFormatContext *context, const Find &, MediaType type);

    static int execute(AVFormatContext *context, const Find &, AVDictionary **options = nullptr);
};

} // namespace ygv
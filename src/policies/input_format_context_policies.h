#pragma once
#include "tags/self_execution.h"
#include "tags/to_execution.h"
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
    static int execute(const ToExecution &, AVFormatContext *context, AVPacket *packet);

    static int execute(const SelfExecution &, AVFormatContext *context, MediaType type);

    static int execute(const SelfExecution &, AVFormatContext *context, AVDictionary **options = nullptr);
};

} // namespace ygv
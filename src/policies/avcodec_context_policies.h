#pragma once
struct AVCodecContext;
struct AVCodecParameters;
struct AVCodec;
struct AVDictionary;
#include "tags/tags.h"
namespace ygv
{

struct AVCodecContextPolicies
{
    static int execute(const FromExecution &, AVCodecContext *context, const AVCodecParameters *params);

    static int execute(const ToExecution &, AVCodecContext *context, AVCodecParameters *params);

    static int execute(const SelfExecution &, AVCodecContext *context, const AVCodec *codec = nullptr,
                       AVDictionary **options = nullptr);
};

} // namespace ygv
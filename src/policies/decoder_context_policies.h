#pragma once
#include "avcodec_context_policies.h"

struct AVPacket;
struct AVFrame;

namespace ygv
{

struct DecoderContextPolicies : AVCodecContextPolicies
{
    using AVCodecContextPolicies::execute;

    static int execute(const FromExecution &, AVCodecContext *context, AVPacket *packet);

    static int execute(const ToExecution &, AVCodecContext *context, AVFrame *frame);

    static int execute(const SelfExecution &, AVCodecContext *context, const AVCodecParameters *params,
                       AVDictionary **options = nullptr);
};

} // namespace ygv
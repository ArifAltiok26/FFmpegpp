#pragma once
#include "avcodec_context.h"
#include "tags/read.h"
#include "tags/write.h"
struct AVPacket;
struct AVFrame;

namespace ygv::policies
{

struct DecoderContext_w : AVCodecContext_w
{
    using AVCodecContext_w::execute;

    static int execute(AVCodecContext *context, const Write &, AVPacket *packet);

    static int execute(AVCodecContext *context, const Read &, AVFrame *frame);

    static int execute(AVCodecContext *context, const Open &, const AVCodecParameters *params,
                       AVDictionary **options = nullptr);
};

} // namespace ygv::policies
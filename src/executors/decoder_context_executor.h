#pragma once
#include "codec_context_executor.h"

struct AVPacket;
struct AVFrame;
struct AVStream;

struct DecoderContextExecutor : CodecContextExecutor
{
    using CodecContextExecutor::execute;

    static int execute(AVCodecContext *context, AVPacket *packet);

    static int execute(AVCodecContext *context, AVFrame *frame);

    static int execute(AVCodecContext *context, const AVCodecParameters *params, AVDictionary **options);
};
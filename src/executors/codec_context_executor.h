#pragma once
struct AVCodecContext;
struct AVCodecParameters;
struct AVCodec;
struct AVDictionary;

struct CodecContextExecutor
{
    static int execute(AVCodecContext *context, const AVCodecParameters *params);

    static int execute(AVCodecContext *context);

    static int execute(AVCodecContext *context, const AVCodec *codec);

    static int execute(AVCodecContext *context, const AVCodec *codec, AVDictionary **options);
};
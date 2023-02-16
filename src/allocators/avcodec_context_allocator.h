#pragma once
struct AVCodecContext;
struct AVCodec;

struct AVCodecContextAllocator
{
    static AVCodecContext *allocate();

    static AVCodecContext *allocate(const AVCodec *codec);

    static void destroy(AVCodecContext *context);
};
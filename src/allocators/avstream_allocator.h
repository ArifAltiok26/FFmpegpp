#pragma once
struct AVFormatContext;
struct AVCodec;
struct AVStream;

struct AVStreamAllocator
{
    static AVStream *allocate(AVFormatContext *context);

    static AVStream *allocate(AVFormatContext *context, const AVCodec *codec);

    static void destroy(AVStream *stream);
};
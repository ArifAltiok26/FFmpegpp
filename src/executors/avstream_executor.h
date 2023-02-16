#pragma once
struct AVStream;
struct AVCodecParameters;
struct AVCodecContext;

struct AVStreamExecutor
{
    static int execute(AVStream *stream, AVCodecParameters *params);

    static int execute(AVStream *stream, AVStream *src);

    static int execute(AVStream *stream, AVCodecContext *context);
};
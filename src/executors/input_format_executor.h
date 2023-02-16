#pragma once
struct AVFormatContext;
struct AVPacket;

struct InputFormatContextExecutor
{
    static int execute(AVFormatContext *context, AVPacket *packet);
};
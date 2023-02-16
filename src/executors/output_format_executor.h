#pragma once
struct AVFormatContext;
struct AVPacket;

struct OutputFormatContextExecutor
{
    static int execute(AVFormatContext *context, AVPacket *packet);
};
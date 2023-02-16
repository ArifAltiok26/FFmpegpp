#pragma once
struct SwsContext;
struct AVFrame;

struct SwsContextExecutor
{
    static int execute(SwsContext *context, AVFrame *src, AVFrame *dest);
};
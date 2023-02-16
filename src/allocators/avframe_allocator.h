#pragma once
struct AVFrame;
struct VideoFrameParams;
struct AVFrameAllocator
{
    static AVFrame *allocate();

    static AVFrame *allocate(const VideoFrameParams &params, int align = 0);

    static void destroy(AVFrame *frame);
};
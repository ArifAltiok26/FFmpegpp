#pragma once
struct AVFrame;
// struct VideoFrameParams;
namespace ygv::allocators
{

struct AVFrame_w
{
    static AVFrame *allocate();

    //  static AVFrame *allocate(const VideoFrameParams &params, int align = 0);

    static void destroy(AVFrame *frame);
};

} // namespace ygv::allocators
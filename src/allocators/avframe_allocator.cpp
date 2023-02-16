#include "avframe_allocator.h"
#include "data_types/video_frame_params.h"
extern "C"
{
#include <libavutil/frame.h>
}

AVFrame *AVFrameAllocator::allocate()
{
    return av_frame_alloc();
}

AVFrame *AVFrameAllocator::allocate(const VideoFrameParams &params, int align)
{
    AVFrame *frame = allocate();
    frame->width = params.width;
    frame->height = params.height;
    frame->format = params.format;
    av_frame_get_buffer(frame, align);
    return frame;
}

void AVFrameAllocator::destroy(AVFrame *frame)
{
    return av_frame_free(&frame);
}
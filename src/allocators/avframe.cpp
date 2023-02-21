#include "avframe.h"
//#include "data_types/video_frame_params.h"
extern "C"
{
#include <libavutil/frame.h>
}

namespace ygv::allocators
{

AVFrame *AVFrame_w::allocate()
{
    return av_frame_alloc();
}

// AVFrame *AVFrame_w::allocate(const VideoFrameParams &params, int align)
//{
//     AVFrame *frame = allocate();
//     frame->width = params.width;
//     frame->height = params.height;
//     frame->format = params.format;
//     av_frame_get_buffer(frame, align);
//     return frame;
// }

void AVFrame_w::destroy(AVFrame *frame)
{
    return av_frame_free(&frame);
}

} // namespace ygv::allocators
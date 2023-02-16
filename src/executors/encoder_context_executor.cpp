#include "encoder_context_executor.h"
extern "C"
{
#include <libavcodec/avcodec.h>
}

int EncoderContextExecutor::execute(AVCodecContext *context, AVPacket *packet)
{
    return avcodec_receive_packet(context, packet);
}

int EncoderContextExecutor::execute(AVCodecContext *context, AVFrame *frame)
{
    return avcodec_send_frame(context, frame);
}

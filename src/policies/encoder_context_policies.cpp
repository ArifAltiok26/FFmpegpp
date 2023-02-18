#include "encoder_context_policies.h"
extern "C"
{
#include <libavcodec/avcodec.h>
}

namespace ygv
{

int EncoderContextPolicies::execute(const ToExecution &, AVCodecContext *context, AVPacket *packet)
{
    return avcodec_receive_packet(context, packet);
}

int EncoderContextPolicies::execute(const FromExecution &, AVCodecContext *context, AVFrame *frame)
{
    return avcodec_send_frame(context, frame);
}

int EncoderContextPolicies::execute(const SelfExecution &, AVCodecContext *context, const AVCodecParameters *params,
                                    AVDictionary **options)
{
    const AVCodec *codec = avcodec_find_encoder(params->codec_id);
    execute(FromExecutionTag, context, params);
    return avcodec_open2(context, codec, options);
}
} // namespace ygv
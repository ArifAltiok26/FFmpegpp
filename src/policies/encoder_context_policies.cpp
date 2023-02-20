#include "encoder_context_policies.h"
extern "C"
{
#include <libavcodec/avcodec.h>
}

namespace ygv
{

int EncoderContextPolicies::execute(AVCodecContext *context, const Read &, AVPacket *packet)
{
    return avcodec_receive_packet(context, packet);
}

int EncoderContextPolicies::execute(AVCodecContext *context, const Write &, AVFrame *frame)
{
    return avcodec_send_frame(context, frame);
}

int EncoderContextPolicies::execute(AVCodecContext *context, const Open &, const AVCodecParameters *params,
                                    AVDictionary **options)
{
    const AVCodec *codec = avcodec_find_encoder(params->codec_id);
    execute(context, write, params);
    return execute(context, open, codec, options);
}
} // namespace ygv
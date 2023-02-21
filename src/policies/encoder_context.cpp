#include "encoder_context.h"
extern "C"
{
#include <libavcodec/avcodec.h>
}

namespace ygv::policies
{

int EncoderContext_w::execute(AVCodecContext *context, const Read &, AVPacket *packet)
{
    return avcodec_receive_packet(context, packet);
}

int EncoderContext_w::execute(AVCodecContext *context, const Write &, AVFrame *frame)
{
    return avcodec_send_frame(context, frame);
}

int EncoderContext_w::execute(AVCodecContext *context, const Open &, const AVCodecParameters *params,
                              AVDictionary **options)
{
    const AVCodec *codec = avcodec_find_encoder(params->codec_id);
    execute(context, write, params);
    return execute(context, open, codec, options);
}
} // namespace ygv::policies
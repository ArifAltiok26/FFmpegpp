#include "decoder_context.h"
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}
namespace ygv::policies
{

int DecoderContext_w::execute(AVCodecContext *context, const Write &, AVPacket *packet)
{
    return avcodec_send_packet(context, packet);
}

int DecoderContext_w::execute(AVCodecContext *context, const Read &, AVFrame *frame)
{
    return avcodec_receive_frame(context, frame);
}

int DecoderContext_w::execute(AVCodecContext *context, const Open &, const AVCodecParameters *params,
                              AVDictionary **options)
{
    const AVCodec *codec = avcodec_find_decoder(params->codec_id);
    execute(context, from, params);
    return execute(context, open, codec, options);
}

} // namespace ygv::policies
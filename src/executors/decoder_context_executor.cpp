#include "decoder_context_executor.h"
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

int DecoderContextExecutor::execute(AVCodecContext *context, AVPacket *packet)
{
    return avcodec_send_packet(context, packet);
}

int DecoderContextExecutor::execute(AVCodecContext *context, AVFrame *frame)
{
    return avcodec_receive_frame(context, frame);
}

int DecoderContextExecutor::execute(AVCodecContext *context, const AVCodecParameters *params, AVDictionary **options)
{
    const AVCodec *codec = avcodec_find_decoder(params->codec_id);
    execute(context, params);
    return avcodec_open2(context, codec, options);
}

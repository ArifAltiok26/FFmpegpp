#include "decoder_context_policies.h"
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}
namespace ygv
{

int DecoderContextPolicies::execute(const FromExecution &, AVCodecContext *context, AVPacket *packet)
{
    return avcodec_send_packet(context, packet);
}

int DecoderContextPolicies::execute(const ToExecution &, AVCodecContext *context, AVFrame *frame)
{
    return avcodec_receive_frame(context, frame);
}

int DecoderContextPolicies::execute(const SelfExecution &, AVCodecContext *context, const AVCodecParameters *params,
                                    AVDictionary **options)
{
    const AVCodec *codec = avcodec_find_decoder(params->codec_id);
    execute(FromExecutionTag, context, params);
    return avcodec_open2(context, codec, options);
}

} // namespace ygv
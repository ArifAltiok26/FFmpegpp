#include "swr_context.h"

extern "C"
{
#include <libavcodec/codec_par.h>
#include <libavutil/avutil.h>
#include <libswresample/swresample.h>
}
namespace ygv::policies
{

int SwrContext_w::execute(SwrContext *&context, const Open &, int64_t out_ch_layout, int out_sample_fmt,
                          int out_sample_rate, int64_t in_ch_layout, int in_sample_fmt, int in_sample_rate,
                          int log_offset, void *log_ctx)
{
    context = swr_alloc_set_opts(context, out_ch_layout, (AVSampleFormat)out_sample_fmt, out_sample_rate, in_ch_layout,
                                 (AVSampleFormat)in_sample_fmt, in_sample_rate, log_offset, log_ctx);
    return swr_init(context);
}

int SwrContext_w::execute(SwrContext *&context, const Open &open, const AVCodecParameters *src,
                          const AVCodecParameters *dest, int log_offset, void *log_ctx)
{
    return execute(context, open, dest->channel_layout, dest->format, dest->sample_rate, src->channel_layout,
                   src->format, src->sample_rate, log_offset, log_ctx);
}

int SwrContext_w::execute(SwrContext *context, const Rescale &tag, const AVFrame *src, AVFrame *dest)
{
    return execute(context, tag, (const uint8_t **)src->data, src->nb_samples, dest->data, dest->nb_samples);
}

int SwrContext_w::execute(SwrContext *context, const Rescale &tag, const AVFrame *src, uint8_t **dest, int dest_count)
{

    return execute(context, tag, (const uint8_t **)src->data, src->nb_samples, dest, dest_count);
}

int SwrContext_w::execute(SwrContext *context, const Rescale &tag, const uint8_t **src, int src_count, uint8_t **dest,
                          int dest_count)
{
    return swr_convert(context, dest, dest_count, src, src_count);
}

} // namespace ygv::policies
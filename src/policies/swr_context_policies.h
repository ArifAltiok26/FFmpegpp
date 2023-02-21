#pragma once
struct SwrContext;
struct AVFrame;
#include "tags/open.h"
#include "tags/rescale.h"
#include <stdint.h>

namespace ygv
{

struct SwrContextPolicies
{
    static int execute(SwrContext *&context, const Open &, int64_t out_ch_layout, int out_sample_fmt,
                       int out_sample_rate, int64_t in_ch_layout, int in_sample_fmt, int in_sample_rate,
                       int log_offset = 0, void *log_ctx = nullptr);

    static int execute(SwrContext *context, const Rescale &, const AVFrame *src, AVFrame *dest);

    static int execute(SwrContext *context, const Rescale &, const AVFrame *src, uint8_t **dest, int dest_count);

    static int execute(SwrContext *context, const Rescale &, const uint8_t **src, int src_count, uint8_t **dest,
                       int dest_count);
};
} // namespace ygv
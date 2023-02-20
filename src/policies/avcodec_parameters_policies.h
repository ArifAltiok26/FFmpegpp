#pragma once
#include "tags/from.h"
#include "tags/to.h"
struct AVCodecParameters;
struct AVStream;
struct AVCodecContext;
namespace ygv
{

struct AVCodecParametersPolicies
{
    static int execute(AVCodecParameters *params, const From &, const AVCodecParameters *src);

    static int execute(AVCodecParameters *params, const To &, AVCodecParameters *dest);

    static int execute(AVCodecParameters *params, const From &, const AVStream *stream);

    static int execute(const AVCodecParameters *params, const To &, AVStream *stream);

    static int execute(const AVCodecParameters *params, const To &, AVCodecContext *context);

    static int execute(AVCodecParameters *params, const From &, const AVCodecContext *context);
};

} // namespace ygv
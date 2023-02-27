#pragma once
struct AVCodecContext;
struct AVCodecParameters;
struct AVCodec;
struct AVDictionary;
#include "tags/from.h"
#include "tags/open.h"
#include "tags/to.h"
namespace ygv::policies
{

struct AVCodecContext_w
{
    static int execute(AVCodecContext *context, const From &, const AVCodecParameters *params);

    static int execute(AVCodecContext *context, const To &, AVCodecParameters *params);

    static int execute(AVCodecContext *context, const Open &, const AVCodec *codec = nullptr,
                       AVDictionary **options = nullptr);
};

} // namespace ygv::policies
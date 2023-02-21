#pragma once
struct AVCodecContext;
struct AVCodecParameters;
struct AVCodec;
struct AVDictionary;
#include "tags/open.h"
#include "tags/read.h"
#include "tags/write.h"
namespace ygv::policies
{

struct AVCodecContext_w
{
    static int execute(AVCodecContext *context, const Write &, const AVCodecParameters *params);

    static int execute(AVCodecContext *context, const Read &, AVCodecParameters *params);

    static int execute(AVCodecContext *context, const Open &, const AVCodec *codec = nullptr,
                       AVDictionary **options = nullptr);
};

} // namespace ygv::policies
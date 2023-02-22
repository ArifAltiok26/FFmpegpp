#pragma once
struct AVFormatContext;
struct AVPacket;
struct AVDictionary;
struct AVStream;
struct AVCodec;

#include "tags/create.h"
#include "tags/from.h"
#include "tags/open.h"
#include "tags/write.h"
namespace ygv::policies
{
struct OutputFormatContext_w
{
    static int execute(AVFormatContext *context, const Write &, AVPacket *packet);

    static int execute(AVFormatContext *context, const From &, AVDictionary **options);

    static int execute(AVFormatContext *context, const Open &, const char *filename);

    static AVStream *execute(AVFormatContext *context, const Create &, const AVCodec *codec = nullptr);
};
} // namespace ygv::policies
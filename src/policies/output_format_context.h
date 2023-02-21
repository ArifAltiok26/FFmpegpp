#pragma once
struct AVFormatContext;
struct AVPacket;
#include "tags/write.h"
namespace ygv::policies
{
struct OutputFormatContext_w
{
    static int execute(AVFormatContext *context, const Write &, AVPacket *packet);
};
} // namespace ygv::policies
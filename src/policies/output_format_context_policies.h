#pragma once
struct AVFormatContext;
struct AVPacket;
#include "tags/write.h"
namespace ygv
{
struct OutputFormatContextPolicies
{
    static int execute(AVFormatContext *context, const Write &, AVPacket *packet);
};
} // namespace ygv
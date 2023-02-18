#pragma once
struct AVFormatContext;
struct AVPacket;
#include "tags/from_execution.h"
namespace ygv
{
struct OutputFormatContextPolicies
{
    static int execute(const FromExecution &, AVFormatContext *context, AVPacket *packet);
};
} // namespace ygv
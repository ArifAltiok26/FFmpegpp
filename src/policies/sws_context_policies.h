#pragma once
#include "tags/from_execution.h"
struct SwsContext;
struct AVFrame;

namespace ygv
{

struct SwsContextPolicies
{
    static int execute(const FromExecution &, SwsContext *context, AVFrame *src, AVFrame *dest);
};

} // namespace ygv
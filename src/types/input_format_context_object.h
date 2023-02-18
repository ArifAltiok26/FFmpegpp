#pragma once
#include "allocators/input_format_context_allocator.h"
#include "object.h"
#include "policies/input_format_context_policies.h"
struct AVPacket;
namespace ygv
{
using InputFormatContextObject = Object<AVFormatContext, InputFormatContextAllocator, InputFormatContextPolicies>;
}
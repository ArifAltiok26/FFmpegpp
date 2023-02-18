#pragma once
#include "allocators/output_format_context_allocator.h"
#include "object.h"
#include "policies/output_format_context_policies.h"
namespace ygv
{
using OutputFormatContextObject = Object<AVFormatContext, OutputFormatContextAllocator, OutputFormatContextPolicies>;
}
#pragma once
#include "allocators/swr_context_allocator.h"
#include "object.h"
#include "policies/swr_context_policies.h"
namespace ygv
{
using SwrContextObject = Object<SwrContext, SwrContextAllocator, SwrContextPolicies>;
} // namespace ygv

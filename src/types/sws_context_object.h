#pragma once
#include "allocators/sws_context_allocator.h"
#include "object.h"
#include "policies/sws_context_policies.h"
namespace ygv
{
using SwsContextObject = Object<SwsContext, SwsContextAllocator, SwsContextPolicies>;
}
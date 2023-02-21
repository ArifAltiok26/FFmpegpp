#pragma once
#include "allocators/swr_context.h"
#include "object.h"
#include "policies/swr_context.h"
namespace ygv
{

using SwrContextObject = Object<SwrContext, allocators::SwrContext_w, policies::SwrContext_w>;

} // namespace ygv

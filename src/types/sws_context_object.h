#pragma once
#include "allocators/sws_context.h"
#include "object.h"
#include "policies/sws_context.h"
namespace ygv
{

using SwsContextObject = Object<SwsContext, allocators::SwsContext_w, policies::SwsContext_w>;

}
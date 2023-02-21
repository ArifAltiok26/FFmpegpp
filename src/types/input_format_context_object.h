#pragma once
#include "allocators/input_format_context.h"
#include "object.h"
#include "policies/input_format_context.h"
struct AVPacket;
namespace ygv
{

using InputFormatContextObject =
    Object<AVFormatContext, allocators::InputFormatContext_w, policies::InputFormatContext_w>;

}
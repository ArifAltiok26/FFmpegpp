#pragma once
#include "allocators/output_format_context.h"
#include "object.h"
#include "policies/output_format_context.h"
namespace ygv
{

using OutputFormatContextObject =
    Object<AVFormatContext, allocators::OutputFormatContext_w, policies::OutputFormatContext_w>;

}
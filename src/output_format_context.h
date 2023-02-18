#pragma once
#include "allocators/output_format_allocator.h"
#include "executors/output_format_executor.h"
#include "object.h"
using OutputFormatContext = ygv::Object<AVFormatContext, OutputFormatContextAllocator, OutputFormatContextExecutor>;
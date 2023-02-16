#pragma once
#include "allocators/output_format_allocator.h"
#include "executors/output_format_executor.h"
#include "wrapper.h"
using OutputFormatContext = ygv::Wrapper<AVFormatContext, OutputFormatContextAllocator, OutputFormatContextExecutor>;
#pragma once
#include "allocators/input_format_allocator.h"
#include "executors/input_format_executor.h"
#include "wrapper.h"

using InputFormatContext = ygv::Wrapper<AVFormatContext, InputFormatContextAllocator, InputFormatContextExecutor>;

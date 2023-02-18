#pragma once
#include "allocators/input_format_allocator.h"
#include "executors/input_format_executor.h"
#include "object.h"

using InputFormatContext = ygv::Object<AVFormatContext, InputFormatContextAllocator, InputFormatContextExecutor>;

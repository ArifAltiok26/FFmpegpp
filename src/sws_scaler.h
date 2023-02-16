#pragma once
#include "allocators/sws_context_allocator.h"
#include "executors/sws_context_executor.h"
#include "wrapper.h"
using SwsScaler = ygv::Wrapper<SwsContext, SwsContextAllocator, SwsContextExecutor>;
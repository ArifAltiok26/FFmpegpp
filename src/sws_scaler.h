#pragma once
#include "allocators/sws_context_allocator.h"
#include "executors/sws_context_executor.h"
#include "object.h"
using SwsScaler = ygv::Object<SwsContext, SwsContextAllocator, SwsContextExecutor>;
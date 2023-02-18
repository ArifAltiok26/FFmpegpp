#pragma once
#include "allocators/avstream_allocator.h"
#include "executors/avstream_executor.h"
#include "object.h"
using Stream = ygv::Object<AVStream, AVStreamAllocator, AVStreamExecutor>;
#pragma once
#include "allocators/avstream_allocator.h"
#include "executors/avstream_executor.h"
#include "wrapper.h"
using Stream = ygv::Wrapper<AVStream, AVStreamAllocator, AVStreamExecutor>;
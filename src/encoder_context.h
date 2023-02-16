#pragma once
#include "allocators/avcodec_context_allocator.h"
#include "executors/encoder_context_executor.h"
#include "wrapper.h"
using EncoderCodecContext = ygv::Wrapper<AVCodecContext, AVCodecContextAllocator, EncoderContextExecutor>;
#pragma once
#include "allocators/avcodec_context_allocator.h"
#include "executors/decoder_context_executor.h"
#include "wrapper.h"

using DecoderCodecContext = ygv::Wrapper<AVCodecContext, AVCodecContextAllocator, DecoderContextExecutor>;
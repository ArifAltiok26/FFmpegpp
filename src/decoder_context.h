#pragma once
#include "allocators/avcodec_context_allocator.h"
#include "executors/decoder_context_executor.h"
#include "object.h"

using DecoderCodecContext = ygv::Object<AVCodecContext, AVCodecContextAllocator, DecoderContextExecutor>;
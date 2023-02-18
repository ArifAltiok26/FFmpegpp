#pragma once
#include "allocators/avcodec_context_allocator.h"
#include "executors/encoder_context_executor.h"
#include "object.h"
using EncoderCodecContext = ygv::Object<AVCodecContext, AVCodecContextAllocator, EncoderContextExecutor>;
#include "output_format_context_allocator.h"

extern "C"
{
#include <libavformat/avformat.h>
}

namespace ygv
{

AVFormatContext *OutputFormatContextAllocator::allocate()
{
    return avformat_alloc_context();
}

AVFormatContext *OutputFormatContextAllocator::allocate(const char *filename)
{
    return allocate(nullptr, nullptr, filename);
}

AVFormatContext *OutputFormatContextAllocator::allocate(const AVOutputFormat *oformat, const char *format_name,
                                                        const char *filename)
{
    AVFormatContext *context = nullptr;
    avformat_alloc_output_context2(&context, oformat, format_name, filename);
    return context;
}

void OutputFormatContextAllocator::destroy(AVFormatContext *context)
{
    avformat_free_context(context);
}

} // namespace ygv
#include "output_format_context.h"

extern "C"
{
#include <libavformat/avformat.h>
}

namespace ygv::allocators
{

AVFormatContext *OutputFormatContext_w::allocate()
{
    return avformat_alloc_context();
}

AVFormatContext *OutputFormatContext_w::allocate(const char *filename)
{
    return allocate(nullptr, nullptr, filename);
}

AVFormatContext *OutputFormatContext_w::allocate(const AVOutputFormat *oformat, const char *format_name,
                                                 const char *filename)
{
    AVFormatContext *context = nullptr;
    avformat_alloc_output_context2(&context, oformat, format_name, filename);
    return context;
}

void OutputFormatContext_w::destroy(AVFormatContext *context)
{
    avformat_free_context(context);
}

} // namespace ygv::allocators
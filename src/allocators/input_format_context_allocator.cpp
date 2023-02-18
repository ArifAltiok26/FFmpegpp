#include "input_format_context_allocator.h"
extern "C"
{
#include <libavformat/avformat.h>
}
namespace ygv
{

AVFormatContext *InputFormatContextAllocator::allocate()
{
    return avformat_alloc_context();
}

AVFormatContext *InputFormatContextAllocator::allocate(const char *url)
{
    return allocate(url, nullptr, nullptr);
}

AVFormatContext *InputFormatContextAllocator::allocate(const char *url, AVInputFormat *format, AVDictionary **options)
{
    AVFormatContext *context = nullptr;
    avformat_open_input(&context, url, format, options);
    return context;
}

void InputFormatContextAllocator::destroy(AVFormatContext *context)
{
    avformat_close_input(&context);
}

} // namespace ygv
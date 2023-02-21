#include "input_format_context.h"
extern "C"
{
#include <libavformat/avformat.h>
}
namespace ygv::allocators
{

AVFormatContext *InputFormatContext_w::allocate()
{
    return avformat_alloc_context();
}

AVFormatContext *InputFormatContext_w::allocate(const char *url)
{
    return allocate(url, nullptr, nullptr);
}

AVFormatContext *InputFormatContext_w::allocate(const char *url, AVInputFormat *format, AVDictionary **options)
{
    AVFormatContext *context = nullptr;
    avformat_open_input(&context, url, format, options);
    return context;
}

void InputFormatContext_w::destroy(AVFormatContext *context)
{
    avformat_close_input(&context);
}

} // namespace ygv::allocators
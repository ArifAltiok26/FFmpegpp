#pragma once
struct AVFormatContext;
struct AVInputFormat;
struct AVDictionary;

namespace ygv::allocators
{

struct InputFormatContext_w
{
    static AVFormatContext *allocate();

    static AVFormatContext *allocate(const char *url);

    static AVFormatContext *allocate(const char *url, AVInputFormat *format, AVDictionary **options);

    static void destroy(AVFormatContext *context);
};

} // namespace ygv::allocators
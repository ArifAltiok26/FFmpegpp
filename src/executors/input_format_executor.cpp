#include "input_format_executor.h"
extern "C"
{
#include <libavformat/avformat.h>
}

int InputFormatContextExecutor::execute(AVFormatContext *context, AVPacket *packet)
{
    return av_read_frame(context, packet);
}

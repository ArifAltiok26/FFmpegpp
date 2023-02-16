#include "output_format_executor.h"
extern "C"
{
#include <libavformat/avformat.h>
}
int OutputFormatContextExecutor::execute(AVFormatContext *context, AVPacket *packet)
{
    return av_interleaved_write_frame(context, packet);
}
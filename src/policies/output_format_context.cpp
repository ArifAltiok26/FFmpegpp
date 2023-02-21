#include "output_format_context.h"
extern "C"
{
#include <libavformat/avformat.h>
}
namespace ygv::policies
{

int OutputFormatContext_w::execute(AVFormatContext *context, const Write &, AVPacket *packet)
{
    return av_interleaved_write_frame(context, packet);
}

} // namespace ygv::policies
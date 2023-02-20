#include "output_format_context_policies.h"
extern "C"
{
#include <libavformat/avformat.h>
}
namespace ygv
{

int OutputFormatContextPolicies::execute(AVFormatContext *context, const Write &, AVPacket *packet)
{
    return av_interleaved_write_frame(context, packet);
}

} // namespace ygv
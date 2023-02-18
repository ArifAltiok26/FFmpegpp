#include "output_format_context_policies.h"
extern "C"
{
#include <libavformat/avformat.h>
}
namespace ygv
{

int OutputFormatContextPolicies::execute(const FromExecution &, AVFormatContext *context, AVPacket *packet)
{
    return av_interleaved_write_frame(context, packet);
}

} // namespace ygv
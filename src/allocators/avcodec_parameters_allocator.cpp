#include "avcodec_parameters_allocator.h"
extern "C"
{
#include <libavcodec/codec_par.h>
}
namespace ygv
{

AVCodecParameters *AVCodecParametersAllocator::allocate()
{
    return avcodec_parameters_alloc();
}

void AVCodecParametersAllocator::destroy(AVCodecParameters *params)
{
    avcodec_parameters_free(&params);
}

} // namespace ygv
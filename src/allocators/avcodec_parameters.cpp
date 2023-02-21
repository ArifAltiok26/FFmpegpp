#include "avcodec_parameters.h"
extern "C"
{
#include <libavcodec/codec_par.h>
}
namespace ygv::allocators
{

AVCodecParameters *AVCodecParameters_w::allocate()
{
    return avcodec_parameters_alloc();
}

void AVCodecParameters_w::destroy(AVCodecParameters *params)
{
    avcodec_parameters_free(&params);
}

} // namespace ygv::allocators
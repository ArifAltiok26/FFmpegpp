#include "avaudio_fifo.h"
extern "C"
{
#include <libavutil/audio_fifo.h>
}
namespace ygv::allocators
{

AVAudioFifo *AVAudioFifo_w::allocate()
{
    return nullptr;
}

AVAudioFifo *AVAudioFifo_w::allocate(int sample_fmt, int channels, int nb_samples)
{
    return av_audio_fifo_alloc((AVSampleFormat)sample_fmt, channels, nb_samples < 1 ? 1 : nb_samples);
}

void AVAudioFifo_w::destroy(AVAudioFifo *buff)
{
    av_audio_fifo_free(buff);
}

} // namespace ygv::allocators

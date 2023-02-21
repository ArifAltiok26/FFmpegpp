#include "avaudio_fifo_allocator.h"
extern "C"
{
#include <libavutil/audio_fifo.h>
}
namespace ygv
{

AVAudioFifo *AVAudioFifoAllocator::allocate()
{
    return nullptr;
}

AVAudioFifo *AVAudioFifoAllocator::allocate(int sample_fmt, int channels, int nb_samples)
{
    return av_audio_fifo_alloc((AVSampleFormat)sample_fmt, channels, nb_samples < 1 ? 1 : nb_samples);
}

void AVAudioFifoAllocator::destroy(AVAudioFifo *buff)
{
    av_audio_fifo_free(buff);
}

} // namespace ygv

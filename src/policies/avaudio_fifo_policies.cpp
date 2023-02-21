#include "avaudio_fifo_policies.h"
extern "C"
{
#include <libavutil/audio_fifo.h>
#include <libavutil/frame.h>
}
namespace ygv
{

int AVAudioFifoPolicies::execute(AVAudioFifo *&af, const Open &, int sample_fmt, int channels, int nb_samples)
{
    af = av_audio_fifo_alloc(AVSampleFormat(sample_fmt), channels, nb_samples < 1 ? 1 : nb_samples);
    return !af;
}

int AVAudioFifoPolicies::execute(AVAudioFifo *af, const Write &, AVFrame *src)
{
    return av_audio_fifo_write(af, (void **)src->data, src->nb_samples);
}

int AVAudioFifoPolicies::execute(AVAudioFifo *af, const Read &)
{
    return av_audio_fifo_size(af);
}

int AVAudioFifoPolicies::execute(AVAudioFifo *af, const Read &, AVFrame *dest)
{
    return av_audio_fifo_read(af, (void **)dest->data, dest->nb_samples);
}

} // namespace ygv
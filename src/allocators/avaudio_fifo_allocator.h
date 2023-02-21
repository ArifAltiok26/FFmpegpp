#pragma once

struct AVAudioFifo;

namespace ygv
{

struct AVAudioFifoAllocator
{
    AVAudioFifo *allocate();

    AVAudioFifo *allocate(int sample_fmt, int channels, int nb_samples = 0);

    void destroy(AVAudioFifo *buff);
};

} // namespace ygv

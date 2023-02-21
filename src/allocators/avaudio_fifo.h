#pragma once

struct AVAudioFifo;

namespace ygv::allocators
{

struct AVAudioFifo_w
{
    AVAudioFifo *allocate();

    AVAudioFifo *allocate(int sample_fmt, int channels, int nb_samples = 0);

    void destroy(AVAudioFifo *buff);
};

} // namespace ygv::allocators

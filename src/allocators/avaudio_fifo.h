#pragma once

struct AVAudioFifo;

namespace ygv::allocators
{

struct AVAudioFifo_w
{
    static AVAudioFifo *allocate();

    static AVAudioFifo *allocate(int sample_fmt, int channels, int nb_samples = 0);

    static void destroy(AVAudioFifo *buff);
};

} // namespace ygv::allocators

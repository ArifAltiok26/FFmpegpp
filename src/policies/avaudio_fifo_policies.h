#pragma once
#include "tags/open.h"
#include "tags/read.h"
#include "tags/write.h"
struct AVAudioFifo;
struct AVFrame;

namespace ygv
{

struct AVAudioFifoPolicies
{
    static int execute(AVAudioFifo *&af, const Open &, int sample_fmt, int channels, int nb_samples = 0);

    static int execute(AVAudioFifo *af, const Write &, AVFrame *src);

    static int execute(AVAudioFifo *af, const Read &);

    static int execute(AVAudioFifo *af, const Read &, AVFrame *dest);
};

} // namespace ygv
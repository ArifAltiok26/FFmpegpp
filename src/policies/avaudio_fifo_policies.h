#pragma once
#include "tags/read.h"
#include "tags/write.h"
struct AVAudioFifo;
struct AVFrame;

namespace ygv
{

struct AVAudioFifoPolicies
{
    static int execute(AVAudioFifo *af, const Write &, AVFrame *src);

    static int execute(AVAudioFifo *af, const Read &);

    static int execute(AVAudioFifo *af, const Read &, AVFrame *dest);
};

} // namespace ygv
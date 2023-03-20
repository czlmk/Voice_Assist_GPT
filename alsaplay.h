#ifndef ALSAPLAY_H
#define ALSAPLAY_H

#include <alsa/asoundlib.h>
#include <flite/flite.h>

class AlsaPlay {
public:
    AlsaPlay();
    ~AlsaPlay();
    void stop();
    void play(cst_wave* wave);

private:
    snd_pcm_t* pcm_handle;
    int err;
    int frames;
};

#endif
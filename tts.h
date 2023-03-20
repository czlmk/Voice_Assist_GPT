#ifndef TTS_H
#define TTS_H
//uses flite to synthesize audio from string
#include <flite/flite.h>
#include <iostream>

class TTS {
public:
    TTS();
    ~TTS();
    cst_wave* synthesize(const std::string text);

private:

    cst_wave* wave;
    cst_voice* voice;
};
#endif //TTS_H
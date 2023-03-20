#include "tts.h"
#include <flite/cst_wave.h>



extern "C" {

cst_voice *register_cmu_us_slt();
void unregister_cmu_us_slt(cst_voice *vox);
}

TTS::TTS(){
    flite_init();
    voice = register_cmu_us_slt();
    wave = NULL;
}

TTS::~TTS(){
    if (wave != NULL) {
        delete_wave(wave);
        wave = NULL;
    }

    unregister_cmu_us_slt(voice);
}

cst_wave* TTS::synthesize(const std::string text)
{
    
    if (wave != NULL) {
        delete_wave(wave);
        wave = NULL;
    }
    wave = flite_text_to_wave(text.c_str(), voice);
    
    return wave;
}


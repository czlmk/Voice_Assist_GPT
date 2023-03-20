#include "alsaplay.h"

AlsaPlay::AlsaPlay() {
    // Open the default PCM device for playback
    if ((err = snd_pcm_open(&pcm_handle, "default", SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
        fprintf(stderr, "AlsaPlay::AlsaPlay(): Cannot open PCM device: %s\n", snd_strerror(err));
        exit(EXIT_FAILURE);
    }
    // Set the hardware parameters for the PCM device
    snd_pcm_hw_params_t* hw_params;
    snd_pcm_hw_params_alloca(&hw_params);
    if ((err = snd_pcm_hw_params_any(pcm_handle, hw_params)) < 0) {
        fprintf(stderr, "AlsaPlay::AlsaPlay(): Cannot configure PCM device: %s\n", snd_strerror(err));
        exit(EXIT_FAILURE);
    }
    
    if ((err = snd_pcm_hw_params_set_access(pcm_handle, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
        fprintf(stderr, "AlsaPlay::AlsaPlay(): Cannot set access type for PCM device: %s\n", snd_strerror(err));
        exit(EXIT_FAILURE);
    }
    
    if ((err = snd_pcm_hw_params_set_format(pcm_handle, hw_params, SND_PCM_FORMAT_S16_LE)) < 0) {
        fprintf(stderr, "AlsaPlay::AlsaPlay(): Cannot set sample format for PCM device: %s\n", snd_strerror(err));
        exit(EXIT_FAILURE);
    }
    unsigned int sample_rate = 16000; // default sample rate
    if ((err = snd_pcm_hw_params_set_rate_near(pcm_handle, hw_params, &sample_rate, 0)) < 0) {
        fprintf(stderr, "AlsaPlay::AlsaPlay(): Cannot set sample rate for PCM device: %s\n", snd_strerror(err));
        exit(EXIT_FAILURE);
    }
    if ((err = snd_pcm_hw_params_set_channels(pcm_handle, hw_params, 1)) < 0) {
        fprintf(stderr, "AlsaPlay::AlsaPlay(): Cannot set channel count for PCM device: %s\n", snd_strerror(err));
        exit(EXIT_FAILURE);
    }
    
    if ((err = snd_pcm_hw_params(pcm_handle, hw_params)) < 0) {
        fprintf(stderr, "AlsaPlay::AlsaPlay(): Cannot set parameters for PCM device: %s\n", snd_strerror(err));
        exit(EXIT_FAILURE);
    }

    // Prepare the PCM device for playback
    if ((err = snd_pcm_prepare(pcm_handle)) < 0) {
        fprintf(stderr, "AlsaPlay::AlsaPlay(): Cannot prepare PCM device for playback: %s\n", snd_strerror(err));
        exit(EXIT_FAILURE);
    }
}

AlsaPlay::~AlsaPlay() {
    // Close the PCM device

    if (pcm_handle) {
        if((err = snd_pcm_close(pcm_handle))<0){
        fprintf(stderr, "AlsaPlay::~AlsaPlay: closing failed %s\n", snd_strerror(err));
        exit(EXIT_FAILURE);
        }
    }
}

void AlsaPlay::stop() {
    snd_pcm_drop(pcm_handle);
}
void AlsaPlay::play(cst_wave* wave) {
    // Write the audio data from the wave object to the PCM device
    snd_pcm_writei(pcm_handle, wave->samples, wave->num_samples);
    if (frames < 0) {
    frames = snd_pcm_recover(pcm_handle, frames, 0);
        if (frames < 0) {
            fprintf(stderr, "AlsaPlay::play(): Failed to recover PCM device after write error: %s\n", snd_strerror(frames));
            exit(EXIT_FAILURE);
        }
    }
    if (frames != wave->num_samples) {
        fprintf(stderr, "AlsaPlay::play(): Failed to write all audio data to PCM device: %d/%d frames written\n", frames, wave->num_samples);
        //exit(EXIT_FAILURE);
    }


    // Drain the PCM device

    if ((err = snd_pcm_drain(pcm_handle)) < 0) {
        printf("Error draining PCM device: %s\n", snd_strerror(err));
        exit(EXIT_FAILURE);
    }
}
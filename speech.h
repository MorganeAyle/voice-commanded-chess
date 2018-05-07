#include <pocketsphinx.h>
#include <sphinxbase/ad.h>
#include <sphinxbase/err.h>

//#include "mycontinuous.cpp"
#include "commands.h"

#define MODELDIR "../cmusphinx/pocketsphinx/model"

#ifndef SPEECH_H
#define SPEECH_H

class Speech
{
public:
    Speech();
    ~Speech();
    int start(int game, Commands allCommands);

    const char * recognize_from_microphone();

    ps_decoder_t *ps;                  // create pocketsphinx decoder structure
    cmd_ln_t *config;                  // create configuration structure
    ad_rec_t *ad;                      // create audio recording structure - for use with ALSA functions

    int16 adbuf[4096];                 // buffer array to hold audio data
    uint8 utt_started, in_speech;      // flags for tracking active speech - has speech started? - is speech currently happening?
    int32 k;                           // holds the number of frames in the audio buffer
    char const *hyp;                   // pointer to "hypothesis" (best guess at the decoded result)
    char const *decoded_speech;
};

#endif // SPEECH_H

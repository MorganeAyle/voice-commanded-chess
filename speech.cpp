#include "speech.h"

Speech::Speech()
{

}

Speech::~Speech() {
    delete this;
}

int Speech::start(int game, Commands allCommands) {
    QByteArray modeldir = MODELDIR;
    if (game == TETRIS)
        modeldir.append("/en-us/tetrisdict.dict");
    else
        modeldir.append("/en-us/chessdict.dict");

    const char* dictpath = modeldir.data();

    config = cmd_ln_init (NULL, ps_args(), TRUE,
    "-hmm", MODELDIR "/en-us/en-us",                       // Acoustic Model Path
    "-lm", MODELDIR "/en-us/en-us.lm.bin",                 // Language Model Path
    "-dict", dictpath,                                     // Dictionary Path
    NULL);

    ps = ps_init(config);                                                        // initialize the pocketsphinx decoder
    ad = ad_open_dev("sysdefault", (int) cmd_ln_float32_r(config, "-samprate")); // open default microphone at default samplerate

    if ((ad = ad_open_dev(cmd_ln_str_r(config, "-adcdev"),
                                  (int) cmd_ln_float32_r(config,
                                                         "-samprate"))) == NULL)
        E_FATAL("Failed to open audio device\n");
    if (ad_start_rec(ad) < 0)
        E_FATAL("Failed to start recording\n");

    while(1){
        decoded_speech = recognize_from_microphone();         		  // call the function to capture and decode speech
        printf("You Said: %s\n", decoded_speech);								// send decoded speech to screen
        allCommands.validate(decoded_speech);
    }

     ad_close(ad);                                                    // close the microphone

    return 0;
}

const char * Speech::recognize_from_microphone(){

    ad_start_rec(ad);                                // start recording
    ps_start_utt(ps);                                // mark the start of the utterance
    utt_started = FALSE;                             // clear the utt_started flag

    while(1) {
        k = ad_read(ad, adbuf, 4096);                // capture the number of frames in the audio buffer
        ps_process_raw(ps, adbuf, k, FALSE, FALSE);  // send the audio buffer to the pocketsphinx decoder

        in_speech = ps_get_in_speech(ps);            // test to see if speech is being detected

        if (in_speech && !utt_started) {             // if speech has started and utt_started flag is false
            utt_started = TRUE;                      // then set the flag
        }

        if (!in_speech && utt_started) {             // if speech has ended and the utt_started flag is true
            ps_end_utt(ps);                          // then mark the end of the utterance
            ad_stop_rec(ad);                         // stop recording
            hyp = ps_get_hyp(ps, NULL );             // query pocketsphinx for "hypothesis" of decoded statement
            return hyp;                              // the function returns the hypothesis
            break;                                   // exit the while loop and return
        }
    }

}

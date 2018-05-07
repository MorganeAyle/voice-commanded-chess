#include "speech.h"

Speech::Speech()
{

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


    ps = ps_init(config);
    recognize_from_microphone(allCommands); // from mycontinuous.cpp

    return 0;
}

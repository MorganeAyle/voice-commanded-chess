#include "speech.h"

Speech::Speech()
{

}

int Speech::start(int game, Commands allCommands) {
    if (game == TETRIS) {
        config = cmd_ln_init (NULL, ps_args(), TRUE,
        "-hmm", MODELDIR "/en-us/en-us",                       // Acoustic Model Path
        "-lm", MODELDIR "/en-us/en-us.lm.bin",                 // Language Model Path
        "-dict", MODELDIR "/en-us/persdict.dict",         // Dictionary Path
         NULL);
    }
    else {
        config = cmd_ln_init (NULL, ps_args(), TRUE,
        "-hmm", MODELDIR "/en-us/en-us",                       // Acoustic Model Path
        "-lm", MODELDIR "/en-us/en-us.lm.bin",                 // Language Model Path
        "-dict", MODELDIR "/en-us/dict2.dict",         // Dictionary Path
         NULL);
    }

ps = ps_init(config);
recognize_from_microphone(allCommands); // from mycontinuous.cpp

return 0;
}

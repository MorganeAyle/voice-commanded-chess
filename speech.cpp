#include "speech.h"

Speech::Speech()
{

}

int Speech::start(Commands allCommands) {
    config = cmd_ln_init (NULL, ps_args(), TRUE,
    "-hmm", MODELDIR "/en-us/en-us",                       // Acoustic Model Path
    "-lm", MODELDIR "/en-us/en-us.lm.bin",                 // Language Model Path
    "-dict", MODELDIR "/en-us/cmudict-en-us(copy).dict",         // Dictionary Path
     NULL);

ps = ps_init(config);
recognize_from_microphone(allCommands); // from myContinuous.cpp

return 0;
}

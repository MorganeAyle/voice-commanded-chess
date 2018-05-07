#include <pocketsphinx.h>
#include "mycontinuous.cpp"
#include "commands.h"

#define MODELDIR "/home/morgane/Desktop/cmusphinx/pocketsphinx/model"

#ifndef SPEECH_H
#define SPEECH_H


class Speech
{
public:
    Speech();

    int start(int game, Commands allCommands);
};

#endif // SPEECH_H

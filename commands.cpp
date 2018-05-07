#include "commands.h"

Commands::Commands()
{
    this->game = CHESS;

    sharedMemory = new QSharedMemory("VoiceChess", NULL);
    if (!sharedMemory->create(11)) {
        qDebug() << "unable to create shared mem";
        qDebug() << QString::fromUtf8(sharedMemory->errorString().toStdString().c_str());
    }
}

Commands::Commands(int game, QString up, QString left, QString right, QString down) {
    this->game = game;

    dict.insert(up, "Up");
    dict.insert(left, "Left");
    dict.insert(right, "Right");
    dict.insert(down, "Down");

}

bool Commands::validate(QString command) {
    if (game == TETRIS && dict.contains(command)) {
        Action action(game, dict.value(command));
        action.execute();
        return true;
    }
    else if (game == CHESS && command.split(" ").size() == 5) {
        Action action(game, command);
        action.execute();
        return true;
    }
    return false;
}

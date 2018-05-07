#include <QHash>
#include <QKeyEvent>
#include <QString>
#include <QTextStream>
#include <QSharedMemory>
#include <QBuffer>
#include <QDebug>

#include "action.h"

#ifndef COMMANDS_H
#define COMMANDS_H

#define TETRIS 0
#define CHESS 1

class Commands
{
public:
    Commands();
    Commands(int game, QString up, QString left, QString right, QString down);
    bool validate(QString command);

private:
    QHash <QString, QString> dict;
    int game;
    QSharedMemory *sharedMemory;
};

#endif // COMMANDS_H

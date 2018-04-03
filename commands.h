#include <QHash>
#include <QKeyEvent>
#include <QString>

#include "action.h"

#ifndef COMMANDS_H
#define COMMANDS_H


class Commands
{
public:
    Commands();
    bool contains(QString command);

private:
    QHash <QString, QString> dict;
};

#endif // COMMANDS_H

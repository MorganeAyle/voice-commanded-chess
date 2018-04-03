#include <QString>

#ifndef ACTION_H
#define ACTION_H


class Action
{
private:
    QString key;

public:
    Action();

    Action(QString key);

    void execute();
};

#endif // ACTION_H

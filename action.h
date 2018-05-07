#ifndef ACTION_H
#define ACTION_H

#include <QObject>

#include <QString>
#include <QStringList>
#include <QList>
#include <QHash>
#include <QSharedMemory>
#include <QBuffer>
#include <QDebug>

#include <stdio.h>
#include <stdlib.h>

#define TETRIS 0
#define CHESS 1

class Action : public QObject
{
    Q_OBJECT

private:
    QString key;
    int game;
    QHash <QString, int> map;


public:
    explicit Action(QObject *parent = NULL);

    Action(int game, QString key);

    void execute();

    QSharedMemory sharedMemory;

signals:

public slots:
};

#endif // ACTION_H

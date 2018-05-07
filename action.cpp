#include "action.h"

Action::Action(QObject *parent) : QObject(parent)
{

}

Action::Action(int game, QString key) {
    this->game = game;
    this->key = key;
    if (game == CHESS) {

        map.insert("one", 7);
        map.insert("two", 6);
        map.insert("three", 5);
        map.insert("four", 4);
        map.insert("five", 3);
        map.insert("six", 2);
        map.insert("seven", 1);
        map.insert("eight", 0);
        map.insert("a", 0);
        map.insert("b", 1);
        map.insert("c", 2);
        map.insert("d", 3);
        map.insert("e", 4);
        map.insert("f", 5);
        map.insert("g", 6);
        map.insert("h", 7);
    }
}


void Action::execute() {
    if (game == TETRIS) {
        QString string("xdotool key " + key);
        QByteArray string8bit = string.toLocal8Bit();
        const char* command = string8bit.data();
        system (command);
    }
    else if (game == CHESS) {
        QStringList list = key.split(" ");
        QStringList move;
        move.append(QString::number(map[list[0]]));
        move.append(QString::number(map[list[1]]));
        move.append(QString::number(map[list[3]]));
        move.append(QString::number(map[list[4]]));

        QString toSend = move.at(0) + "," + move.at(1) +","+ move.at(2) +","
                + move.at(3);

        QByteArray msg = toSend.toUtf8();

        sharedMemory.setKey("VoiceChess");

        if (!sharedMemory.attach()) {
                qDebug() << "Unable to attach mem seg";
                qDebug() << QString::fromUtf8(sharedMemory.errorString().toStdString().c_str());
                return;
            }

        QBuffer *buffer = new QBuffer;
        buffer->setBuffer(&msg);
        int size = buffer->size();

        sharedMemory.lock();
        char *to = (char*) (sharedMemory.data());
        const char *from = buffer->data().data();
        memcpy(to, from, qMin(sharedMemory.size(), size));
        sharedMemory.unlock();
    }
}


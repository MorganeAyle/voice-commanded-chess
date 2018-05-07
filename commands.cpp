#include "commands.h"

Commands::Commands()
{
    this->game = CHESS;

    sharedMemory = new QSharedMemory("blabla", NULL);
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

    int count = 0;
    QStringList list;
    QFile inputFile("/home/morgane/Desktop/cmusphinx/pocketsphinx/model/en-us/cmudict-en-us.dict");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          QString word = line.split(" ").at(0);
          if (dict.contains(word)) {
              list.append(line);
              count++;
              if (count == dict.size())
                  break;
          }
       }
       inputFile.close();
    }

    QFile file("/home/morgane/Desktop/cmusphinx/pocketsphinx/model/en-us/tetrisdict.dict");
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        for (int i = 0; i < list.size(); i++) {
            stream << list.at(i) << endl;
        }
    }
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

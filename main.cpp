#include "mainwindow.h"
#include <QApplication>

#include "speech.h"
#include "commands.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Commands allCommands;
    Speech speech;
    speech.start(allCommands);

    return a.exec();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tetrisButton_clicked()
{
    TetrisWindow *t = new TetrisWindow;
    t->show();

    this->close();
}

void MainWindow::on_chessButton_clicked()
{
    Thread2 thread;
    thread.program = "/home/morgane/Desktop/build-Chess-Desktop-Debug/build/Chess";
    thread.start();

    Commands allCommands;
    Speech speech;
    speech.start(CHESS, allCommands);
}

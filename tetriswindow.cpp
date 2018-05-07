#include "tetriswindow.h"
#include "ui_tetriswindow.h"

TetrisWindow::TetrisWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TetrisWindow)
{
    ui->setupUi(this);
}

TetrisWindow::~TetrisWindow()
{
    delete ui;
}

void TetrisWindow::on_pushButton_clicked()
{
    Thread2 thread;
    thread.program = "/home/morgane/Desktop/build-Tetris-Desktop-Debug/Tetris";
    thread.start();

    Commands allCommands(TETRIS, ui->upText->text().toLower(), ui->leftText->text().toLower(), ui->rightText->text().toLower(), ui->downText->text().toLower());
    Speech speech;
    speech.start(TETRIS, allCommands);
}

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
    ui->resultLabel->setText("");

    bool result = verifyCommands();
    if (result) {
        Thread2 thread;
        thread.program = "../build-Tetris/Tetris";
        thread.start();

        Commands allCommands(TETRIS, ui->upText->text().toLower(), ui->leftText->text().toLower(), ui->rightText->text().toLower(), ui->downText->text().toLower());
        Speech speech;
        speech.start(TETRIS, allCommands);
    }
    else
        ui->resultLabel->setText("One or more words are not valid");
}

bool TetrisWindow::verifyCommands() {
    int count = 0;
    QStringList words, phonetics;
    words.append(ui->upText->text().toLower());
    words.append(ui->leftText->text().toLower());
    words.append(ui->rightText->text().toLower());
    words.append(ui->downText->text().toLower());

    QFile inputFile("../cmusphinx/pocketsphinx/model/en-us/cmudict-en-us.dict");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          QString word = line.split(" ").at(0);
          if (words.contains(word)) {
              phonetics.append(line);
              count++;
              if (count == words.size())
                  break;
          }
       }
       inputFile.close();

       if (count != words.size()) // we didn't find a line in the dict corresponding to one of the words
           return false;
    }

    QFile file("../cmusphinx/pocketsphinx/model/en-us/tetrisdict.dict");
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        for (int i = 0; i < phonetics.size(); i++) {
            stream << phonetics.at(i) << endl;
        }
    }
    return true;
}

#ifndef TETRISWINDOW_H
#define TETRISWINDOW_H

#include <QWidget>

#include "thread2.h"
#include "speech.h"
#include "commands.h"

namespace Ui {
class TetrisWindow;
}

class TetrisWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TetrisWindow(QWidget *parent = 0);
    ~TetrisWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TetrisWindow *ui;
};

#endif // TETRISWINDOW_H

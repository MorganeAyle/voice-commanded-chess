#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tetriswindow.h"
#include "chesswindow.h"
#include "action.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_tetrisButton_clicked();
    
    void on_chessButton_clicked();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

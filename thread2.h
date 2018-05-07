#ifndef THREAD2_H
#define THREAD2_H

#include <QThread>
#include <QProcess>

class Thread2 : public QThread
{
    Q_OBJECT

public:
    QString program;

private:
    void run() {
        QProcess process;
        process.execute(program);
    }

};

#endif // THREAD2_H

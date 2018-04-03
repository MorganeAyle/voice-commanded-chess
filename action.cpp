#include "action.h"

Action::Action()
{

}

Action::Action(QString key) {
    this->key = key;
}

void Action::execute() {
    QString command("xdotool key " + key);
    QByteArray array = command.toLocal8Bit();
    const char* buffer = array.data();
    system (buffer);
}

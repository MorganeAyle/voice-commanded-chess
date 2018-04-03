#include "commands.h"

Commands::Commands()
{
    dict.insert("left", "Left");
    dict.insert("right", "Right");
    dict.insert("up", "Up");
    dict.insert("down", "Down");
}

bool Commands::contains(QString command) {
    if (dict.contains(command)) {
        Action action(dict.value(command));
        action.execute();
        return true;
    }
    return false;
}

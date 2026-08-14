#ifndef CORE_H
#define CORE_H

#include <QObject>
#include "corelogic.h"
#include "room.h"

class Core : public QObject
{
    Q_OBJECT

public:
    explicit Core(QObject *parent = nullptr);
    ~Core();

    void start();
    CoreLogic* getLogic();

private:
    CoreLogic* logic;
    room* currentRoom;
};

#endif // CORE_H
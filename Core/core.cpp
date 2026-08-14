#include "core.h"

Core::Core(QObject *parent)
    : QObject(parent)
{
    logic = new CoreLogic(this);

    RoomData data;
    data.id = 1;
    data.name = "Первая комната";
    currentRoom = new room(data);

    logic->setRoom(currentRoom);
}

Core::~Core() {}

void Core::start()
{
    // Инициализация ядра
    logic->init();
}

CoreLogic* Core::getLogic()
{
    return logic;
}
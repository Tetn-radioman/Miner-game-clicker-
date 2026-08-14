#include <QApplication>
#include "visual.h"
#include "core.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Создаем ядро
    Core core;

    // Создаем визуал
    Visual visual;
    visual.setLogic(core.getLogic());

    // Запускаем ядро
    core.start();

    // Показываем визуал
    visual.show();

    return app.exec();
}
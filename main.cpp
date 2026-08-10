#include <QApplication>
#include "visual.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Visual window;
    window.show();

    return app.exec();
}
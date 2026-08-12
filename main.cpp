#include <QApplication>
#include "visual.h"

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Visual window;
    window.show();


    return app.exec();
}
#include "visual.h"


Visual::Visual(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
}

Visual::~Visual() {}

void Visual::setupUI()
{
    // Создаём центральный виджет
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Создаём вертикальный слой (VBoxL)
    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    setupMiddle();

}

void Visual::setupTop(){


}

void Visual::setupBottom(){


}

void Visual::setupMiddle(){

    middleLayout = new QVBoxLayout();
    for (int i = 0; i < 2; ++i) {
        QHBoxLayout *HBoxLayout = new QHBoxLayout();
        for (int j = 0; j < 4; ++j) {

            QPushButton *Btn = new QPushButton(this);


            QPixmap pixmap("textures/pc/1.png");
            QPixmap scaledPixmap = pixmap.scaled(64, 64, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            QIcon icon(scaledPixmap);
            Btn->setIcon(icon);
            Btn->setIconSize(QSize(64, 64));
            Btn->setFixedSize(64, 64);
            Btn->setStyleSheet(
                "QPushButton {"
                "   border: 2px solid gray;"
                "   border-radius: 5px;"
                "   color: white;"
                "   font-weight: bold;"
                "   font-size: 16px;"
                "}"
                "QPushButton:hover {"
                "   border: 2px solid black;"
                "}"
                );


            int index;
            if (i == 1) index = 4 + j; else index = j;

            //Btn->setText(QString("Btn №%1").arg(index));
            Btn->setProperty("index",index);
            HBoxLayout->addWidget(Btn);

        }

        middleLayout->addLayout(HBoxLayout);

    }

    mainLayout->addLayout(middleLayout);

}
#include "visual.h"

Visual::Visual(QWidget *parent)
    : QMainWindow(parent)
    , logic(nullptr)
{
    setupUI();
}

Visual::~Visual() {}

void Visual::setLogic(CoreLogic* logic)
{
    this->logic = logic;

    // Подключаем сигналы от логики
    connect(logic, &CoreLogic::cellUpdated, this, &Visual::updateCell);

    // Загружаем начальное состояние
    for (int i = 0; i < 8; ++i) {
        if (cellButtons[i]) {
            CellData cell = logic->getCellData(i);
            updateCellTexture(i, cell);
        }
    }
}

void Visual::updateCell(int index)
{
    if (index >= 0 && index < 8 && logic) {
        CellData cell = logic->getCellData(index);
        updateCellTexture(index, cell);
    }
}

void Visual::updateCellTexture(int index, const CellData& cell)
{
    if (index >= 0 && index < 8 && cellButtons[index]) {
        QPixmap pixmap(cell.texturePath);
        QPixmap scaledPixmap = pixmap.scaled(64, 64, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        QIcon icon(scaledPixmap);
        cellButtons[index]->setIcon(icon);
        cellButtons[index]->setProperty("cellIndex", index);
    }
}

void Visual::setupUI()
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    setupTop();
    setupMiddle();
    setupBottom();
}

void Visual::setupTop()
{
    topLayout = new QHBoxLayout();

    QPushButton *Btn = new QPushButton(this);
    Btn->setText("Настройки");
    topLayout->addWidget(Btn);

    mainLayout->addLayout(topLayout);
}

void Visual::setupBottom()
{
    bottomLayout = new QHBoxLayout();

    QPushButton *Btn = new QPushButton(this);
    Btn->setText("купить помещение");
    bottomLayout->addWidget(Btn);

    QComboBox *CBox = new QComboBox(this);
    CBox->addItem("Первая комната");
    CBox->addItem("Вторая комната");
    bottomLayout->addWidget(CBox);

    mainLayout->addLayout(bottomLayout);
}

void Visual::setupMiddle()
{
    middleLayout = new QVBoxLayout();

    for (int i = 0; i < 2; ++i) {
        QHBoxLayout *HBoxLayout = new QHBoxLayout();
        for (int j = 0; j < 4; ++j) {
            QPushButton *Btn = new QPushButton(this);

            int index;
            if (i == 1) index = 4 + j; else index = j;

            QPixmap pixmap("textures/empty.png");
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

            Btn->setProperty("cellIndex", index);
            cellButtons[index] = Btn;

            connect(Btn, &QPushButton::clicked, this, [this, index]() {
                miniBar(index);
            });

            HBoxLayout->addWidget(Btn);
        }
        middleLayout->addLayout(HBoxLayout);
    }

    mainLayout->addLayout(middleLayout);
}

void Visual::miniBar(int index)
{
    qDebug() << "miniBar вызван! btn - " << index;

    // Запрос к логике для проверки возможности апгрейда
    if (logic) {
        if (logic->canUpgradeCell(index)) {
            // Можно апгрейдить
            qDebug() << "Cell" << index << "can be upgraded";
            // Здесь открыть мини-бар для выбора действия
        } else {
            qDebug() << "Cell" << index << "is empty or cannot be upgraded";
            // Здесь предложить купить оборудование
        }
    }
}
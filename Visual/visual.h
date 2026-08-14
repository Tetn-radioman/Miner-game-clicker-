#ifndef VISUAL_H
#define VISUAL_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>
#include "corelogic.h"

class Visual : public QMainWindow
{
    Q_OBJECT

public:
    Visual(QWidget *parent = nullptr);
    ~Visual();

    void setLogic(CoreLogic* logic);
    void updateCell(int index);

public slots:
    void miniBar(int index);

private:
    void setupUI();
    void setupTop();
    void setupMiddle();
    void setupBottom();
    void updateCellTexture(int index, const CellData& cell);

    QWidget* centralWidget;
    QVBoxLayout* mainLayout;
    QHBoxLayout* topLayout;
    QHBoxLayout* bottomLayout;
    QVBoxLayout* middleLayout;
    std::array<QPushButton*, 8> cellButtons;
    CoreLogic* logic;
};

#endif // VISUAL_H
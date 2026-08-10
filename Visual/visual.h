#ifndef VISUAL_H
#define VISUAL_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QVector>
#include <QPushButton>

class Visual : public QMainWindow
{
    Q_OBJECT

public:
    Visual(QWidget *parent = nullptr);
    ~Visual();

private:
    void setupUI();  // Только создание виджетов и layout'ов
    void setupMiddle();

    // Базовые элементы (пустые, без логики)
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;  // Вот твой VBoxL
    QVBoxLayout *middleLayout;

    //QVector<QHBoxLayout*> HBoxL;
    //QVector<QPushButton*> buttons; // Вектор указателей на кнопки
};

#endif // VISUAL_H
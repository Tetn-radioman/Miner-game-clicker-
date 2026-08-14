#ifndef CORELOGIC_H
#define CORELOGIC_H

#include <QObject>
#include "room.h"

class CoreLogic : public QObject
{
    Q_OBJECT

public:
    explicit CoreLogic(QObject *parent = nullptr);
    ~CoreLogic();

    void setRoom(room* room);
    void init();

    bool canUpgradeCell(int cellIndex);
    bool canBuyEquipment(int cellIndex, EquipmentType type);
    void upgradeCell(int cellIndex);
    void buyEquipment(int cellIndex, EquipmentType type);
    CellData getCellData(int cellIndex);

signals:
    void cellUpdated(int cellIndex);
    void roomUpdated();

private:
    room* currentRoom;
};

#endif // CORELOGIC_H
#include "corelogic.h"
#include <QDebug>

CoreLogic::CoreLogic(QObject *parent)
    : QObject(parent)
    , currentRoom(nullptr)
{
}

CoreLogic::~CoreLogic() {}

void CoreLogic::setRoom(room* room)
{
    currentRoom = room;
}

void CoreLogic::init()
{
    if (currentRoom) {
        // Инициализация начальных данных
        qDebug() << "CoreLogic initialized with room:" << currentRoom->getID();
        emit roomUpdated();
    }
}

bool CoreLogic::canUpgradeCell(int cellIndex)
{
    if (!currentRoom) return false;
    CellData cell = currentRoom->getCellData(cellIndex);
    return cell.type != EquipmentType::Empty;
}

bool CoreLogic::canBuyEquipment(int cellIndex, EquipmentType type)
{
    if (!currentRoom) return false;
    CellData cell = currentRoom->getCellData(cellIndex);
    return cell.type == EquipmentType::Empty && type != EquipmentType::Empty;
}

void CoreLogic::upgradeCell(int cellIndex)
{
    if (!currentRoom || !canUpgradeCell(cellIndex)) return;

    CellData cell = currentRoom->getCellData(cellIndex);
    // Повышаем уровень
    switch (cell.level) {
    case EquipmentLevel::Level1:
        cell.level = EquipmentLevel::Level2;
        break;
    case EquipmentLevel::Level2:
        cell.level = EquipmentLevel::Level3;
        break;
    case EquipmentLevel::Level3:
        return; // Максимальный уровень
    }

    // Обновляем путь к текстуре
    QString typeStr;
    switch (cell.type) {
    case EquipmentType::PC: typeStr = "pc"; break;
    case EquipmentType::Server: typeStr = "server"; break;
    case EquipmentType::ASIC: typeStr = "miner"; break;
    default: return;
    }

    int levelNum = static_cast<int>(cell.level) + 1;
    cell.texturePath = QString("textures/%1/%2.png").arg(typeStr).arg(levelNum);

    emit cellUpdated(cellIndex);
}

void CoreLogic::buyEquipment(int cellIndex, EquipmentType type)
{
    if (!currentRoom || !canBuyEquipment(cellIndex, type)) return;

    CellData cell = currentRoom->getCellData(cellIndex);
    cell.type = type;
    cell.level = EquipmentLevel::Level1;

    QString typeStr;
    switch (type) {
    case EquipmentType::PC: typeStr = "pc"; break;
    case EquipmentType::Server: typeStr = "server"; break;
    case EquipmentType::ASIC: typeStr = "miner"; break;
    default: return;
    }

    cell.texturePath = QString("textures/%1/1.png").arg(typeStr);

    emit cellUpdated(cellIndex);
}

CellData CoreLogic::getCellData(int cellIndex)
{
    if (!currentRoom) return CellData();
    return currentRoom->getCellData(cellIndex);
}
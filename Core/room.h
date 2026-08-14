#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <array>

enum class EquipmentType { Empty, PC, Server, ASIC };
enum class EquipmentLevel { Level1, Level2, Level3 };

struct CellData {
    EquipmentType type = EquipmentType::Empty;
    EquipmentLevel level = EquipmentLevel::Level1;
    double income = 0.0;
    QString texturePath = "textures/empty.png";
};

struct RoomData {
    int id = 0;
    QString name = "Комната 1";
    double electricityCost = 0.78;
    std::array<CellData, 8> cells; // 8 ячеек
};

class room
{
public:
    room(RoomData Data);

    int getID();
    CellData getCellData(int CellID);
    void setCellData(int CellID, const CellData& data);

private:
    RoomData data;
};

#endif // ROOM_H
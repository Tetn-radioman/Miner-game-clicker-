#include "room.h"

room::room(RoomData Data)
    : data(Data)
{
}

int room::getID()
{
    return data.id;
}

CellData room::getCellData(int CellID)
{
    if (CellID >= 0 && CellID < static_cast<int>(data.cells.size())) {
        return data.cells[CellID];
    }
    return CellData();
}

void room::setCellData(int CellID, const CellData& cellData)
{
    if (CellID >= 0 && CellID < static_cast<int>(data.cells.size())) {
        data.cells[CellID] = cellData;
    }
}
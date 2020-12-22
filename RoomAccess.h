#pragma once
#include "Room.h"
#include "DatabaseAccess.h"
class RoomAccess : public DatabaseAccess
{
public:
    void Select(Room*&);
    int Count();
    bool Insert();
    int Search(int); // search theo id_number
    bool Update(int);
    bool Delete();
    void Show();
    Room getRoom(int);
    int LastID();
};




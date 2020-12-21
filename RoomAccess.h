#pragma once
#include "Room.h"
#include "DatabaseAccess.h"
class RoomAccess : public DatabaseAccess
{
    public:
        void Select(Room*&);
        int Count();
        bool Insert();
        //int SearchID(int); // search theo id_number
        int SearchName(char*); // search teo ten phong
        bool Update();
        bool Delete();
        void Show();
};


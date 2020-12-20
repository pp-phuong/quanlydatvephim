#pragma once
#include "SeatType.h"
#include "DatabaseAccess.h"
class SeatTypeAccess :
    public DatabaseAccess
{
public:
    void Select(SeatType*&);
    int Count();
    bool Insert();
    int Search(int); // search theo id_number
    bool Update();
    bool Delete();
    void Show();
};

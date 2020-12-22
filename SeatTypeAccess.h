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
    bool Insert(SeatType);
    int Search(int); // search theo id_number
    bool Update(int, int);
    bool Delete();
    void Show();
    SeatType getSeatType(int);
    int LastID();
};

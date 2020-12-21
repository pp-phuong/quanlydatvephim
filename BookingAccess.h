#pragma once
#include "Booking.h"
#include "DatabaseAccess.h"
class BookingAccess : public DatabaseAccess
{
public:
    void Select(Booking *&);
    int Count();
    bool Insert();
    int Search(int);
    bool Update();
    bool Delete();
    void Show();
};


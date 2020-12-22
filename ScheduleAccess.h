#pragma once
#include "Schedule.h"
#include "Date.h"
#include "DatabaseAccess.h"
class ScheduleAccess : public DatabaseAccess
{
	public:
        void Select(Schedule*&, int, int);
        int Count(int);
        bool Insert();
        int Search(int, int); // search theo id_number
        bool Update(int,int);
        bool Delete();
        void Show();
        Schedule getSchedule(int);
        int LastID();
};




#pragma once
#include <iostream>
using namespace std;
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
#include "MovieAccess.h"
class Schedule
{
private:
	int schedule_id;
	int movie_id;
	int room_id;
	char schedule_date[20];
	char schedule_start[20];
	char schedule_end[20];
public:
	Schedule();
	Schedule(char*, char*, char*, int = 0, int = 0, int = 0);
	~Schedule();
	int getScheduleID();
	char* getSDate();
	char* getStart();
	char* getEnd();
	int getMovieID();
	string insertQuery();
	void setSchedule();
	int getRoomID();
	void Show(MovieAccess);
};


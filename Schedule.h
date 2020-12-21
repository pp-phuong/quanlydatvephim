#pragma once
#include <iostream>
using namespace std;
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
class Schedule
{
private:
	int schedule_id;
	int movie_id;
	int room_id;
	char schedule_date[15];
	char schedule_start[15];
	char schedule_end[15];
public:
	Schedule();
	Schedule(char*, char*, char*, int = 0, int = 0, int = 0);
	~Schedule();
	int getScheduleID();
	char* getSDate();
	char* getStart();
	char* getEnd();
	string insertQuery();
	void Show();
};


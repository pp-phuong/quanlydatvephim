#pragma once
#include <iostream>
using namespace std;
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
class Seat
{
	private:
		int seat_id;
		int seatType_id;
		int room_id;
		char seat_row[5];
		char seat_number[5];
		int seat_status;
	public:
		Seat();
		Seat(char*, char*, int=0, int = 0, int = 0, int = 0);
		~Seat();
		int getSeatID();
		int getStatus();
		string insertQuery();
		void Show();
};

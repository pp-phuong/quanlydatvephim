#pragma once
#include <iostream>
using namespace std;
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
#include "ScheduleAccess.h"
#include "MovieAccess.h"
#include "SeatAccess.h"
class Booking
{
private:
	int booking_id;
	int account_id;
	int schedule_id;
	int seat_id;
public:
	Booking(int = 0, int = 0, int = 0, int = 0);
	~Booking();
	int getBookingID();
	int getAccountID();
	int getScheduleID();
	int getSeatID();
	void setBooking(int,int,int);
	string insertQuery();
	void Show();
};


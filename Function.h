#pragma once
#include "Account.h"
#include "Movie.h"
#include "Room.h"
#include "Seat.h"
#include "SeatType.h"
#include "Booking.h"
#include "Schedule.h"
#include "AccountAccess.h"
#include "MovieAccess.h"
#include "RoomAccess.h"
#include "SeatAccess.h"
#include "SeatTypeAccess.h"
#include "BookingAccess.h"
//#include "ScheduleAccess.h"
#include <string>
#include <conio.h>
#include <windows.h>

class Function
{
	int search;
	AccountAccess acc;
	MovieAccess mv;
	RoomAccess room;
	SeatAccess seat;
	SeatTypeAccess seat_type;
	BookingAccess booking;
	Account account;
	Account user;
	Account user_now;
public:
	Function();
	void Menu();
	void MenuTodayMovie();
	void MenuMovieShowing();
	void MenuMovieComing();
	void MenuSearchMovie();
	void MenuSchedule();
	void MenuBooking();
	void MenuAdmin();
	void MenuAdAccount();
	void MenuAdRoom();
	void MenuAdSeat();
	void MenuUpdateSeat(int);
	void MenuAdMovie();
	void MenuUpdateMovie(int);
	void MenuAdSeatType();
	void MenuAdBooking();
	void MenuAdSchedule();
	void Authentication();
	void Validate();
	Account getUserNow();
	~Function();
};


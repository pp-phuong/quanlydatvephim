#pragma once
#include "AccountAccess.h"
#include "Account.h"
#include "Movie.h"
#include "MovieAccess.h"
#include <string>
#include <conio.h>
#include <windows.h>

class Function
{
	int search;
	AccountAccess acc;
	MovieAccess mv;
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


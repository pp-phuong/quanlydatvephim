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
	int id_user;
public:
	Function();
	void setUserNow(int);
	void Menu();
	void Authentication();
	void Validate();
	~Function();
};


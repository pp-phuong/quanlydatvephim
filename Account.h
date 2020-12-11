#pragma once
#include <iostream>
using namespace std;
#include <string.h>
#include "AccountAccess.h"
class Account
{
private:
	int ID_number;
	char fullname[32];
	char username[32];
	char pwd[32];
	char email[32];
	char phone_number[50];

public:
	Account();
	Account(int,char*, char*, char*, char*, char*);
	~Account();
	int getID();
	char* getUsername();
	char* getPwd();
	void setAccount();
	string insertQuery();
};

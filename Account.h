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
	int role;

public:
	Account();
	Account(int,char*, char*, char*, char*, char*, int);
	~Account();
	int getID();
	char* getFullname();
	char* getUsername();
	string getStrUsername();
	char* getPwd();
	char* getEmail();
	char* getPhone();
	int getRole();
	void setAccount();
};

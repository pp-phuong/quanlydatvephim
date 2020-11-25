#include "Account.h"
#include <iomanip>
#include <windows.h>
#include <conio.h>

Account::Account()
{
	strcpy_s(fullname, "");
	strcpy_s(username, "");
	strcpy_s(pwd, "");
	strcpy_s(email, "");
	strcpy_s(phone, "");
}
Account::Account(int ID,char* fullname, char* username, char* pwd, char* email, char* phone)
    :ID_number(ID)
{
	strcpy_s(this->fullname,30, fullname);
	strcpy_s(this->username,30, username);
	strcpy_s(this->pwd,30, pwd);
	strcpy_s(this->email,30, email);
	strcpy_s(this->phone,11, phone);
}
Account::~Account()
{
}


int Account::getID()
{
    return this->ID_number;
}
char* Account::getUsername()
{
    return this->username;
}
char* Account::getPwd()
{
    return this->pwd;
}

#include <iostream>
using namespace std;
#include <string.h>
class Account
{
private:
	int ID_number;
	char fullname[30];
	char username[30];
	char pwd[30];
	char email[30];
	char phone[11];

public:
	Account();
	Account(int,char*, char*, char*, char*, char*);
	~Account();
	int getID();
	char* getUsername();
	char* getPwd();
};

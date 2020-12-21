#pragma once
#include <iostream>
using namespace std;
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
class Room
{
	private:
		int room_id;
		char room_name[5];
	public:
		Room();
		Room(char*, int=0);
		~Room();
		int getRoomID();
		char* getRoomName();
		string insertQuery();
		void Show();
};


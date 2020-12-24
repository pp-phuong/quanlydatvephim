#include "Room.h"

Room::Room()
{}

Room::Room(char* roomName, int roomID)
{
	this->room_id = roomID;
	strcpy_s(this->room_name, 5, roomName);
}

Room::~Room()
{}

int Room::getRoomID()
{
	return this->room_id;
}

char* Room::getRoomName()
{
	return this->room_name;
}

string Room::insertQuery()
{
	string t_query;
	string t_room_name(room_name);
	t_query = t_room_name + "')";
	return t_query;
}

void Room::Show()
{
	cout << "\t\t\t\t\t\t\t\tRoom name: " << this->room_name << endl << endl;
}

void Room::setRoom()
{
	cin.ignore();
	cout << "\t\t\t\t\t\t\t\tRoom name: ";
	cin.getline(this->room_name, 5);
}







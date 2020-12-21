#include "Room.h"

Room::Room()
{
	this->room_id = 0;
	strcpy_s(room_name, 5, "");
}

Room::Room(char* roonName, int roomID)
{
	this->room_id = roomID;
	strcpy_s(this->room_name, 5, roonName);
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
	string t_room_id = to_string(room_id);
	string t_room_name(room_name);
	t_query = t_room_id + "','" + t_room_name + "')";
	return t_query;
}

void Show()
{}








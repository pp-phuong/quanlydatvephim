#include "Schedule.h"

Schedule::Schedule()
{}

Schedule::Schedule(char* date, char* start, char* end, int scheduleID, int movieID, int roomID)
	:schedule_id(scheduleID), movie_id(movieID), room_id(roomID)
{
	strcpy_s(this->schedule_date, 15, date);
	strcpy_s(this->schedule_start, 15, start);
	strcpy_s(this->schedule_end, 15, end);
}

Schedule::~Schedule()
{}

int Schedule::getScheduleID()
{
	return this->schedule_id;
}

char* Schedule::getSDate()
{
	return this->schedule_date;
}

char* Schedule::getStart()
{
	return this->schedule_start;
}

char* Schedule::getEnd()
{
	return this->schedule_end;
}

string Schedule::insertQuery()
{
	string t_query;
	string t_schedule_id = to_string(this->schedule_id);
	string t_movie_id = to_string(this->movie_id);
	string t_room_id = to_string(this->room_id);
	string t_schedule_date(this->schedule_date);
	string t_schedule_start(this->schedule_start);
	string t_schedule_end(this->schedule_end);
	t_query = t_schedule_id + "','" + t_movie_id + "','" + t_room_id + "','" + t_schedule_date + "','" + t_schedule_start + "','" + t_schedule_end + "')";
	return t_query;
}

void Schedule::Show()
{
	cout << left << setw(5) << this->schedule_id;
	RoomAccess room;
	Room* ptr = new Room[room.Count()];
	room.Select(ptr);
	MovieAccess mv;
	Movie* ptr_mv = new Movie[mv.CountRow(1)];
	mv.Select(ptr_mv, 1);
	cout << left << setw(5) << ptr_mv[mv.Search(this->movie_id)].getMovieName();
	cout << left << setw(5) << ptr[room.Search(this->room_id)].getRoomName();
	cout << left << setw(18) << this->schedule_date;
	cout << left << setw(18) << this->schedule_start;
	cout << right << setw(18) << this->schedule_end << endl;
}

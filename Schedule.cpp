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
	cout << left << setw(15) << this->schedule_id;
	cout << left << setw(15) << this->movie_id;
	cout << left << setw(15) << this->room_id;
	cout << left << setw(15) << this->schedule_date;
	cout << left << setw(15) << this->schedule_start;
	cout << left << setw(15) << this->schedule_end << endl;
}

void Schedule::setSchedule()
{
	cout << "Movie ID : ";
	cin >> this->movie_id;
	cout << "Room ID: ";
	cin >> this->room_id;
	cout << "Schedule date (yyyy-mm-dd): ";
	cin.ignore();
	cin.getline(this->schedule_date, 15);
	cout << "Schedule start (hh:mm:ss): ";
	cin.ignore();
	cin.getline(this->schedule_start, 15);
	cout << "Schedule end (hh:mm:ss): ";
	cin.ignore();
	cin.getline(this->schedule_end, 15);
}


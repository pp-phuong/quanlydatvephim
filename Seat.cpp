#include "Seat.h"

Seat::Seat()
{
	this->seat_id = 0;
	this->seatType_id = 0;
	this->room_id = 0;
	strcpy_s(this->seat_row, 5, "");
	strcpy_s(this->seat_number, 5, "");
	this->seat_status = 0;
}

Seat::Seat(char* row, char* number, int ID, int seatTypeID, int roomID, int status)
	:seat_id(ID), seatType_id(seatTypeID), room_id(roomID), seat_status(status)
{
	strcpy_s(this->seat_row, 5, row);
	strcpy_s(this->seat_number, 5, number);
}

Seat::~Seat()
{}

int Seat::getSeatID()
{
	return this->seat_id;
}

int Seat::getStatus()
{
	return this->seat_status;
}

string Seat::insertQuery()
{
	string t_query;
	string t_seat_id = to_string(seat_id);
	string t_seatType_id = to_string(seatType_id);
	string t_room_id = to_string(room_id);
	string t_seatStatus = to_string(seat_status);
	string t_seat_row(seat_row);
	string t_seat_number(seat_number);
	t_query = t_seat_id + "','" + t_seatType_id + "','" + t_room_id + "','" + t_seat_row + "','" + t_seat_number + "','" + t_seatStatus + "')";
	return t_query;
}

void Seat::Show()
{
	cout << left << setw(4) << this->seat_id;
	cout << left << setw(4) << this->seatType_id;
	cout << left << setw(4) << this->room_id;
	cout << left << setw(4) << this->seat_row;
	cout << left << setw(4) << this->seat_number;
	cout << right << setw(4) << this->seat_status << endl;
}


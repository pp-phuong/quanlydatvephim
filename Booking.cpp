#include "Booking.h"

Booking::Booking(int bookingID, int accountID, int scheduleID, int seatID)
{
	this->booking_id = bookingID;
	this->account_id = accountID;
	this->schedule_id = scheduleID;
	this->seat_id = seatID;
}

Booking::~Booking()
{}

int Booking::getBookingID()
{
	return this->booking_id;
}

int Booking::getAccountID()
{
	return this->account_id;
}

int Booking::getScheduleID()
{
	return this->schedule_id;
}

int Booking::getSeatID()
{
	return this->seat_id;
}

string Booking::insertQuery()
{
	string t_query;
	string t_booking_id = to_string(this->booking_id);
	string t_account_id = to_string(this->account_id);
	string t_schedule_id = to_string(this->schedule_id);
	string t_seat_id = to_string(this->seat_id);
	t_query = t_booking_id + "','" + t_account_id + "','" + t_schedule_id + "','" + t_seat_id + "')";
	return t_query;
}

void Booking::Show()
{}



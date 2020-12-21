#include "BookingAccess.h"
#include <iomanip>

void BookingAccess::Select(Booking*& bk)
{
	int i = 0;
	string c_query;
	c_query = "select * from booking";
	const char* q = c_query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		int booking_id;
		int account_id;
		int schedule_id;
		int seat_id;
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_INTEGER, &booking_id, sizeof(booking_id), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_INTEGER, &account_id, sizeof(account_id), NULL);
			SQLGetData(SQLStateHandle, 3, SQL_INTEGER, &schedule_id, sizeof(schedule_id), NULL);
			SQLGetData(SQLStateHandle, 4, SQL_INTEGER, &seat_id, sizeof(seat_id), NULL);
			Booking* temp = new Booking(booking_id, account_id, schedule_id, seat_id);
			*(bk + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int BookingAccess::Count()
{
	int i = 0;
	string c_query;
	c_query = "select * from booking";
	const char* q = c_query.c_str();
	cout << q;
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!" << endl;
		Close();
	}
	else
	{
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
	return i;
}

int BookingAccess::Search(int account_id)
{
	Booking* ptr = new Booking[this->Count()];
	this->Select(ptr);
	for (int i = 0; i < this->Count(); i++)
	{
		if (ptr[i].getAccountID() == account_id) return i;
	}
	return -1;
}

void BookingAccess::Show()
{
	string c_query = "select booking.ID_number, movie_name, room_name, seat_row, seat_number, schedule_date, schedule_start, schedule_end, seat_price from booking inner join schedule on booking.schedule_id = schedule.schedule_id inner join room on schedule.room_id = room.room_id inner join movie on schedule.movie_id = movie.movie_id inner join account on booking.ID_number = account.ID_number inner join seat on booking.seat_id = seat.seat_id ";
	const char* q = c_query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		cout << "Hoa don dat ve xem phim" << endl;
	}
	SQLCancel(SQLStateHandle);
}

bool BookingAccess::Update()
{
	return 0;
}

bool BookingAccess::Delete()
{
	return 0;
}

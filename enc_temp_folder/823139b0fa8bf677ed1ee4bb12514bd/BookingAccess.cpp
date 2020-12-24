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
	Booking* ptr = new Booking[this->Count()];
	this->Select(ptr);

	for (int i = 0; i < this->Count(); i++)
	{
		cout << i + 1 << ".";
		ptr[i].Show();
	}
	if (this->Count() == 0)
	{
		cout << endl << "Sorry,no seat type founded!" << endl;
	}
}

bool BookingAccess::Update()
{
	return 0;
}
bool BookingAccess::Insert(Booking &booking)
{
	string c_query = "insert into booking values ('";
	int id = this->LastID() + 1;
	c_query += to_string(id) + "','";
	c_query += booking.insertQuery();
	const char* q = c_query.c_str();
	SeatAccess seat;
	seat.Init();
	cout << q;
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		seat.Update(booking.getSeatID(), 4, 0); seat.Close();
		cout << "Dat ve  thanh cong !" << endl;

		Booking* ptr = new Booking[this->Count()];
		this->Select(ptr);
		ptr[this->Search(id)].Show();
		return true;
	}
	SQLCancel(SQLStateHandle);
	return 1;
}
int BookingAccess::LastID()
{
	if (this->Count() == 0) return 0;
	else {
		Booking* ptr = new Booking[this->Count()];
		this->Select(ptr);
		return ptr[this->Count() - 1].getBookingID();
	}
}
bool BookingAccess::Delete()
{
	return 0;
}

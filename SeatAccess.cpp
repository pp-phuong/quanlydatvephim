#include "SeatAccess.h"
#include <iomanip>

void SeatAccess::Select(Seat*& seat)
{
	int i = 0;
	string c_query;
	c_query = "select * from seat";
	const char* q = c_query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		int seat_id;
		int seatType_id;
		int room_id;
		char seat_row[5];
		char seat_number[5];
		int seat_status;
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_INTEGER, &seat_id, sizeof(seat_id), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_INTEGER, &seatType_id, sizeof(seatType_id), NULL);
			SQLGetData(SQLStateHandle, 3, SQL_INTEGER, &room_id, sizeof(room_id), NULL);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, seat_row, sizeof(seat_row), NULL);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, seat_number, sizeof(seat_number), NULL);
			SQLGetData(SQLStateHandle, 6, SQL_INTEGER, &seat_status, sizeof(seat_status), NULL);

			Seat* temp = new Seat(seat_id, seatType_id, room_id, seat_row, seat_number, seat_status);
			*(seat + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

void SeatAccess::Show()
{
}

int SeatAccess::Count(int choice, int roomID)
{
	// 1: đếm hàng
	// 2: đếm cột
	int i = 0;
	string c_query;
	switch (choice)
	{
	case 1:
		c_query = "select distinct seat_row from seat where room_id = " + roomID;
		break;
	case 2:
		c_query = "select distinct seat_number from seat where room_id = " + roomID;
		break;
	}
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

bool SeatAccess::Insert()
{
}

bool SeatAccess::Update()
{}

bool SeatAccess::Delete()
{}


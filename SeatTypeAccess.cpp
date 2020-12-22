#include "SeatTypeAccess.h"
#include <iomanip>

void SeatTypeAccess::Select(SeatType*& seatType)
{
	int i = 0;
	string c_query;
	c_query = "select * from seatType";
	const char* q = c_query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		int seat_type_id;
		char seat_type[15];
		int seat_price;
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_INTEGER, &seat_type_id, sizeof(seat_type_id), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, seat_type, sizeof(seat_type), NULL);
			SQLGetData(SQLStateHandle, 3, SQL_INTEGER, &seat_price, sizeof(seat_price), NULL);
			SeatType* temp = new SeatType(seat_type, seat_type_id, seat_price);
			*(seatType + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int SeatTypeAccess::Count()
{
	int i = 0;
	string c_query;
	c_query = "select * from seatType";
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

bool SeatTypeAccess::Insert()
{
	return 0;
}

bool SeatTypeAccess::Update()
{
	return 0;
}

bool SeatTypeAccess::Delete()
{
	return 0;
}

void SeatTypeAccess::Show()
{}

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
	string c_query= "insert into seatType values ('";
	string seat_type_id = to_string(this->LastID() + 1);
	c_query += seat_type_id + "','";
	SeatType seat_type;
	seat_type.setSeatType();
	c_query +=  seat_type.insertQuery();
	const char* q = c_query.c_str();
	cout << q;
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!" << endl;
		Close();
	}
	else
	{
		cout << "Them seat type thanh cong !";
	}
	SQLCancel(SQLStateHandle);
	return 1;
}
int SeatTypeAccess::LastID() {
	SeatType* ptr = new SeatType[this->Count()];
	this->Select(ptr);
	return ptr[this->Count() - 1].getSeatTypeID();
}
bool SeatTypeAccess::Update(int choice, int id)
{

	//1. seat Type name;
	//2. seat type price;
	string c_query = "update seatType set";
	string seat_type;
	int seat_price;
	switch (choice)
	{
	case 1:
		cout << "Seat Type : ";
		cin.ignore();
		getline(cin, seat_type);
		c_query += " seat_type = '" + seat_type;
		break;
	case 2:
		cout << "Seat Price : ";
		cin >> seat_price;
		c_query += " seat_price = '" + to_string(seat_price);
		break;
	}
	c_query += "'where seat_type_id = '" + to_string(id) + "'";
	const char* q = c_query.c_str();
	cout << q;
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << endl << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		cout << endl << "Them du lieu thanh cong !" << endl;
		return true;
	}
	SQLCancel(SQLStateHandle);
	return true;
}

bool SeatTypeAccess::Delete()
{
	return 0;
}

void SeatTypeAccess::Show()
{
	SeatType* ptr = new SeatType[this->Count()];
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
SeatType SeatTypeAccess::getSeatType(int index)
{
	SeatType* ptr = new SeatType[this->Count()];
	this->Select(ptr);
	cout << "seat type:"; ptr[index].Show(); cout << endl;
	cout <<"id:"<< ptr[index].getSeatTypeID();
	return ptr[index];
}
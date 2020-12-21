#include "RoomAccess.h"
#include  <iomanip>

void RoomAccess::Select(Room*& room)
{
	int i = 0;
	string c_query;
	c_query = "select * from room";
	const char* q = c_query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		int room_id;
		char room_name[5];
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_INTEGER, &room_id, sizeof(room_id), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, room_name, sizeof(room_name), NULL);
			Room* temp = new Room(room_name, room_id);
			*(room + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}

int RoomAccess::Count()
{
	int i = 0;
	string c_query;
	c_query = "select * from room";
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

void RoomAccess::Show()
{}

bool RoomAccess::Insert()
{
	return 0;
}

bool RoomAccess::Update()
{
	return 0;
}

bool RoomAccess::Delete()
{
	return 0;
}

int RoomAccess::SearchName(char* r_name)
{
	return 0;
}

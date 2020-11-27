#include "AccountAccess.h"
#include <iomanip>
void AccountAccess::Select(Account*& acc)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLWCHAR*)L"SELECT * FROM account", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		int ID_number;
		char fullname[32];
		char username[32];
		char pwd[32];
		char email[32];
		char phone_number[50];
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_INTEGER, &ID_number, sizeof(ID_number), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, fullname, sizeof(fullname), NULL);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, username, sizeof(username), NULL);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, pwd, sizeof(pwd), NULL);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, email, sizeof(email), NULL);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, phone_number, sizeof(phone_number), NULL);

			Account* temp = new Account(ID_number,fullname, username, pwd, email, phone_number);
			*(acc + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
} 

void AccountAccess::Show()
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLWCHAR*)L"SELECT * FROM account", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		int ID_number;
		char fullname[32];
		char username[32];
		char pwd[32];
		char email[33];
		char phone_number[50];
		int n = 0;

		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_INTEGER, &ID_number, sizeof(ID_number), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, fullname, sizeof(fullname), NULL);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, username, sizeof(username), NULL);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, pwd, sizeof(pwd), NULL);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, email, sizeof(email), NULL);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, phone_number, sizeof(phone_number), NULL);
			cout << left << "ID: " << setw(4) << ID_number;
			cout << left << "Fullname: " << setw(20) <<fullname;
			cout << left << "Username: " << setw(20) << username;
			cout << left << "Email: " << setw(20) << email;
			cout << right << "Phone number: " << setw(11) << phone_number << endl;
			
			n++;
			if (n == MAX_ROW_SHOW) break;
		}
	}
	SQLCancel(SQLStateHandle);
}

bool AccountAccess::Insert()
{
	string c_query = "insert into account values ('";
	Account acc;
	acc.setAccount();
	c_query += acc.insertQuery();
	const char* q = c_query.c_str();
	cout << c_query;
	cout << q;
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		cout << c_query;
		cout << "Them du lieu thanh cong !" << endl;
		return true;
	}
	SQLCancel(SQLStateHandle);
}
bool AccountAccess::Update()
{
	return true;
}
bool AccountAccess::Delete()
{
	return true;
}
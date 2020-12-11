#include "AccountAccess.h"
#include "Account.h"
#include <iomanip>
void AccountAccess::Select(Account*& acc)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLWCHAR*)L"SELECT * FROM account", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!" << endl;
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
int AccountAccess::CountRow()
{
	int i = 0;
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLWCHAR*)L"SELECT * FROM account", SQL_NTS))
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
int AccountAccess::Search(int id)
{
	Account* ptr = new Account[this->CountRow()];
	this->Select(ptr);
	for (int i = 0; i < this->CountRow(); i++)
	{
		if (ptr[i].getID() == id) return i;
	}
	return -1;
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
		cout << "ID: " << setw(4) << "Fullname: " << setw(30) << "Username: " << setw(34) << "Phone number: " << setw(14) << "Email: " << setw(20) << endl;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_INTEGER, &ID_number, sizeof(ID_number), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, fullname, sizeof(fullname), NULL);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, username, sizeof(username), NULL);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, pwd, sizeof(pwd), NULL);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, phone_number, sizeof(phone_number), NULL);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, email, sizeof(email), NULL);
			cout << left << setw(4) << ID_number;
			cout << left << setw(20) <<fullname;
			cout << left  << setw(17) << username;
			cout << left  << setw(11) << phone_number;
			cout << right << setw(20) << email << endl;
			
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
	return false;
}
bool AccountAccess::Update()
{
	return true;
}
bool AccountAccess::Delete()
{
	return true;
}
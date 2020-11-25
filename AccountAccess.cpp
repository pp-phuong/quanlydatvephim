#include "AccountAccess.h"

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
			SQLGetData(SQLStateHandle, 1, SQL_INTEGER, &ID_number, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, fullname, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, username, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, pwd, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, email, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, phone_number, SQL_RESULT_LEN, &PtrSQLVersion);

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
			SQLGetData(SQLStateHandle, 1, SQL_INTEGER, &ID_number, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, fullname, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, username, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, pwd, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, email, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, phone_number, SQL_RESULT_LEN, &PtrSQLVersion);

			cout << ID_number << " " << fullname << " " << username << " " << pwd << " "<< phone_number << " "  << email<<  endl;
			n++;
			if (n == MAX_ROW_SHOW) break;
		}
	}
	SQLCancel(SQLStateHandle);
}

bool AccountAccess::Insert()
{
	string c_query = "insert into Account values ('";
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
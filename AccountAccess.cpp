#include "AccountAccess.h"

void AccountAccess::Select(Account*& acc)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLWCHAR*)L"SELECT * FROM Account", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		int ID_number;
		char fullname[30];
		char username[30];
		char pwd[30];
		char email[30];
		char phone[11];
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_INTEGER, &ID_number, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, fullname, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, username, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, pwd, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, email, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, phone, SQL_RESULT_LEN, &PtrSQLVersion);

			Account* temp = new Account(ID_number,fullname, username, pwd, email, email, phone);
			*(acc + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
} 

void AccountAccess::Show()
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLWCHAR*)L"SELECT * FROM Account", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		int ID_number;
		char fullname;
		char username;
		char pwd;
		char email;
		char phone;
		int n = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, &ID_number, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, &fullname, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, &username, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, &pwd, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, &email, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, &phone, SQL_RESULT_LEN, &PtrSQLVersion);

			cout << ID_number << " " << username << " " << username << " " << pwd << " " << email << " " << phone <<  endl;
			n++;
			if (n == MAX_ROW_SHOW) break;
		}
	}
	SQLCancel(SQLStateHandle);
}
AccountAccess::AccountAccess()
{

}
AccountAccess::~AccountAccess()
{

}

bool AccountAccess::Insert()
{

}
bool AccountAccess::Update()
{

}
bool AccountAccess::Delete()
{

}
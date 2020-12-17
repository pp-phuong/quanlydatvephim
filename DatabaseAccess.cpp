#include "DatabaseAccess.h"
bool DatabaseAccess::Init()
{
	//set SQLHandle = NULL
	SQLStateHandle = NULL;
	SQLConnectionHandle = NULL;
	//Allocates Handle
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvironmentHandle))
		Close();
	if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvironmentHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		Close();
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvironmentHandle, &SQLConnectionHandle))
		Close();

	cout << "Waiting......" << endl;
	/*Data Source = DESKTOP - S2SLR6P; Initial Catalog = QlyDatVePhim; Persist Security Info = True; User ID = sa*/
	switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server}; Server=DESKTOP-BIHQC8D;Database=QLDatVeXemPhim;UID=sa;PWD=123456;Trusted_Connection=True;",
		SQL_NTS,
		retConString,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {

	case SQL_SUCCESS:
		/*cout << "Ket noi thanh cong!!" << endl;*/
		break;

	case SQL_SUCCESS_WITH_INFO:
	/*	cout << "Ket noi thanh cong!!" << endl;*/
		break;

	case SQL_INVALID_HANDLE:
		cout << "Error!!" << endl;
		Close();
		break;

	case SQL_ERROR:
		cout << "Error!!" << endl;
		Close();
		break;
	default:
		break;
	}
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStateHandle))
		Close();
	return true;
}

void DatabaseAccess::Close()
{
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStateHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvironmentHandle);
}
void DatabaseAccess::Select()
{}

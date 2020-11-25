#include "SQL_Conn_Log.h"

using namespace std;


void SQL_Conn_Log::ShowSQLError(unsigned int HandleType, const HANDLE& Handle)
{
	SQLCHAR SQLState[1024];
	SQLCHAR Message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(HandleType, Handle, 1, SQLState, NULL, Message, 1024, NULL))
		cout << "SQL driver message: " << Message << "\nSQL state: " << SQLState << "." << endl;	
}

int SQL_Conn_Log::Default_Connection_String(SQLHANDLE SQLConnectionHandle)
{
	//SQL CONNECTION STRING!!
	SQLCHAR SQL_Conn_String[1024];
	switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server}; Server=DESKTOP-S2SLR6P;Database=QlyDatVePhim;UID=sa;PWD=123456;Trusted_Connection=True;", SQL_NTS, SQL_Conn_String, 1024, NULL, SQL_DRIVER_NOPROMPT))
	{
	case SQL_SUCCESS:
		return 1;
	case SQL_SUCCESS_WITH_INFO:
		return 1;
	case SQL_NO_DATA_FOUND:
		ShowSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
		return 0;
	case SQL_INVALID_HANDLE:
		ShowSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
		return 0;
	case SQL_ERROR:
		ShowSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
		return 0;
	default:
		return 0;
	}
	
	
}
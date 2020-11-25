#include <iostream>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>

class SQL_Conn_Log
{
private:
	SQLHANDLE SQLConn = NULL;
	SQLHANDLE SQLEnv = NULL;
	SQLHANDLE SQLState = NULL;
public:
	void ShowSQLError(unsigned int HandleType, const HANDLE& Handle);
	int Default_Connection_String(SQLHANDLE SQLConn);
};


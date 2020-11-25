#include <iostream>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "SQL_Conn_Log.h"
#include "GetDB.h"
using namespace std;

int main()
{
    //CALL CLASS HERE!!
    SQL_Conn_Log conn;
    GetDB get;
    //INIT SQL HANDLE!!
    SQLHANDLE SQLConnectionHandle = NULL;
    SQLHANDLE SQLStateHandle = NULL;
    SQLHANDLE SQLEnvHandle = NULL;

    do
    {
        //SQL INIT ODBC!!
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle)) break;
        if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) break;
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle)) break;
        if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0)) break;
        if (conn.Default_Connection_String(SQLConnectionHandle) == 0) break;
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStateHandle)) break;
        //ENTER FUNCTION HERE!!!
        get.CauHinhChiTiet(SQLStateHandle);
        //get.ThongTinKhachHang(SQLStateHandle);
    } while (FALSE);
    //SQL RELEASE HANDLE!!
    SQLFreeHandle(SQL_HANDLE_STMT, SQLStateHandle);
    SQLDisconnect(SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

}


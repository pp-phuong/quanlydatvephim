#include <iostream>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "DatabaseAccess.h"
#include "AccountAccess.h"
using namespace std;

int main()
{

    /*DatabaseAccess db;
    db.Init();db.Close();*/

    AccountAccess acc;
    acc.Init();
    acc.Show();
    acc.Close();
}


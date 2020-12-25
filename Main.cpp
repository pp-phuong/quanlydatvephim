#include <iostream>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "Date.h"
#include "Function.h"
using namespace std;

int main()
{
    Function fc;
    fc.Information();
    fc.Start();
    return 0;
}


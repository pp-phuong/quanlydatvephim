#include <iostream>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "Function.h"
using namespace std;

int main()
{
    Function fc;
    char key;
    AccountAccess acc;
    //fc.Authentication();
    cout << " WELCOME TO HANAFUO CINEMA!" << endl;
    do
    {
        fc.Menu(acc); 
        cout << "Do you want to be continute? y/n ";
        cin >> key;
    } while (key != 'n');
    return 0;
}


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
    fc.Authentication();
    char key;
    cout << " WELCOME TO HANAFUO CINEMA!" << endl;
    do
    {
        system("cls");
        if (fc.getUserNow().getRole() == 1) {
            fc.MenuAdmin();
        }
        else {
            fc.Menu();
        }
        cout << "Do you want to be continute? y/n ";
        cin >> key;
    } while (key != 'n');
    /*ScheduleAccess s;
    s.Init();
    int choice = 1;
    Schedule* ptr = new Schedule[s.Count(choice)];
    s.Select(ptr, choice, 0);
    
    for (int i = 0; i < s.Count(choice); i++)
    {
        cout << i + 1 << ".";
        cout << ptr[i].getSDate() <<endl;
    }
    cout << endl;
    s.Close();*/
    return 0;
}


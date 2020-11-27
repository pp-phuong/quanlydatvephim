#include "Function.h"

void Function::Menu(AccountAccess &acc)
{
    cout << "_________________________HANAFUO CINEMA_________________________" << endl
        << "                       1. MOVIE" << endl
        << "                       2. SCHEDULE " << endl
        << "                       3. BOOKING " << endl
        << "                       4. ACCOUNT" << endl
        << "                       5. INSERT ACCOUNT " << endl 
        << "                       PRESS THE NUMBER : ";
    int m;
    cin >> m;
    switch (m)
    {
    case 1:
        cout << "You chose MOVIE" << endl;
        /*cout << mv;*/
        break;
    case 2:
        cout << "You chose SCHEDULE" << endl;
        break;
    case 3:
        cout << "You chose BOOKING" << endl;
        break;
    case 4:
        cout << "You chose ACCOUNT" << endl;
        acc.Init();
        acc.Show();
        acc.Close();
        break;
    case 5:
        cout << "You chose INSERT " << endl;
        acc.Init();
        acc.Insert();
        acc.Close();
        break;
    default:
        cout << " Sorry,There is no matching option " << endl;
        break;
    }
}
void Function::Authentication(AccountAccess& acc)
{
    Account user;
    cout << "_________________________WELCOME TO HANAFUO CINEMA_________________________" << endl
        << "                          Do you have account ? " << endl
        << "                          1. Login " << endl
        << "                          2. Register " << endl
        << "                       PRESS THE NUMBER : ";
    int m;
    cin >> m;
    switch (m)
    {
    case 1:
        cout << "Login:" << endl;
        Authentication(acc);
        break;
    case 2:
        cout << "Register:" << endl;
        acc.Insert();
        cout << "Login:" << endl;
        Authentication(acc);
        break;
    default:
        cout << " Sorry,There is no matching option " << endl;
        break;
    }
}
//void Function::Validate()
//{
//    
//        int validate = 0;
//        string pass = "";
//        char ch;
//        while (!validate)
//        {
//            string username;
//            cout << "Username : ";
//            cin >> username;
//            if ((acc.SearchName(username)) == -1)
//            {
//                cout << "Khong tim thay tai khoan ! " << endl;
//                cout << "Xin moi nhap lai !" << endl;
//                continue;
//            }
//            else
//            {
//
//                /*string pwd = acc[acc.SearchName(username)].getPwd();*/
//                string pwd;
//
//                cout << "Pass : ";
//                /*ch = getch();*/
//                ch = 'a';
//                while (ch != 13)
//                {
//                    if (ch == '\b')
//                    {
//                        cout << static_cast<char>(8) << " " << static_cast<char>(8);
//                        if (!pass.empty())
//                            pass.pop_back();
//                    }
//                    else
//                    {
//                        pass.push_back(ch);
//                        cout << ch;
//                        Sleep(200);
//                        cout << static_cast<char>(8) << " " << static_cast<char>(8);
//                        cout << '*';
//                    }
//                   /* ch = getch();*/
//                }
//                cout << (pwd == pass) << endl;
//                cout << "pass : " << pass << "pwd:" << pwd << endl;
//                if (pass == pwd)
//                {
//                    cout << "Login success ! ";
//                    validate = 1;
//                }
//                else
//                    cout << "Sai mat khau ! Moi nhap lai ";
//                pass = "";
//                continue;
//            }
//        }
//}
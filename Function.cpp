#include "Function.h"
Function::Function() {
}
Function::~Function() {
}
void Function::Menu()
{
    cout << "_________________________HANAFUO CINEMA_________________________" << endl
        << "                       1. MOVIE" << endl
        << "                       2. SCHEDULE " << endl
        << "                       3. BOOKING " << endl
        << "                       4. ACCOUNT" << endl
        << "                       5. INSERT ACCOUNT " << endl
        << "                       6. INSERT MOVIE " << endl
        << "                       7. SEARCH MOVIE " << endl
        << "                       PRESS THE NUMBER : ";
    int m;
    int search;
    AccountAccess acc;
    MovieAccess mv;
    Account account;
    cin >> m;
    switch (m)
    {
    case 1:
        cout << "You chose MOVIE" << endl;
        mv.Init();
        mv.Show();
        mv.Close();
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
        cout << "You chose INSERT ACCOUNT " << endl;
        acc.Init();
        account.setAccount();
        acc.Insert(account);
        acc.Close();
        break;
    case 6:
        cout << "You chose INSERT MOVIE " << endl;
        mv.Init();
        mv.Insert();
        mv.Close();
        break;
    case 7:
        cout << "You chose INSERT MOVIE " << endl;
        cout << "Nhap ma phim can tim kiem :";
        cin >> search;
        mv.Init();
        cout << mv.Search(search);
        mv.Close();
        break;
    default:
        cout << " Sorry,There is no matching option " << endl;
        break;
    }
}
void Function::Authentication()
{
    AccountAccess acc;
    MovieAccess mv;
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
        Validate();
        break;
    case 2:
        cout << "Register:" << endl;
        acc.Init();
        user.setAccount();
        acc.Insert(user);
        cout << "Login:" << endl;
        Validate();
        break;
    default:
        cout << " Sorry,There is no matching option " << endl;
        break;
    }
}
void Function::Validate()
{
        AccountAccess acc;
        int validate = 0;
        char ch;
        while (!validate)
        {
            string username;
            cout << "Username : ";
            cin >> username;
            acc.Init();
            int stt = acc.SearchName(username);
            if ((acc.SearchName(username)) == -1)
            {
                cout << "Khong tim thay tai khoan ! " << endl;
                cout << "Xin moi nhap lai !" << endl;
                continue;
            }
            else
            {
                validate = 1;
                string pwd;
                Password:
                cout <<  "Pass : ";
                for (char c; c = _getch(); )
                {
                    if (c == 13 || c == '\r') // enter 
                    {
                        cout << "\n";
                        break;
                    }
                    else
                    {
                        if (c == 8) // backspace
                        {
                            if (!pwd.empty())
                            {
                                pwd.erase(pwd.size() - 1);
                                cout << "\b \b";
                            }
                        }
                        else {
                            if (c == -32 ) // phim mui ten
                            {
                                _getch();
                            }
                            else {
                                if (isprint(c))
                                {
                                    cout << '*';
                                    pwd += c;
                                }
                            }
                        }
                    }
                }
                char* password = const_cast<char*>(pwd.c_str());
                if (acc.checkPwd(stt) == pwd)
                {
                    
                    cout << "Login success ! " << endl;
                    validate = 1;
                    _getch();
                    system("cls");
                }
                else
                {
                    cout << "Sai mat khau ! Moi nhap lai " << endl;
                    pwd = "";
                    goto Password;
                }
            }
            this->setUserNow(stt); // sua thanh id
            acc.Close();
        }
}
void Function::setUserNow(int id)
{
    this->id_user = id;
}
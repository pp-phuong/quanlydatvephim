#include "Account.h"
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>

Account::Account()
{
    ID_number = 0;
	strcpy_s(fullname, 32, "");
	strcpy_s(username, 32, "");
	strcpy_s(pwd, 32, "");
	strcpy_s(email, 32, "");
	strcpy_s(phone_number,50, "");
    role = 0;
}
Account::Account(int ID,char* fullname, char* username, char* pwd, char* email, char* phone, int role)
    :ID_number(ID),role(role)
{
	strcpy_s(this->fullname,32, fullname);
	strcpy_s(this->username,32, username);
	strcpy_s(this->pwd,32, pwd);
	strcpy_s(this->email,32, email);
	strcpy_s(this->phone_number, 50, phone);
}
Account::~Account()
{
}
int Account::getID()
{
    return this->ID_number;
}
char* Account::getUsername()
{
    return this->username;
}
string Account::getStrUsername() {
    char* User = this->username;
    for (int i = strlen(User) - 1; i >= 0; i--) {
        if (User[i] != ' ') {
            User[i + 1] = '\0';
            break;
        }
    }
    string temp(User);
    return temp;
}
char* Account::getFullname()
{
    return this->fullname;
}
char* Account::getEmail()
{
    return this->email;
}
char* Account::getPhone()
{
    return this->phone_number;
}
char* Account::getPwd()
{
    char* pwd = this->pwd;
    for (int i = strlen(pwd) - 1; i >= 0; i--) {
        if (pwd[i] != ' ') {
            pwd[i + 1] = '\0';
            break;
        }
    }
    return pwd;
}
int Account::getRole()
{
    return this->role;
}
void Account::setAccount()
{
   /* AccountAccess acc;
    acc.Init();*/
    char ch;
    bool validate = false;
    /*int temp;
    do {
    cout << "ID Number :";
    cin >> temp;
    if (acc.Search(temp) != -1) {
        cout << "ID Number da ton tai !";
    }
    else validate = true;
    } while (validate == false);
    ID_number = temp;
    acc.Close();*/
    cout << "Fullname : ";
    cin.ignore();
    cin.getline(fullname,32);
    cout << "Username :";
    cin.getline(username,32);
    cout << "Email :";
    cin.getline(email, 32);
    cout << "Phone number :";
    cin.getline(phone_number, 50);
    cout << "Password :";
    cin.getline(pwd, 32);
   /* while (ch != 13)
    {
        if (ch == '\b')
        {

            if ( pwd == "")
            {
                pwd = pwd + ch;
                cout << static_cast<char>(8) << " " << static_cast<char>(8);
            }
        }
        else
        {
            if (ch == ' ')
            {
                cout << endl << " Khong nhap khoang trang !" << endl;
                cout << " Xin nhap lai mat khau !" << endl << "Password :";
                ch = getch();
                continue;
            }
            else
            {
                p.push_back(ch);
                cout << ch;
                Sleep(200);
                cout << static_cast<char>(8) << " " << static_cast<char>(8);
                cout << '*';
            }
        }
        ch = getch();
    }*/
}

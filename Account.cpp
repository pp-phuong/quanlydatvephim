#include "Account.h"
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>

Account::Account()
{
	ID_number = 0;
	strcpy_s(fullname, "");
	strcpy_s(username, "");
	strcpy_s(pwd, "");
	strcpy_s(email, "");
	strcpy_s(phone_number, "");
}
Account::Account(int ID,char* fullname, char* username, char* pwd, char* email, char* phone)
    :ID_number(ID)
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
char* Account::getPwd()
{
    return this->pwd;
}
void Account::setAccount()
{
    /*char ch;*/
    cout << "ID Number :";
    cin >> ID_number;
    cout << "Fullname : ";
    cin.ignore();
    cin.getline( fullname,32);
    cout << "Username :";
    cin.getline(username,32);
    cout << "Email :";
    cin.getline(email, 32);
    cout << "Phone number :";
    cin.getline(phone_number, 50);
    cout << "Password :";
    cin.getline(pwd, 32);
    /*while (ch != 13)
    {
        if (ch == '\b')
        {

            if ( !password.empty())
            {
                password.pop_back();
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
string Account::insertQuery()
{
    string t_query;
    string t_ID = to_string(ID_number);
    string t_fullname(fullname);
    string t_username(username);
    string t_pwd(pwd);
    string t_email(email);
    string t_phone(phone_number);
    t_query = t_ID + "','" + t_fullname +"','" + t_username + "','" + t_pwd +"','" + t_email +"','" + t_phone + "')";
    return t_query;
}
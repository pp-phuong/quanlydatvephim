#pragma once
#include "Account.h"
#include "DatabaseAccess.h"
class AccountAccess :
    public DatabaseAccess
{
public:
    void Select(Account*&);
    bool Insert();
    bool Update();
    bool Delete();
    void Show();
    int SearchName(string);

};


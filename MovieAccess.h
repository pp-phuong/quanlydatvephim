#pragma once
#include "Movie.h"
#include "Date.h"
#include "DatabaseAccess.h"
class MovieAccess :
    public DatabaseAccess
{
public:
    void Select(Movie*& , int);
    int CountRow(int);
    bool Insert();
    int Search(int); // search theo id_number
    bool Update();
    bool Delete();
    void Show(int);
    int SearchName(string);
};



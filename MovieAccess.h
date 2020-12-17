#pragma once
#include "Movie.h"
#include "DatabaseAccess.h"
class MovieAccess :
    public DatabaseAccess
{
public:
    void Select(Movie*&);
    int CountRow();
    bool Insert();
    int Search(int); // search theo id_number
    bool Update();
    bool Delete();
    void Show();
    int SearchName(string);

};



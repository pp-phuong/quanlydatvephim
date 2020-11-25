#include "CauHinh.h"
#include "DataAccess.h"
#pragma once
class CauHinhAccess : public DataAccess
{
public:
	void Select(CauHinh*&); 
	int countRow(); //Dem so dong cua bang

	bool Insert(); //Chen them du lieu vao bang
	bool Update();
	void Str_Update(const char*, char*, string, int);
	void Num_Update(const char*, float, string, int);
	bool Delete();
	void Show();
	void Sort();
	void Filter();
};

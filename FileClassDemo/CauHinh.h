#include <iostream>
#include <string>
#include <iomanip>
#pragma once

using namespace std;

class CauHinh 
{
protected:
	char MaSP[20];
	char MaModel[20];
	char ManHinh[20];
	char CPU[30];
	char GPU[50];
	char RAM[30];
	char LuuTru[20];
	int Pin_Wh;
	float KhoiLuong_Kg;
	int Gia;
public:
	CauHinh();
	CauHinh(char*, char*, char*, char*, char*, char*, char*, int, float, int);
	~CauHinh();

	friend ostream& operator<<(ostream&, const CauHinh&);
	void setCauHinh(); //Nhap tay cau hinh ban dau

	char* getMaSP();
	char* getMaModel();
	char* getManHinh();
	char* getCPU();
	char* getGPU();
	char* getRAM();
	char* getLuuTru();
	int getPin();
	float getKhoiLuong();
	int getGia();
	string insertQuery(); //Noi chuoi de tao thanh query nhap vao SQL


};


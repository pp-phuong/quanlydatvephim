#include "CauHinh.h"

CauHinh::CauHinh()
{
	strcpy_s(MaSP, "");
	strcpy_s(MaModel, "");
	strcpy_s(ManHinh, "");
	strcpy_s(CPU, "");
	strcpy_s(GPU, "");
	strcpy_s(RAM, "");
	strcpy_s(LuuTru, "");
	Pin_Wh = 0;
	KhoiLuong_Kg = 0;
	Gia = 0;
}

CauHinh::CauHinh(char* MaSP, char* MaModel, char* ManHinh, char* CPU, char* GPU, char* RAM, char* LuuTru, int Pin_Wh, float KhoiLuong_Kg, int Gia)
{
	strcpy_s(this->MaSP, 20, MaSP);
	strcpy_s(this->MaModel, 20, MaModel);
	strcpy_s(this->ManHinh, 20, ManHinh);
	strcpy_s(this->CPU, 30, CPU);
	strcpy_s(this->GPU, 50, GPU);
	strcpy_s(this->RAM, 30, RAM);
	strcpy_s(this->LuuTru, 20, LuuTru);
	this->Pin_Wh = Pin_Wh;
	this->KhoiLuong_Kg = KhoiLuong_Kg;
	this->Gia = Gia;
}

ostream& operator<<(ostream& o, const CauHinh& ch)
{
	o << ch.MaSP << " " << ch.MaModel << " " << ch.ManHinh << " " << ch.CPU << " " << ch.GPU << " " << ch.RAM << " "
		<< ch.LuuTru << " " << ch.Pin_Wh << " " << ch.KhoiLuong_Kg << " " << ch.Gia << " " << endl;
	return o;
}

void CauHinh::setCauHinh()
{
	cout << "Nhap ma SP: ";
	cin.getline(MaSP, 20);
	cout << "Nhap ma Model: ";
	cin.getline(MaModel, 20);
	cout << "Nhap thong tin man hinh: ";
	cin.getline(ManHinh, 20);
	cout << "Nhap thong tin ve CPU: ";
	cin.getline(CPU, 30);
	cout << "Nhap thong tin ve GPU: ";
	cin.getline(GPU, 50);
	cout << "Nhap thong tin ve RAM: ";
	cin.getline(RAM, 30);
	cout << "Nhap dung luong bo nho: ";
	cin.getline(LuuTru, 20);
	cout << "Nhap thong so pin: ";
	cin >> Pin_Wh;
	cout << "Nhap khoi luong cua san pham: ";
	cin >> KhoiLuong_Kg;
	cout << "Nhap gia san pham: ";
	cin >> Gia;
}

string CauHinh::insertQuery()
{
	string t_query;
	string t_MaSP(MaSP);
	string t_MaModel(MaModel);
	string t_ManHinh(ManHinh);
	string t_CPU(CPU);
	string t_GPU(GPU);
	string t_RAM(RAM);
	string t_LuuTru(LuuTru);
	string t_Pin = to_string(Pin_Wh);
	string t_KhoiLuong = to_string(KhoiLuong_Kg);
	string t_Gia = to_string(Gia);
	t_query = "'" + t_MaSP + "','" + t_MaModel + "','" + t_ManHinh + "','" + t_CPU + "','" + t_GPU + "','" + t_RAM
		+ "','" + t_LuuTru + "'," + t_Pin + "," + t_KhoiLuong + "," + t_Gia + ")";
	return t_query;
}

char* CauHinh::getMaSP() { return this->MaSP; }
char* CauHinh::getMaModel() { return this->MaModel; }
char* CauHinh::getManHinh() { return this->ManHinh; }
char* CauHinh::getCPU() { return this->CPU; }
char* CauHinh::getGPU() { return this->GPU; }
char* CauHinh::getRAM() { return this->RAM; }
char* CauHinh::getLuuTru() { return this->LuuTru; }
int CauHinh::getPin() { return this->Pin_Wh; }
float CauHinh::getKhoiLuong() { return this->KhoiLuong_Kg; }
int CauHinh::getGia() { return this->Gia; }

CauHinh::~CauHinh()
{

}


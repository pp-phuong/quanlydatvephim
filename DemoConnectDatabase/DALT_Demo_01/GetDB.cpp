#include <iomanip>
#include "GetDB.h"
#include "SQL_Conn_Log.h"

using namespace std;

void GetDB::Account(SQLHANDLE SQLStateHandle)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)this->Account_Query, SQL_NTS))
	{
		SQL_Conn_Log conn;
		conn.ShowSQLError(SQL_HANDLE_STMT, SQLStateHandle);
		return;
	}
	else
	{
		char ID[20];
		char Pass[20];
		cout << "TITTLE" << endl;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_C_DEFAULT, &ID, sizeof(ID), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_C_DEFAULT, &Pass, sizeof(ID), NULL);
			cout << ID << " " << Pass << endl;
		}
	}
}

void GetDB::CauHinhChiTiet(SQLHANDLE SQLStateHandle)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)this->CauHinhChiTiet_Query, SQL_NTS))
	{
		SQL_Conn_Log conn;
		conn.ShowSQLError(SQL_HANDLE_STMT, SQLStateHandle);
		return;
	}
	else
	{
		char MaSP[5];
		char MaModel[5];
		char ManHinh[10];
		char CPU[20];
		char GPU[50];
		char RAM[10];
		char LuuTru[10];
		int Pin_Wh;
		double KhoiLuong_Kg;
		int Gia;

		int index = 0;  //COUT FIRST 'i' VALUE!!

		cout << "MaSP MaModel ManHinh CPU GPU RAM LuuTru Pin_Wh KhoiLuong_Kg Gia" << endl;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_C_DEFAULT, &MaSP, sizeof(MaSP), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_C_DEFAULT, &MaModel, sizeof(MaModel), NULL);
			SQLGetData(SQLStateHandle, 3, SQL_C_DEFAULT, &ManHinh, sizeof(ManHinh), NULL);
			SQLGetData(SQLStateHandle, 4, SQL_C_DEFAULT, &CPU, sizeof(CPU), NULL);
			SQLGetData(SQLStateHandle, 5, SQL_C_DEFAULT, &GPU, sizeof(GPU), NULL);
			SQLGetData(SQLStateHandle, 6, SQL_C_DEFAULT, &RAM, sizeof(RAM), NULL);
			SQLGetData(SQLStateHandle, 7, SQL_C_DEFAULT, &LuuTru, sizeof(LuuTru), NULL);
			SQLGetData(SQLStateHandle, 8, SQL_C_DEFAULT, &Pin_Wh, sizeof(Pin_Wh), NULL);
			SQLGetData(SQLStateHandle, 9, SQL_C_DEFAULT, &KhoiLuong_Kg, sizeof(KhoiLuong_Kg), NULL);
			SQLGetData(SQLStateHandle, 10, SQL_C_DEFAULT, &Gia, sizeof(Gia), NULL);
			cout << fixed << setprecision(2);
			cout << MaSP << " " << MaModel << " " << ManHinh << " " << CPU << " " << GPU << " " << RAM << " " << LuuTru << " " << Pin_Wh << " " << KhoiLuong_Kg << " " << Gia << endl;

			index++;
			if (index == 10) break;
		}
	}
}

void GetDB::ThongTinKhachHang(SQLHANDLE SQLStateHandle)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)this->ThongTinKhachHang_Query, SQL_NTS))
	{
		SQL_Conn_Log conn;
		conn.ShowSQLError(SQL_HANDLE_STMT, SQLStateHandle);
		return;
	}
	else
	{
		char MaKH[20];
		char TenKH[30];
		char SDT[10];
		char TenSP[30];
		char MaSP[20];
		int SoLuong;
		int TongThanhToan;
		//tm TGTT;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_C_DEFAULT, &MaKH, sizeof(MaKH), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_C_DEFAULT, &TenKH, sizeof(TenKH), NULL);
			SQLGetData(SQLStateHandle, 3, SQL_C_DEFAULT, &SDT, sizeof(SDT), NULL);
			SQLGetData(SQLStateHandle, 4, SQL_C_DEFAULT, &TenSP, sizeof(TenSP), NULL);
			SQLGetData(SQLStateHandle, 5, SQL_C_DEFAULT, &MaSP, sizeof(MaSP), NULL);
			SQLGetData(SQLStateHandle, 6, SQL_C_DEFAULT, &SoLuong, sizeof(SoLuong), NULL);
			SQLGetData(SQLStateHandle, 7, SQL_C_DEFAULT, &TongThanhToan, sizeof(TongThanhToan), NULL);
			//SQLGetData(SQLStateHandle, 8, SQL_C_DEFAULT, &TGTT, sizeof(TGTT), NULL);
		}
	}
}

void GetDB::ThongTinNhanVien(SQLHANDLE SQLStateHandle)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)this->ThongTinNhanVien_Query, SQL_NTS))
	{
		SQL_Conn_Log conn;
		conn.ShowSQLError(SQL_HANDLE_STMT, SQLStateHandle);
		return;
	}
	else
	{
		char MaNV[20];
		char HoTen[30];
		//date NgaySinh;
		//bit Nam;
		char SDT[10];
		char DiaChi[50];
		//date NgayVaoLam;
		char ChucVu[20];

		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_C_DEFAULT, &MaNV, sizeof(MaNV), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_C_DEFAULT, &HoTen, sizeof(HoTen), NULL);
			//SQLGetData(SQLStateHandle, 3, SQL_C_DEFAULT, &NgaySinh, sizeof(NgaySinh), NULL);
			//SQLGetData(SQLStateHandle, 4, SQL_C_DEFAULT, &Nam, sizeof(Nam), NULL);
			SQLGetData(SQLStateHandle, 5, SQL_C_DEFAULT, &SDT, sizeof(SDT), NULL);
			SQLGetData(SQLStateHandle, 6, SQL_C_DEFAULT, &DiaChi, sizeof(DiaChi), NULL);
			//SQLGetData(SQLStateHandle, 7, SQL_C_DEFAULT, &NgayVaoLam, sizeof(NgayVaoLam), NULL);
			SQLGetData(SQLStateHandle, 8, SQL_C_DEFAULT, &ChucVu, sizeof(ChucVu), NULL);
		}
	}
}

void GetDB::ThongTinSanPham(SQLHANDLE SQLStateHandle)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)this->ThongTinSanPham_Query, SQL_NTS))
	{
		SQL_Conn_Log conn;
		conn.ShowSQLError(SQL_HANDLE_STMT, SQLStateHandle);
		return;
	}
	else
	{
		char MaSP[20];
		char Hang[20];
		char TenSP[30];
		char XuatXu[20];
		//date NgaySX;

		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_C_DEFAULT, &MaSP, sizeof(MaSP), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_C_DEFAULT, &Hang, sizeof(Hang), NULL);
			SQLGetData(SQLStateHandle, 3, SQL_C_DEFAULT, &TenSP, sizeof(TenSP), NULL);
			SQLGetData(SQLStateHandle, 4, SQL_C_DEFAULT, &XuatXu, sizeof(XuatXu), NULL);
			//SQLGetData(SQLStateHandle, 5, SQL_C_DEFAULT, &NgaySX, sizeof(NgaySX), NULL);
		}
	}
}

void GetDB::XuatNhapKho(SQLHANDLE SQLStateHandle)
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLCHAR*)this->XuatNhapKho_Query, SQL_NTS))
	{
		SQL_Conn_Log conn;
		conn.ShowSQLError(SQL_HANDLE_STMT, SQLStateHandle);
		return;
	}
	else
	{
		char MaSP[20];
		//bit NhapOrXuat;
		//datetime ThoiGianNX;
		char DiaChiNhapXuat[30];
		int SoLuong;
		int DonGia;
		char NhanVienNX[20];

		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_C_DEFAULT, &MaSP, sizeof(MaSP), NULL);
			//SQLGetData(SQLStateHandle, 2, SQL_C_DEFAULT, &NhapOrXuat, sizeof(MaSP), NULL);
			//SQLGetData(SQLStateHandle, 3, SQL_C_DEFAULT, &ThoiGianNhapXuat, sizeof(MaSP), NULL);
			SQLGetData(SQLStateHandle, 4, SQL_C_DEFAULT, &DiaChiNhapXuat, sizeof(MaSP), NULL);
			SQLGetData(SQLStateHandle, 5, SQL_C_DEFAULT, &SoLuong, sizeof(MaSP), NULL);
			SQLGetData(SQLStateHandle, 6, SQL_C_DEFAULT, &DonGia, sizeof(MaSP), NULL);
			SQLGetData(SQLStateHandle, 7, SQL_C_DEFAULT, &NhanVienNX, sizeof(MaSP), NULL);
		}
	}
}
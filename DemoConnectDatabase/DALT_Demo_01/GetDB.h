#include <iostream>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
class GetDB
{
private:
	//ENTER YOUR QUERY!!
	const char* Account_Query = "SELECT * FROM Account";
	const char* CauHinhChiTiet_Query = "SELECT * FROM CauHinhChiTiet";
	const char* ThongTinKhachHang_Query = "SELECT * FROM ThongTinKhachHang";
	const char* ThongTinNhanVien_Query = "SELECT * FROM ThongTinNhanVien";
	const char* ThongTinSanPham_Query = "SELECT * FROM ThongTinSanPham";
	const char* XuatNhapKho_Query = "SELECT * FROM XuatNhapKho";
public:
	//GET DATABASE FUNCTION!!
	void Account(SQLHANDLE SQLStateHandle);
	void CauHinhChiTiet(SQLHANDLE SQLStateHandle);
	void ThongTinKhachHang(SQLHANDLE SQLStateHandle);
	void ThongTinNhanVien(SQLHANDLE SQLStateHandle);
	void ThongTinSanPham(SQLHANDLE SQLStateHandle);
	void XuatNhapKho(SQLHANDLE SQLStateHandle);

};


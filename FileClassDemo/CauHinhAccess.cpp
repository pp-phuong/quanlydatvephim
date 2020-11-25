#include "CauHinhAccess.h"

void CauHinhAccess::Select(CauHinh*& ch)//Do? du lieu tu SQL vao` bien' ch
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLWCHAR*)L"SELECT * FROM CauHinhChiTiet", SQL_NTS)) //SQLExecDirect kiem tra cau lenh sql sau chu~ L co loi~ k
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion; //Ni chac khai bao ra r de do' k dung. gi` toi' giong may cai luc ket noi thoi :V dung` cho~ SQLGetData
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
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaSP, SQL_RESULT_LEN, &PtrSQLVersion); //Chuoi thi dung kieu z, so' 1 la` stt cot can doc
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, MaModel, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, ManHinh, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, CPU, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, GPU, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, RAM, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 7, SQL_CHAR, LuuTru, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 8, SQL_INTEGER, &Pin_Wh, 1, &PtrSQLVersion); //Kieu int hay float thi` dung` kieu z
			SQLGetData(SQLStateHandle, 9, SQL_C_FLOAT, &KhoiLuong_Kg, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 10, SQL_INTEGER, &Gia, 1, &PtrSQLVersion);

			CauHinh* temp = new CauHinh(MaSP, MaModel, ManHinh, CPU, GPU, RAM, LuuTru, Pin_Wh, KhoiLuong_Kg, Gia);
			*(ch + i) = *temp; //Dua du lieu vua doc vao bien temp vao` bien' ch (la` bien' do? du~ lieu vao` ban dau`)
			i++;
		}
	}
	SQLCancel(SQLStateHandle); //Xoa con tro SQLStateHandle de lan sau su dung k loi
}

int CauHinhAccess::countRow()
{
	int n = 0;
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLWCHAR*)L"SELECT * FROM CauHinhChiTiet", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS) n++;
	}
	SQLCancel(SQLStateHandle);
	return n;
}

bool CauHinhAccess::Insert()
{
	string c_query = "insert into CauHinhChiTiet (MaSP, MaModel, ManHinh, CPU, GPU, RAM, LuuTru, [Pin(Wh)], [KhoiLuong(Kg)], Gia) values (";
	CauHinh ch;
	ch.setCauHinh(); //Khoi tao bien ch rong~
	c_query += ch.insertQuery(); // Nhap query roi cho cong vao cau query
	const char* q = c_query.c_str(); // Chuyen cau query sang const char* de cau lenh cua sql nhan duoc
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS)) // 
	{
		cout << "Co loi xay ra, vui long kiem tra du lieu nhap vao!" << endl;
		Close();
		return false;
	}
	else
	{
		cout << "Them du lieu thanh cong!" << endl;
		return true;
	}
	SQLCancel(SQLStateHandle); //Xoa con tro SQLStateHandle de lan sau su dung k loi
}

bool CauHinhAccess::Update() //Ni la thinh no cho phep update so cot nhap vao tuy y, nhap stt cot can update
{
	char t_MaSP[20];
	int n = 0, t;
	string query;
	cout << "Nhap MaSP can cap nhat: ";
	cin.ignore(); //Xoa ki tu dau tien trong bo nho dem
	cin.getline(t_MaSP, 20); //Nhap vao MaSP can update
	CauHinh* ptr = new CauHinh[countRow()]; //Cap phat con tro ptr kieu cauhinh voi so hang` cua bang cau' hinh` o nho'
	Select(ptr);
	for (int i = 0; i < countRow(); i++)
	{
		if (strcmp(ptr[i].getMaSP(), t_MaSP) == 0)
		{
			string MaSP(ptr[i].getMaSP());
			cout << "Da chon ban ghi: " << *(ptr + i) << endl; //In ra de xem co dung' cho can update khong thoi :V
			cout << "Nhap so cot can cap nhat: ";
			cin >> n;
			while (n > 0)
			{
				cout << "Nhap STT cot: ";
				cin >> t;
				switch (t)
				{
				case 1:
					Str_Update("MaSP", ptr[i].getMaSP(), MaSP, n);
					break;
				case 2:
					Str_Update("MaModel", ptr[i].getMaModel(), MaSP, n);
					break;
				case 3:
					Str_Update("ManHinh", ptr[i].getManHinh(), MaSP, n);
					break;
				case 4:
					Str_Update("CPU", ptr[i].getCPU(), MaSP, n);
					break;
				case 5:
					Str_Update("GPU", ptr[i].getGPU(), MaSP, n);
					break;
				case 6:
					Str_Update("RAM", ptr[i].getRAM(), MaSP, n);
					break;
				case 7:
					Str_Update("LuuTru", ptr[i].getLuuTru(), MaSP, n);
					break;
				case 8:
					Num_Update("Pin", (float)ptr[i].getPin(), MaSP, n);
					break;
				case 9:
					Num_Update("KhoiLuong", ptr[i].getKhoiLuong(), MaSP, n);
					break;
				case 10:
					Num_Update("Gia", (float)ptr[i].getGia(), MaSP, n);
					break;
				default:
					cout << "Khong ton tai cot nay, vui long kiem tra lai!!";
					n++; //Cong lenh de bo qua cot vua nhap loi~ va` giu~ nguyen so cot can` cap. nhap. luc' dau`
					break;
				}
				n--; //Luc nao n = 0 thi` dung`
			}
			return true;
		}
	}
	cout << "Khong tim thay ban ghi nao co MaSP la " << t_MaSP << endl;
	return false;
}
//Str_Update va` Num_Update la` ham` phu. ho~ tro. cho ham` update nhanh hon
void CauHinhAccess::Str_Update(const char* option, char* oldStr, string MaSP, int n)//Tao query khi bang chi co kieu chuoi~
{
	cout << "Nhap " << option << ": ";
	char tmp[20];
	cin.ignore();
	cin.getline(tmp, 20);
	string NewStr(tmp);
	string OldStr(oldStr);
	string Option(option);
	string query = "update CauHinhChiTiet set " + Option + " = '" + NewStr + "' where MaSP = " +
		"'" + MaSP + "' and " + Option + " = '" + OldStr + "'";
	const char* q = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long kiem tra lai." << endl;
		n++;
	}
	else
	{
		cout << "Cap nhat thanh cong!!" << endl;
		Show();
	}
}

void CauHinhAccess::Num_Update(const char* option, float oldValue, string MaSP, int n)//Tao query khi bang co cot la` so'
{
	cout << "Nhap " << option << ": "; //option la` ten cot. co du~ lieu la` so'
	char tmp[20];
	cin.ignore();
	cin.getline(tmp, 20);
	string OldStr = to_string(oldValue); //dung` ham` co' san~ de chuyen gia tri so thanh` string thoi
	string NewStr(tmp);
	string Option(option);
	string query = "update CauHinhChiTiet set " + Option + " = '" + NewStr + "' where MaSP = " +
		"'" + MaSP + "' and " + Option + " = '" + OldStr + "'";
	const char* q = query.c_str(); //doi string qua const char*
	cout << q << endl; //in cai' query ra coi thu dung k thoi :V
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))//Ni khac cai phia tren la` do q la` 1 cai const char* chu k phai dang "abcxyz" nen no doi thanh SQLCHAR* voi k co chu~ L phia truoc
	{
		cout << "Co loi xay ra, vui long kiem tra lai." << endl;
		n++;
	}
	else
	{
		cout << "Cap nhat thanh cong!!" << endl;
		Show();
	}
}

bool CauHinhAccess::Delete()//Tuong tu may cai em noi o tren r nen k noi lai nua~ :V
{
	string c_query = "delete from CauHinhChiTiet where MaSP = '";
	char temp[20];
	cout << "Nhap MaSP can xoa: ";
	cin.ignore();
	cin.getline(temp, 20);
	CauHinh* ptr = new CauHinh[countRow()];
	Select(ptr);
	for (int i = 0; i < countRow(); i++)
	{
		if (strcmp(ptr[i].getMaSP(), temp) == 0)
		{
			cout << *(ptr + i) << endl;
			string t_MaSP(ptr[i].getMaSP());
			c_query = c_query + t_MaSP + "'";
			const char* q = c_query.c_str();
			cout << "Ban co chac chan muon xoa ban ghi " << ptr[i].getMaSP() << "? (Y/N): ";
			char ans;
			cin >> ans;
			switch (ans)
			{
			case 'Y':
			case 'y':
				if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*) q, SQL_NTS))
				{
					cout << "Khong tim thay MaSP nao phu hop!!" << endl;
					Close();
					return false;
				}
				else
				{
					cout << "Xoa ban ghi thanh cong!!" << endl;
					return true;
				}
			default:
				break;
			}
		}
	}
	cout << "Khong tim thay MaSP nao phu hop!!" << endl;
	return false;
}

void CauHinhAccess::Sort()//Tuong tu luon, them order by cho select thoi :V
{
	char temp[20];
	cout << "Nhap cot muon sap xep: ";
	//cin.ignore();
	cin >> temp;
	string t(temp);
	if (t == "KhoiLuong") t = "[KhoiLuong(Kg)]";
	if (t == "Pin") t = "[Pin(Wh)]";
	string query = "select * from CauHinhChiTiet order by " + t + " desc";
	const char* q = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Khong tim thay cot, vui long kiem tra lai" << endl;
		return;
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaSP[20];
		char MaModel[20];
		char ManHinh[20];
		char CPU[30];
		char GPU[50];
		char RAM[30];
		char LuuTru[21];
		int Pin_Wh;
		double KhoiLuong_Kg;
		int Gia;
		int n = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, MaModel, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, ManHinh, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, CPU, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, GPU, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, RAM, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 7, SQL_CHAR, LuuTru, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 8, SQL_INTEGER, &Pin_Wh, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 9, SQL_DOUBLE, &KhoiLuong_Kg, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 10, SQL_INTEGER, &Gia, 1, &PtrSQLVersion);

			cout << MaSP << " " << MaModel << " " << ManHinh << " " << CPU << " " << GPU << " " << RAM << " " << Pin_Wh << " " << KhoiLuong_Kg << " " << Gia << " " << endl;
			n++;
			if (n == MAX_ROW_SHOW) break;
		}
	}
	SQLCancel(SQLStateHandle);
}

void CauHinhAccess::Show()//In cau hinh ra coi thoi :V ma` nay chu moi de y cai MAX_ROW_SHOW = 10 a', do k muon' no' in nhieu` qua' nen de z thoi :V
{
	if (SQL_SUCCESS != SQLExecDirect(SQLStateHandle, (SQLWCHAR*)L"SELECT * FROM CauHinhChiTiet", SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		char MaSP[20];
		char MaModel[20];
		char ManHinh[20];
		char CPU[30];
		char GPU[50];
		char RAM[30];
		char LuuTru[21];
		int Pin_Wh;
		double KhoiLuong_Kg;
		int Gia;
		int n = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_CHAR, MaSP, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, MaModel, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, ManHinh, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 4, SQL_CHAR, CPU, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, GPU, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR, RAM, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 7, SQL_CHAR, LuuTru, SQL_RESULT_LEN, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 8, SQL_INTEGER, &Pin_Wh, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 9, SQL_DOUBLE, &KhoiLuong_Kg, 1, &PtrSQLVersion);
			SQLGetData(SQLStateHandle, 10, SQL_INTEGER, &Gia, 1, &PtrSQLVersion);
		
			cout << MaSP << " " << MaModel << " " << ManHinh << " " << CPU << " " << GPU << " " << RAM << " " << LuuTru << " " << Pin_Wh << " " << KhoiLuong_Kg << " " << Gia << " " << endl;
			n++;
			if (n == MAX_ROW_SHOW) break;
		}
	}
	SQLCancel(SQLStateHandle);
}


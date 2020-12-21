#include "MovieAccess.h"
MovieAccess::MovieAccess()
{
	this->search_key = "";
}
MovieAccess::~MovieAccess()
{

}
void MovieAccess::Select(Movie*& mv, int choice)
{
	// 1: select all
	// 2: select phim đang chiếu
	// 3. select phim sắp khởi chiếu
	// 4. select phim được tìm kiếm
	// 5. select phim hôm nay
	int i = 0;
	Date date;
	string c_query;
	switch (choice)
	{
	case 1:
		c_query = "select * from movie";
		break;
	case 2:
		c_query = "select * from movie where movie_release  <= " + date.getToDay();
		break;
	case 3:
		c_query = "select * from movie where movie_release  > " + date.getToDay();
		break;
	case 4:
		 c_query = "select * from movie where movie_name like '%" + this->search_key + "%'";
		break;
	case 5:
		c_query = "select * from movie where movie_release = " + date.getToDay();
		break;
	}
	const char* q = c_query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!" << endl;
		Close();
	}
	else
	{
		SQLINTEGER PtrSQLVersion;
		int movie_id;
		char movie_name[50];
		char movie_description[160];
		char movie_release[15];
		int movie_length;
		char movie_genre[50];
		int i = 0;
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			SQLGetData(SQLStateHandle, 1, SQL_INTEGER, &movie_id, sizeof(movie_id), NULL);
			SQLGetData(SQLStateHandle, 2, SQL_CHAR, movie_name, sizeof(movie_name), NULL);
			SQLGetData(SQLStateHandle, 3, SQL_CHAR, movie_description, sizeof(movie_description), NULL);
			SQLGetData(SQLStateHandle, 4,SQL_INTEGER, &movie_length, sizeof(movie_length), NULL);
			SQLGetData(SQLStateHandle, 5, SQL_CHAR, movie_genre, sizeof(movie_genre), NULL);
			SQLGetData(SQLStateHandle, 6, SQL_CHAR,  movie_release, sizeof( movie_release), NULL);

			Movie* temp = new Movie(movie_id, movie_name, movie_description, movie_release, movie_length, movie_genre);
			*(mv + i) = *temp;
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
}
int MovieAccess::CountRow(int choice)
{
	// 1: đếm all
	// 2: đếm phim đang chiếu
	// 3. đếm phim sắp khởi chiếu
	int i = 0;
	Date date;
	string c_query;
	switch (choice)
	{
	case 1:
		c_query = "select * from movie";
		break;
	case 2:
		c_query = "select * from movie where movie_release  <= " + date.getToDay();
		break;
	case 3:
		c_query = "select * from movie where movie_release  > " + date.getToDay();
		break;
	case 4:
		 c_query = "select * from movie where movie_name like '%" + this->search_key + "%'";
		break;
	case 5:
		c_query = "select * from movie where movie_release = " + date.getToDay();
		break;
	}
	const char* q = c_query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!" << endl;
		Close();
	}
	else
	{
		while (SQLFetch(SQLStateHandle) == SQL_SUCCESS)
		{
			i++;
		}
	}
	SQLCancel(SQLStateHandle);
	return i;
}
int MovieAccess::Search(int id)
{
	Movie* ptr = new Movie[this->CountRow(1)];
	this->Select(ptr,1);
	for (int i = 0; i < this->CountRow(1); i++)
	{
		if (ptr[i].getMovieID() == id) return i;
	}
	return -1;
}
void MovieAccess::Show(int index)
{
	if (index == 4)
	{
		cout << "Nhap ten phim ban can tim: ";
		cin >> this->search_key;
	}
	Movie* ptr = new Movie[this->CountRow(index)];
	this->Select(ptr, index);
	
	for (int i = 0; i < this->CountRow(index); i++)
	{
		cout << i + 1 << ".";
		ptr[i].Show();
	}
	if (this->CountRow(index) == 0)
	{
		cout << endl << "Sorry,no film founded!" << endl;
	}
}
bool MovieAccess::Insert()
{
	string c_query = "insert into movie values ('";
	Movie mv;
	mv.setMovie();
	c_query += mv.insertQuery();
	const char* q = c_query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		cout << c_query;
		cout << "Them du lieu thanh cong !" << endl;
		return true;
	}
	SQLCancel(SQLStateHandle);
	return false;
}
bool MovieAccess::Update(int id, int type)
{
	//1. Movie name
	//2. movie description
	// 3. movie release
	// 4. movie length
	// 5. movie genre
	string c_query = "update movie set" ;
	string movie_name;
	string movie_description;
	string movie_release;
	int movie_length;
	string movie_genre;
	switch (type)
	{
	case 1:
		cout << "Nhap movie name :";
		cin.ignore();
		getline(cin,movie_name);
		c_query += " movie_name = '"+ movie_name;
		break;
	case 2:
		cout << "Nhap movie description :";
		cin.ignore();
		getline(cin, movie_description);
		c_query += " movie_description = '" +  movie_description;
		break;
	case 3:
		cout << "Nhap movie release :";
		cin.ignore();
		getline(cin, movie_release);
		c_query += " movie_release = '" + movie_release;
		break;
	case 4 :
		cout << "Nhap movie length :";
		cin >> movie_length;
		c_query += " movie_length = '" + to_string(movie_length);
		break;
	case 5:
		cout << "Nhap movie genre :";
		cin.ignore();
		getline(cin, movie_genre);
		c_query += " movie_genre = '" + movie_genre;
		break;
	}
	c_query += "'where movie_id = '" + to_string(id) + "'";
	const char* q = c_query.c_str();
	cout << q;
	if (SQL_SUCCESS != SQLExecDirectA(SQLStateHandle, (SQLCHAR*)q, SQL_NTS))
	{
		cout << endl << "Co loi xay ra, vui long thu lai!!" << endl;
		Close();
	}
	else
	{
		cout << c_query;
		cout << endl <<  "Them du lieu thanh cong !" << endl;
		return true;
	}
	SQLCancel(SQLStateHandle);
	return false;
	return true;
}
bool MovieAccess::Delete()
{
	return true;
}
Movie MovieAccess::getMovie(int index)
{
	Movie* ptr = new Movie[this->CountRow(1)];
	this->Select(ptr,1);
	return ptr[index];
}
int MovieAccess::LastID()
{
	Movie* ptr = new Movie[this->CountRow(1)];
	this->Select(ptr,1);
	return ptr[this->CountRow(1) - 1].getMovieID();
}
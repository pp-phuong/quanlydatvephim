#pragma once
#include <string>
class Seat
{
	int seat_id ;
	int	seat_type_id;
	int	room_id;
	char seat_row[5];
	char seat_number[5];
	int seat_status;
public:
	Seat(int = 0, int =0 , int =0, char*, char*, int = 0);
	~Seat();
	int getID();
	int getStatus(); // ... cái chi cần dùng thì viết get ra
	string setQueryInsert();
};


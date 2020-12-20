#pragma once
#include "DatabaseAccess.h"
#include "Seat.h"
class SeatAccess :
    public DatabaseAccess
{
	public:
	void Insert(); // thêm seat 
	void Select(Seat*&); // đổ dữ liệu full seat về
	void Show(); // show seat row vs number vs loại seat
	void Update(); // chỉnh sửa seatType của seat
	void Delete(); // xóa seat
	int CountRow(); // đếm hàng ghế
};


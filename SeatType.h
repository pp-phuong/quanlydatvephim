#pragma once
class SeatType
{
public:
    int seat_type_id;
    int seat_price;
    char seat_type;
public:
    void Add(); // insert new seattype 
    void Select(SeatType *&); // Lấy về list seatType
    void Update(); // chỉnh sửa seatType, đổi giá, đổi tên 
    void Delete(); // xóa loại seatType đó đi
    void Show(); // xem seatType ( ko cần thiết lắm )
};



USE QLDatVeXemPhim
CREATE TABLE account
(
	ID_number int PRIMARY KEY,
	fullname char(30) NOT NULL,
	username char(30) NOT NULL,
	pwd char(30) NOT NULL,
	phone_number char(20) NOT NULL,
	email char(40) NOT NULL,
	admin_role int DEFAULT (0)
)
GO
CREATE TABLE movie
(
	movie_id int PRIMARY KEY,
	movie_name char(35) NOT NULL,
	movie_description char(150),
	movie_length int NOT NULL,
	movie_genres char(30) NOT NULL,
	movie_release Date NOT NULL
)
GO
CREATE TABLE room
(
	room_id int  PRIMARY KEY,
	room_name char(2) NOT NULL
)
GO
CREATE TABLE schedule
(
	schedule_id int PRIMARY KEY,
	movie_id int NOT NULL ,
	room_id int NOT NULL ,
	schedule_date date,
	schedule_start time NOT NULL,
	schedule_end time,
	constraint fk_id_movie FOREIGN KEY (movie_id ) REFERENCES movie(movie_id),
	constraint fk_id_room FOREIGN KEY (room_id) REFERENCES room(room_id)
)
GO
CREATE TABLE seatType
(
	seat_type_id int PRIMARY KEY,
	seat_type char(10) NOT NULL,
	seat_price money DEFAULT (45000)
)
GO
CREATE TABLE seat
(
	seat_id int PRIMARY KEY,
	seat_type_id int,
	room_id int NOT NULL,
	seat_row char(1) NOT NULL,
	seat_number char(2) NOT NULL,
	seat_status int NOT NULL,
	constraint fk_id_seat_type FOREIGN KEY (seat_type_id) REFERENCES seatType(seat_type_id)
)
GO
CREATE TABLE booking
(
	booking_id INT PRIMARY KEY,
	ID_number int NOT NULL,
	schedule_id int NOT NULL,
	seat_id int NOT NULL,
	constraint fk_indentity_number FOREIGN KEY (ID_number) REFERENCES account(ID_number),
	constraint fk_id_schedule FOREIGN KEY (schedule_id) REFERENCES schedule(schedule_id),
	constraint fk_id_book_seat FOREIGN KEY (seat_id) REFERENCES seat(seat_id)
)
GO

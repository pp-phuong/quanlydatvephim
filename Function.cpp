#include "Function.h"
Function::Function() {
    this->search = 0;
}
Function::~Function() {
}
void Function::MenuAdmin()
{
    cout << "_________________________HANAFUO CINEMA_________________________" << endl
        << "                       1. Movie" << endl
        << "                       2. Account " << endl
        << "                       3. Booking " << endl
        << "                       4. Schedule" << endl
        << "                       5. Room" << endl
        << "                       6. Seat " << endl
        << "                       7. SeatType" << endl
        << "                       8. Menu User" << endl
        << "                       9. Log out " << endl
        << "                       PRESS THE NUMBER : ";
    int m;
    Account out;
    cin >> m;
    switch (m)
    {
    case 1:
        this->MenuAdMovie();
        break;
    case 2:
        this->MenuAdAccount();
        break;
    case 3:
        this->MenuAdBooking();
        break;
    case 4:
        this->MenuAdSchedule();
        break;
    case 5:
        this->MenuAdRoom();
        break;
    case 6:
        this->MenuAdSeat();
        break;
    case 7:
        this->MenuAdSeatType();
        break;
    case 8: 
        Menu();
        break;
    case 9:
        this->user_now = out;
        Authentication();
        break;
    default:
        cout << " Sorry,There is no matching option " << endl;
        break;
    }
}
void Function::Menu()
{
    cout << "_________________________HANAFUO CINEMA_________________________" << endl
        << "                       1. Movie on today" << endl
        << "                       2. Movie now showing" << endl
        << "                       3. Movie coming soon" << endl
        << "                       4. Search movie " << endl
        << "                       5. View showtimes ( schedule )" << endl
        << "                       6. Book a ticket " << endl
        << "                       7. Log out " << endl
        << "                       PRESS THE NUMBER : ";
    int m;
    Account out;
    cin >> m;
    switch (m)
    {
    case 1:
        this->MenuTodayMovie();
        break;
    case 2:
        this->MenuMovieShowing();
        break;
       
    case 3:
        this->MenuMovieComing();
        break;
    case 4:
        this->MenuSearchMovie();
        break;
    case 5:
        this->MenuSchedule();
        break;
    case 6:
        this->MenuBooking();
        break;
    case 7:
        this->user_now = out;
        Authentication();
        break;
    default:
        cout << " Sorry,There is no matching option " << endl;
        break;
    }
}
void Function::Authentication()
{
    cout << "_________________________WELCOME TO HANAFUO CINEMA_________________________" << endl
        << "                          Do you have account ? " << endl
        << "                          1. Login " << endl
        << "                          2. Register " << endl
        << "                       PRESS THE NUMBER : ";
    int m;
    cin >> m;
    switch (m)
    {
    case 1:
        cout << "Login:" << endl;
        Validate();
        break;
    case 2:
        cout << "Register:" << endl;
        this->acc.Init();
        this->user.setAccount();
        this->acc.Insert(user);
        cout << "Login:" << endl;
        Validate();
        break;
    default:
        cout << " Sorry,There is no matching option " << endl;
        break;
    }
}
void Function::Validate()
{
        Login:
        int validate = 0;
        char ch;
        while (!validate)
        {
            string username;
            cout << "Username : ";
            cin >> username;
            this->acc.Init();
            int stt = this->acc.SearchName(username);
            if ((this->acc.SearchName(username)) == -1)
            {
                cout << "Khong tim thay tai khoan ! " << endl;
                cout << "Xin moi nhap lai !" << endl;
                continue;
            }
            else
            {
                validate = 1;
                string pwd;
                Password:
                cout <<  "Pass : ";
                for (char c; c = _getch(); )
                {
                    if (c == 13 || c == '\r') // enter 
                    {
                        cout << "\n";
                        break;
                    }
                    else
                    {
                        if (c == 8) // backspace
                        {
                            if (!pwd.empty())
                            {
                                pwd.erase(pwd.size() - 1);
                                cout << "\b \b";
                            }
                        }
                        else {
                            if (c == -32 ) // phim mui ten
                            {
                                _getch();
                            }
                            else {
                                if (isprint(c))
                                {
                                    cout << '*';
                                    pwd += c;
                                }
                            }
                        }
                    }
                }
                char* password = const_cast<char*>(pwd.c_str());
                if (this->acc.checkPwd(stt) == pwd)
                {
                    
                    cout << "Login success! Press Enter to continute !" << endl;
                    validate = 1;
                    _getch();
                    system("cls");
                }
                else
                {
                    cout << "Sai mat khau ! Moi nhap lai " << endl;
                    pwd = "";
                    goto Password;
                }
            }
            this->user_now = this->acc.getAccount(stt);
            this->acc.Close();
        }
}
void Function::MenuTodayMovie()
{
    cout << "You chose All Movie" << endl;
    this->mv.Init();
    this->mv.Show(5);
    this->mv.Close();
}
void Function::MenuMovieShowing()
{
    cout << "You chose Movie Showing" << endl;
    this->mv.Init();
    this->mv.Show(2);
    this->mv.Close();
}
void Function::MenuMovieComing()
{
    cout << "You chose Movie Coming Soon" << endl;
    this->mv.Init();
    this->mv.Show(3);
    this->mv.Close();
}
void Function::MenuSearchMovie()
{
    this->mv.Init();
    this->mv.Show(4);
    this->mv.Close();
}
void Function::MenuSchedule()
{
    cout << "You choose Schedule";
}
void Function::MenuBooking()
{}
void Function::MenuAdAccount()
{

    cout << "_________________________ACCOUNT_________________________" << endl
        << "                       1. Show All Account" << endl
        << "                       2. New Account " << endl
        << "                       3. Update Account " << endl
        << "                       4. Delete Account" << endl
        << "                       5. Back to menu before" << endl
        << "                       PRESS THE NUMBER : ";
    int m;
    Account out;
    cin >> m;
    switch (m)
    {
    case 1:
        this->acc.Init();
        this->acc.Show();
        this->acc.Close();
        break;
    case 2:
        this->acc.Init();
        this->user.setAccount();
        this->acc.Insert(user);
        this->acc.Show();
        this->acc.Close();
        break;
    case 3:
        this->acc.Init();
        this->acc.Update();
        this->acc.Close();
        break;
    case 4:
        this->acc.Delete();
        break;
    case 5:
        MenuAdmin();
        break;
    default:
        cout << " Sorry,There is no matching option " << endl;
        break;
    }
}
void Function::MenuAdRoom() {
    cout << "_________________________ROOM_________________________" << endl
        << "                       1. Show Room" << endl
        << "                       2. New Room " << endl
        << "                       3. Update Room " << endl
        << "                       4. Delete Room" << endl
        << "                       5. Back to menu before" << endl
        << "                       PRESS THE NUMBER : ";
    int m;
    Account out;
    int room;
    cin >> m;
    switch (m)
    {
    case 1:
        this->room.Init();
        cout << "Nhap room muon hien thi : ";
        cin >> room;
        this->room.Show();
        this->room.Close();
        break;
    case 2:
        this->room.Init();
        this->room.Insert();
        this->room.Show();
        this->room.Close();
        break;
    case 3:
        this->room.Init();
        this->room.Update();
        this->room.Close();
        break;
    case 4:
        this->room.Delete();
        break;
    case 5:
        MenuAdmin();
        break;
    default:
        cout << " Sorry,There is no matching option " << endl;
        break;
    }
}
void Function::MenuAdSeat() {
    cout << "_________________________SEAT_________________________" << endl
        << "                       1. Show Seat of Room" << endl
        << "                       2. New Seat " << endl
        << "                       3. Update Seat " << endl
        << "                       4. Delete Seat" << endl
        << "                       5. Back to menu before" << endl
        << "                       PRESS THE NUMBER : ";
    int m;
    Account out;
    int room;
    cin >> m;
    switch (m)
    {
    case 1:
        this->seat.Init();
        cout << "Nhap room muon hien thi seat: ";
        cin >> room;
        this->seat.Show(room);
        this->seat.Close();
        break;
    case 2:
        this->seat.Init();
        this->seat.Insert();
        this->seat.Show(1);
        this->seat.Close();
        break;
    case 3:
        this->seat.Init();
        this->seat.Update();
        this->seat.Close();
        break;
    case 4:
        this->seat.Delete();
        break;
    case 5:
        MenuAdmin();
        break;
    default:
        cout << " Sorry,There is no matching option " << endl;
        break;
    }
}
void Function::MenuAdMovie() {


    cout << "_________________________Movie_________________________" << endl
        << "                       1. Show all Movie" << endl
        << "                       2. Show today Movie" << endl
        << "                       3. Show showing Movie" << endl
        << "                       4. Show coming Movie" << endl
        << "                       5. New movie " << endl
        << "                       6. Update movie " << endl
        << "                       7. Delete movie" << endl
        << "                       8. Back to menu before" << endl
        << "                       PRESS THE NUMBER : ";
    int m;
    int stt_mv;
    cin >> m;
    switch (m)
    {
    case 1:
        this->mv.Init();
        this->mv.Show(1);
        this->mv.Close();
        break;
    case 2:
        this->mv.Init();
        this->mv.Show(5);
        this->mv.Close();
        break;
    case 3:
        this->mv.Init();
        this->mv.Show(2);
        this->mv.Close();
        break;
    case 4:
        this->mv.Init();
        this->mv.Show(3);
        this->mv.Close();
        break;
    case 5:
        this->mv.Init();
        this->mv.Insert();
        this->mv.Show(1);
        this->mv.Close();
        break;
    case 6:
        this->mv.Init();
        this->mv.Show(1);
        cout << "Nhap stt phim can update : ";
        cin >> stt_mv;
        this->MenuUpdateMovie(stt_mv-1);
        break;
    case 7:
        this->mv.Delete();
        break;
    case 8:
        MenuAdmin();
        break;

    default:
        cout << " Sorry,There is no matching option " << endl;
        break;
    }
}
void Function::MenuUpdateMovie(int stt)
{
    char key= 'y';
    do {
        cout << "_________________________Update Movie_________________________" << endl
            << "                       1. Movie name" << endl
            << "                       2. movie description" << endl
            << "                       3. movie release" << endl
            << "                       4. movie length" << endl
            << "                       5. movie genre " << endl
            << "                       PRESS THE NUMBER : ";
        int m;
        cin >> m;
        switch (m)
        {
        case 1:
            this->mv.getMovie(stt).Show();
            this->mv.Update(this->mv.getMovie(stt).getMovieID(), 1);
            this->mv.getMovie(stt).Show();
            break;
        case 2:
            this->mv.getMovie(stt).Show();
            this->mv.Update(this->mv.getMovie(stt).getMovieID(), 2);
            this->mv.getMovie(stt).Show();
            break;
        case 3:
            this->mv.getMovie(stt).Show();
            this->mv.Update(this->mv.getMovie(stt).getMovieID(), 3);
            this->mv.getMovie(stt).Show();
            break;
        case 4:
            this->mv.getMovie(stt).Show();
            this->mv.Update(this->mv.getMovie(stt).getMovieID(), 4);
            this->mv.getMovie(stt).Show();
            break;
        case 5:
            this->mv.getMovie(stt).Show();
            this->mv.Update(this->mv.getMovie(stt).getMovieID(), 5);
            this->mv.getMovie(stt).Show();
            break;

        default:
            cout << " Sorry,There is no matching option " << endl;
            break;
        }
        this->mv.getMovie(stt).Show();
        cout << "Do you want to be continute? y/n ";
        cin >> key;
        
    } while (key != 'n');
    MenuAdmin();
}
void Function::MenuAdSeatType(){}
void Function::MenuAdBooking(){}
void Function::MenuAdSchedule(){}

Account Function::getUserNow()
{
    return this->user_now;
}
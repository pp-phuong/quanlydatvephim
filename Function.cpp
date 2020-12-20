#include "Function.h"
Function::Function() {
}
Function::~Function() {
}
void Function::MenuAdmin()
{
    cout << "_________________________HANAFUO CINEMA_________________________" << endl
        << "                       1. MOVIE" << endl
        << "                       2. SCHEDULE " << endl
        << "                       3. BOOKING " << endl
        << "                       4. ACCOUNT" << endl
        << "                       5. INSERT ACCOUNT " << endl
        << "                       6. INSERT MOVIE " << endl
        << "                       7. SEARCH MOVIE " << endl
        << "                       8. ID USER " << endl
        << "                       9. Log out " << endl
        << "                       PRESS THE NUMBER : ";
    int m;
    cin >> m;
    switch (m)
    {
    case 1:
        this->MenuAllMovie();
        break;
    case 2:
        cout << "You chose SCHEDULE" << endl;
        break;
    case 3:
        cout << "You chose BOOKING" << endl;
        break;
    case 4:
        this->MenuAccount();
        break;
    case 5:
        cout << "You chose INSERT ACCOUNT " << endl;
        this->acc.Init();
        this->account.setAccount();
        this->acc.Insert(account);
        this->acc.Close();
        break;
    case 6:
        cout << "You chose INSERT MOVIE " << endl;
        this->mv.Init();
        this->mv.Insert();
        this->mv.Close();
        break;
    case 7:
        cout << "You chose SEARCH MOVIE " << endl;
        cout << "Nhap ma phim can tim kiem :";
        cin >> search;
        this->mv.Init();
        cout << mv.Search(search);
        this->mv.Close();
        break;
    case 8:
        cout << "id : " << this->user_now  ;
        break;
    case 9:
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
        << "                       1. View all movies" << endl
        << "                       2. Movie now showing" << endl
        << "                       3. Movie coming soon" << endl
        << "                       4. Search movie " << endl
        << "                       5. View showtimes ( schedule )" << endl
        << "                       6. Book a ticket " << endl
        << "                       7. Log out " << endl
        << "                       PRESS THE NUMBER : ";
    int m;
    cin >> m;
    switch (m)
    {
    case 1:
        this->MenuAllMovie();
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
void Function::MenuAllMovie()
{
    cout << "You chose All Movie" << endl;
    this->mv.Init();
    this->mv.Show(1);
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
    cout << "You chose SEARCH MOVIE " << endl;
    cout << "Nhap ma phim can tim kiem :";
    cin >> search;
    this->mv.Init();
    cout << mv.Search(search);
    this->mv.Close();
}
void Function::MenuSchedule()
{
    cout << "You choose Schedule";
}
void Function::MenuBooking()
{}
void Function::MenuAccount()
{
    cout << "You chose ACCOUNT" << endl;
    this->acc.Init();
    this->acc.Show();
    this->acc.Close();
}
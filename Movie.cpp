#include "Movie.h"
Movie::Movie()
{
}
Movie::Movie(int id, char* name, char* description, char* release, int length, char* genre)
	:movie_id(id), movie_length(length)
{
	strcpy_s(this->movie_name, 50, name);
	strcpy_s(this->movie_description, 160, description);
	strcpy_s(this->movie_release, 15, release);
	strcpy_s(this->movie_genre, 50, genre);

}
Movie::~Movie() {
}
int Movie::getMovieID() {
	return this->movie_id;
}
char* Movie::getMovieName() {
	return this->movie_name;
}
char* Movie::getMovieDescription() {
	return this->movie_description;
}
void Movie::setMovie()
{
	cout << "Movie ID:";
	cin >> movie_id;
	cin.ignore();
	cout << "Movie name: ";
	cin.getline(this->movie_name,50);
	cout << "Movie description:";
	cin.getline(this->movie_description, 160);
	cout << "Movie release:";
	cin.getline(this->movie_release, 15);
	cout << "Movie length";
	cin >> movie_length;
	cin.ignore();
	cout << "Movie genre:";
	cin.getline(this->movie_genre, 50);
}
string Movie::insertQuery()
{
	string t_query;
	string t_movie_id = to_string(movie_id);
	string t_movie_name(movie_name);
	string t_movie_description(movie_description);
	string t_movie_release(movie_release);
	string t_movie_length = to_string(movie_length);
	string t_movie_genres(movie_genre);
	t_query = t_movie_id + "','" + t_movie_name + "','" + t_movie_description + "','" +  t_movie_length + "','" + t_movie_genres + "','" +  t_movie_release + "')";
	return t_query;
}
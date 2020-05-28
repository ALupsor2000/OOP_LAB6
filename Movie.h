#pragma once

#include "Library.cpp"

class Movie
{
private:

	string title, genre, year, likes, link;

public:

	//Default constructor
	Movie();

	//Constructor film
	Movie(string title, string genre, string year, string likes, string link);

	//Functie care returneaza titlul
	string getTitle();

	//Procedura care seteaza titlul
	void setTitle(string title);

	//Functie care returneaza genul
	string getGenre();

	//Procedura care seteaza genul
	void setGenre(string genre);

	//Functie care returneaza anul filmului
	string getYear();

	//Procedura care seteaza anul
	void setYear(int year);

	//Functie care returneaza ratingul
	string getLikes();

	//Procedura care seteaza ratingul
	void setLikes(int likes);

	//Functia care returneaza linkul trailerului
	string getTrailer();

	//Procedura care seteaza linkul trailerul
	void setTrailer(string link);
};


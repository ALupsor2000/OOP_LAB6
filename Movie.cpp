#include "Movie.h"

Movie::Movie() = default;

Movie::Movie(string title, string genre, string year, string likes, string link)
{
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->link = link;
}

string Movie::getTitle()
{
	return title;
}

void Movie::setTitle(string title)
{
	this->title = title;
}


string Movie::getGenre()
{
	return genre;
}

void Movie::setGenre(string genre)
{
	this->genre = genre;
}

string Movie::getYear()
{
	return year;
}

void Movie::setYear(int year)
{
	this->year = year;
}

string Movie::getLikes()
{
	return likes;
}

void Movie::setLikes(int likes)
{
	this->likes = likes;
}

string Movie::getTrailer()
{
	return link;
}

void Movie::setTrailer(string link)
{
	this->link = link;
}
#pragma once

#include "Movie.h"

class AdminRepo
{
public:

	// Default constructor 
	AdminRepo();

	// Creeaza fisierul text primind ca parametru un film m
	void create_csv(Movie m);

	// Afiseaza in consola continutul fisierului text
	void read_csv();

	// Deschide cu ajutorul lui notepad fisierul text
	void open_csv();

	// Actualizeaza una dintre valorile unui film dat de la tastatura
	void update_csv();

	// Sterge un film din fisierul text
	void delete_csv();

	// Cauta  un film dupa genul dat ca parametru
	// In cazul in care exista filme de acest gen vor fi afisate pe ecran si functia va returna 1
	// In caz contrar se va afisa intreg continutul fisierului text si functia va returna 0
	int search_genre(string genre);

	// Preia linkul filmului dat ca parametru din fisier
	string getLink(string title);
};


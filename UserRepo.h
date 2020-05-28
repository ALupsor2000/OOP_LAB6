#pragma once

#include "Movie.h"

class UserRepo
{
public:

	UserRepo();

	void create_csv(string l1, string l2);

	// Afiseaza in consola continutul fisierului text
	void read_csv();

	// Deschide cu ajutorul lui notepad fisierul text
	void open_csv();

	// Incrementare numar lik-uri pentru filmul care urmeaza sa fie sters
	void update_csv(string title);

	// Sterge un film din fisierul text
	int delete_csv();
};


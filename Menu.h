#pragma once

#include "AdminRepo.h";
#include "UserRepo.h";

class Menu
{
	friend class AdminRepo;
	friend class UserRepo;

private:

	AdminRepo adminRepo;
	UserRepo userRepo;

public:

	// Constructor
	Menu();

	// Porneste aplicatia
	void startMenu();
};


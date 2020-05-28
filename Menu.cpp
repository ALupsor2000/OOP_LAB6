#include "Menu.h"

Menu::Menu()
{
	this->adminRepo = AdminRepo();
	this->userRepo = UserRepo();
}

void Menu::startMenu()
{
	bool run = true;

	while (run)
	{
		int mode;
		cout << "1.Administrator mode   2.User mode   3.Exit" << endl;
		cout << "Choose your mode: ";
		cin >> mode;
		if (mode == 1)
		{
			int adminMode = 0;
			while (adminMode != 6)
			{
				cout << "Bun venit in modul administrator! Alegeti ce doriti sa efectuati" << endl;
				cout << "1. Adaugare film nou" << endl;
				cout << "2. Stergere film" << endl;
				cout << "3. Actualizare film" << endl;
				cout << "4. Afisare lista filme" << endl;
				cout << "5. Deschidere fisier" << endl;
				cout << "6. Exit" << endl;
				cout << "Introduceti optiunea: " << endl;
				cin >> adminMode;
				if (adminMode == 1)
				{
					// Preiau atributele filmului
					string title, genre, year, likes, link, blank;
					cout << "Type title: ";
					getline(cin, blank);
					getline(cin, title);
					cout << "Type genre: ";
					getline(cin, genre);
					cout << "Type year: ";
					cin >> year;
					cout << "Type likes: ";
					cin >> likes;
					cout << "Type trailer link: ";
					getline(cin, blank);
					getline(cin, link);

					// Introduc in fisierul administratorului
					Movie m(title, genre, year, likes, link);
					adminRepo.create_csv(m);
				}
				else if (adminMode == 2)
				{
					adminRepo.delete_csv();
				}
				else if (adminMode == 3)
				{
					adminRepo.update_csv();
				}
				else if (adminMode == 4)
				{
					adminRepo.read_csv();
				}
				else if (adminMode == 5)
				{
					adminRepo.open_csv();
				}
				else if (adminMode == 6)
				{
					break;
				}
				else
				{
					cout << "Alegere invalida.";
				}
			}
		}
		else if (mode == 2)
		{
			int userMode= 0;
			while (userMode != 5)
			{
				cout << "Bun venit in modul utilizator! Alegeti ce doriti sa efectuati" << endl;
				cout << "1. Vizualizare film dupa gen" << endl;
				cout << "2. Adaugare film dupa titlu" << endl;
				cout << "3. Stergere film" << endl;
				cout << "4. Afisare lista filme" << endl;
				cout << "5. Deschidere fisier" << endl;
				cout << "6. Exit" << endl;
				cout << "Introduceti optiunea: ";
				cin >> userMode;
				if (userMode == 1)
				{
					string genre, link, line;
					int adaugare, continuare;
					fstream fin;

					cout << "Introduceti genul: ";
					cin >> genre;

					if (adminRepo.search_genre(genre) == 0)
					{
						fin.open("AdminRepo.txt", ios::in);

						while (!fin.eof())
						{
							getline(fin, line);
							cout << line << endl;
							cout << endl;
							getline(fin, link);

							// Readau filmul in browser
							system(std::string("start " + link).c_str());
							
							cout << "Doriti sa adaugati acest film in biblioteca personala?" << endl;
							cout << "Introduceti: 1->DA     2-> NU" << endl;
							cin >> adaugare;
							if (adaugare == 1)
							{
								// Adaugare film in biblioteca personala
								userRepo.create_csv(line, link);
								cout << "Film adaugat cu succes in biblioteca proprie." << endl;

								cout << "Continuati sa redati urmatorul trailer?" << endl;
								cout << "Introduceti: 1->DA     2->NU" << endl;
								cin >> continuare;
								if (continuare == 2)
								{
									break;
								}
							}
							else
							{
								cout << "Continuati sa redati urmatorul trailer?" << endl;
								cout << "Introduceti: 1->DA     2->NU" << endl;
								cin >> continuare;
								if (continuare == 2)
								{
									break;
								}
							}
						}
					}
				}
				else if (userMode == 2)
				{
					string title, blank, line, l1, l2;
					fstream fin;
					int pos;
					bool exista;
					cout << "Ce film doriti sa adaugati in biblioteca dumneavoastra: ";
					getline(cin, blank);
					getline(cin, title);

					fin.open("AdminRepo.txt", ios::in);

					// Verific daca filmul exista si salvez cele doua linii care ii apartin 
					exista = false;
					while (!fin.eof())
					{
					
						getline(fin, line);
						pos = line.find(title);
						if (pos != string::npos)
						{
							l1 = line;
							getline(fin, line);
							l2 = line;
							exista = true;
						}
					}

					// Daca s-a gasit filmul se aduaga in Watchlist
					if (exista)
					{
						userRepo.create_csv(l1, l2);
						cout << "Film adaugat cu succes in biblioteca proprie." << endl;
					}
				}
				else if (userMode == 3)
				{
					userRepo.delete_csv();
				}
				else if (userMode == 4)
				{
					userRepo.read_csv();
				}
				else if (userMode == 5)
				{
					userRepo.open_csv();
				}
				else if (userMode == 6)
				{
					break;
				}
				else
				{
					cout << "Alegere invalida";
				}
			}
		}
		else if (mode == 3)
		{
			run = false;
		}
		else
		{
			cout << "Alegere invalida. Tastati din nou cu atentie" << endl;
		}
	}
}

int main()
{
	Menu menu = Menu();
	
	menu.startMenu();
	
	/*
	string title, link;
	cin >> title;

	AdminRepo a;
	link = a.getLink(title);

	cout << link;
	system(std::string("start " + link).c_str());
	*/
	return 0;
}


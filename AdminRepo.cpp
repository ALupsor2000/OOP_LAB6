#include "AdminRepo.h"

AdminRepo::AdminRepo() = default;

void AdminRepo::create_csv(Movie m)
{
	fstream fout;
	
	fout.open("AdminRepo.txt", ios::out | ios::app);

	fout << m.getTitle() << ", "
		<< m.getGenre() << ", "
		<< m.getYear() << ", "
		<< m.getLikes() << "\n";

	fout << m.getTrailer() << "\n";
}

void AdminRepo::read_csv()
{
	fstream fin;
	vector<string> lines;
	fin.open("AdminRepo.txt", ios::in);

	string line;
	while (getline(fin, line))
		lines.push_back(line);

	for (size_t i = 0; i < lines.size(); ++i)
		cout << lines[i] << '\n';

	fin.close();
}

void AdminRepo::open_csv()
{
	system("notepad.exe AdminRepo.txt");
}

void AdminRepo::update_csv()
{
	fstream fin, fout;
	char atr;
	int i, pos, index = 0;
	string title, new_atr, line, update_line, link_line, str, blank;
	vector<string> row;
	bool exista;

	// Deschid fisierele pentru citire sau scriere
	fin.open("AdminRepo.txt", ios::in);
	fout.open("AdminRepoCopy.txt", ios::out);

	// Titlu filmului care urmeaza sa fie actualizat
	cout << "Introduceti numele filmului de actualizat: ";
	getline(cin, blank);
	getline(cin, title);

	// Parcurg tot fisierul si introduc doar linia care contine titlul introdus mai sus
	row.clear();
	exista = false;
	while (getline(fin, line))
	{
		if (!line.find(title))
		{
			update_line = line;
			getline(fin, line);
			link_line = line;
			exista = true;
		}
	}

	// Daca nu se gasaeste acest film, functia se opreste din executie
	if (!exista)
	{
		cout << "Nu s-a gasit acest film !!!";
		exit(0);
	}

	// Atributul care trebuie sa fie actualizat 
	cout << "T = titlu,  G = gen,  Y = An,  L = Numar Like, H = Adresa URL" << endl;
	cout << "Alegeti ce doriti sa actualizati: ";
	cin >> atr;

	// Determinam indexul atributului in vector
	if (atr == 't' || atr == 'T')
		index = 0;
	else if (atr == 'g' || atr == 'G')
		index = 1;
	else if (atr == 'y' || atr == 'Y')
		index = 2;
	else if (atr == 'l' || atr == 'L')
		index = 3;
	else if (atr == 'h' || atr == 'H')
		index = 4;
	else
	{
		cout << "Alegere invalida. Va rugam sa inceracti din nou\n";
		exit(0);
	}

	cout << "Introduceti atributul nou: ";
	getline(cin, blank);
	getline(cin, new_atr);

	// Adaug fiecare atribut pe cate o pozitie in vectorul row
	for (i = 0; i < 3; i++)
	{
		pos = update_line.find(',');
		row.push_back(update_line.substr(0, pos));
		update_line.erase(0, pos + 2);
	}

	// Adaug ultimul atribut si linkul respectivului film
	row.push_back(update_line);
	row.push_back(link_line);
	
	// Modific atributul
	row[index] = new_atr;

	// Copiez in fisierul nou filmul cu valorile actualizate
	fout << row[0] << ", " << row[1] << ", " << row[2] << ", " << row[3] << "\n";
	fout << row[4] << "\n";

	fin.close();
	fin.open("AdminRepo.txt", ios::in);

	// Scriu restul filmelor inapoi in fisierul original
	while(!fin.eof())
	{
		getline(fin, line);
		if (line.find(title))
		{
			fout << line << endl;
			getline(fin, line);
			fout << line << endl;
		}
		else
			getline(fin, line);
	}

	fin.close();
	fout.close();

	// Schimb numele fisierului care contine actualizarile inapoi in numele initial
	remove("AdminRepo.txt");
	rename("AdminRepoCopy.txt", "AdminRepo.txt");
}

void AdminRepo::delete_csv()
{
	fstream fin, fout;
	string title, line, blank;
	vector<string> row;
	bool exista;

	// Deschid fisierele pentru a fi prelucrate
	fin.open("AdminRepo.txt", ios::in);
	fout.open("AdminRepoCopy.txt", ios::out);

	cout << "Introduceti titlul filmului pe care doriti sa il stergeti: ";
	getline(cin, blank);
	getline(cin, title);

	// Verific daca exista fimul in AdminRepo.txt
	exista = false;
	while (!fin.eof())
	{
		getline(fin, line);
		if (!line.find(title))
			exista = true;
	}

	fin.close();

	while (!exista)
	{
		cout << "Titlul introdus nu exista sau a fost deja sters !!!" << endl;
		break;
	}

	fin.open("AdminRepo.txt", ios::in);

	// Scriu in vector filmele care raman 
	while (!fin.eof())
	{
		getline(fin, line);
		if (line.find(title))
		{
			row.push_back(line);
			getline(fin, line);
			row.push_back(line);
		}
		else
			getline(fin, line);
	}

	fin.close();

	for(int i = 0; i < row.size(); i++)
	{
		fout << row[i] << "\n";
	}
	
	fout.close();

	// Schimb numele fisierului care contine actualizarile inapoi in numele initial
	remove("AdminRepo.txt");
	rename("AdminRepoCopy.txt", "AdminRepo.txt");
}

int AdminRepo::search_genre(string genre)
{
	fstream fin;
	string line;
	vector<string> row;
	size_t pos;

	fin.open("AdminRepo.txt", ios::in);

	while (!fin.eof())
	{
		getline(fin, line);
		pos = line.find(genre);
		if (pos != string::npos)
		{
			row.push_back(line);
			getline(fin, line);
			row.push_back(line);
		}
	}

	if (row.size() == 0)
	{
		cout << "Nu s-a gasit acest gen. Continutul bibliotecii de filme este:" << endl;
		return 0;
	}
	else
	{
		cout << "Filmele care contin acest gen: " << endl;
		for (int i = 0; i < row.size(); i++)
		{
			cout << row[i] << endl;
		}
		return 1;
	}
}

string AdminRepo::getLink(string title)
{
	fstream fin;
	string line;
	size_t pos;

	fin.open("AdminRepo.txt", ios::in);

	while (!fin.eof())
	{
		getline(fin, line);
		pos = line.find(title);
		if (pos != string::npos)
		{
			getline(fin, line);
			return line;
		}
	}
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;

void line()
{
	cout << "\n\n-------------------------------------------------------------------------------\n\n";
}

// загрузка базы данных; 1 - открыто, 0 - ошибка 
int LoadingData(int* count, person_t** persons, int sizePerson)
{
	system("cls");

	FILE* file = fopen(".\\persons.data", "rb");

	char c;

	if (file == nullptr)
	{
		cout << "Data not found! Create data?(Y/N)" << endl;

		while (true)
		{
			c = _getch();

			if (c == 'Y' || c == 'y')
			{
				system("cls");

				file = fopen(".\\persons.data", "wb");

				if (file == nullptr)
				{
					cout << "Error create file!" << endl;

					cout << "\n\n\Exit" << endl;

					return 0;
				}

				cout << "Create File complete!" << endl;

				LoadingData(count, persons, sizePerson);

				return 1;
			}

			if (c == 'N' || c == 'n')
			{
				cout << "\n\nExit" << endl;

				return 0;
			}
		}



		return 0;
	}

	else
	{
		fseek(file, 0, SEEK_END);

		long size = ftell(file);

		fseek(file, 0, SEEK_SET);

		*count = size / sizePerson;

		*persons = new person_t[*count];

		fread(*persons, sizeof(person_t), *count, file);

		fclose(file);
	}

	return 1;
}

// добваление человека в базу 
int AddPerson(int* count, person_t** persons, int sizePerson)
{
	system("cls");

	line();

	cout << "ADD PERSON" << endl;
	
	line();

	person_t* new_person = new person_t;

	char c;

	bool flag = false;

	while (true)
	{
		system("cls");

		cout << "ID: ";
		cin.getline(new_person->id, 20);

		// проверка по базе данных
		for (person_t* person = *persons; person < *persons + *count; person++)
		{
			if (!strcmp(person->id, new_person->id))
			{
				cout << endl << endl;

				cout << "ERROR! Id is already in use! Re-enter? (Y/N): ";
				
				while (true)
				{
					c = _getch();

					if (c == 'Y' || c == 'y')
					{
						break;
					}

					if (c == 'N' || c == 'n')
					{
						cout << "\n\nExit" << endl;

						return 0;
					}
				}

				flag = true;

				break;
			}
		}


		if (flag)
		{
			flag = false;
			return 0;
		}
		cout << "Name: ";
		cin.getline(new_person->name, 20);

		cout << "Surname: ";
		cin.getline(new_person->surname, 20);

		cout << "Patronymic: ";
		cin.getline(new_person->patron, 20);

		cout << "Number: ";
		cin.getline(new_person->number, 20);

		cout << "Position: ";
		cin.getline(new_person->position, 20);

		cout << "Name Department: ";
		cin.getline(new_person->nameDep, 20);

		cout << "Salary: ";
		cin.getline(new_person->salary, 20);

		cout << "Date: ";
		cin.getline(new_person->date, 20);

		break;
	}

	FILE* file = fopen(".\\persons.data", "rb+");

	if (file == nullptr)
	{
		cout << "ERROR OPEN FILE \"person.data\"" << endl;

		return 0;
	}

	fseek(file, 0, SEEK_END);

	fwrite(new_person, sizeof(person_t), 1, file);

	fclose(file);

	delete new_person;

	LoadingData(count, persons, sizePerson);

	return 1;
}

// удаление человека из базы данных
int DeletePerson(int* count, person_t** persons, int sizePerson, char* id)
{
	line();

	cout << "DELETE PERSON" << endl;

	line();

	FILE* file = fopen(".\\persons.data", "wb");

	if (file == nullptr)
	{
		cout << "ERROR OPEN FILE \"person.data\"" << endl;

		return 0;
	}

	bool flag = false;

	for (person_t* person = *persons; person < *persons + *count; person++)
	{
		if (!strcmp(person->id, id))
		{
			flag = true;

			continue;
		}

		fwrite(person, sizeof(person_t), 1, file);
	}

	fclose(file);

	LoadingData(count, persons, sizePerson);

	if (flag)
	{
		cout << "DELETE COMPLETE" << endl;
	}

	else
	{
		cout << "NOR FOUND PERSON" << endl;
	}
	pressAnyKey();

	return 1;
}

// поиск человека в базе данеых
int SearchPerson(int* count, person_t** persons, int sizePerson)
{
	line();

	cout << "SEARCH PERSON" << endl;

	line();

	char c;

	person_t* new_person = new person_t;

	while (true)
	{
		system("cls");

		cout << "Search of: FIO(1), Salary(2), Position(3), Department(4), Exit(ESC): ";

		while (true)
		{
			c = _getch();

			if (c > '0' && c < '5')
			{
				line();

				cout << "SEARCH PERSON" << endl;

				line();

				// поиск по имени
				if (c == '1')
				{
					cin.ignore();
					cout << "Name: ";
					cin.getline(new_person->name, 20);

					cout << "Surname: ";
					cin.getline(new_person->surname, 20);

					cout << "Patronimyc: ";
					cin.getline(new_person->patron, 20);
				}

				// поиск по окладу
				if (c == '2')
				{
					cout << "Salary: ";
					cin.getline(new_person->salary, 20);
				}

				// поиск по должности
				if (c == '3')
				{
					cout << "Position: ";
					cin.getline(new_person->position, 20);
				}

				// поиск по одному отделу 
				if (c == '4')
				{
					cout << "Name Department: ";
					cin.getline(new_person->nameDep, 20);
				}

				system("cls");

				line();

				cout << "SEARCH PERSON" << endl;

				line();


				for (person_t* person = *persons; person < *persons + *count; person++)
				{
					if ((c == '1' && !strcmp(person->name, new_person->name) &&
						!strcmp(person->surname, new_person->surname) &&
						!strcmp(person->patron, new_person->patron)) ||
						(c == '2' && !strcmp(person->salary, new_person->salary)) ||
						(c == '3' && !strcmp(person->position, new_person->position)) ||
						(c == '4' && !strcmp(person->nameDep, new_person->nameDep)))
					{
						cout << "ID: " << person->id << endl;

						cout << "Name: " << person->name << endl;

						cout << "Surname: " << person->surname << endl;

						cout << "Patronymic: " << person->patron << endl;

						cout << "Number: " << person->number << endl;

						cout << "Position: " << person->position << endl;

						cout << "Name Department: " << person->nameDep << endl;

						cout << "Salary: " << person->salary << endl;

						cout << "Date: " << person->date << endl;

						cout << endl << endl;;
					}
				}

				pressAnyKey();

				delete new_person;

				return 1;
			}

			if (c == 27)
			{
				delete new_person;

				return 1;
			}

			system("cls");

			line();

			cout << "SEARCH PERSON" << endl;

			line();

			cout << "NOT FOUND!" << endl;

			pressAnyKey();

			system("cls");

			break;
		}

	}
}

// просмотр всех сотрудников
void AllPersons(int* count, person_t** persons, int sizePerson)
{
	if (!LoadingData(count, persons, sizePerson) || *count == 0)
		return;

	char c;

	for (person_t* person = *persons; ; )
	{
		system("cls");

		line();

		cout << "ALL PERSONS" << endl;

		line();

		cout << "ID: " << person->id << endl;

		cout << "Name: " << person->name << endl;

		cout << "Surname: " << person->surname << endl;

		cout << "Patronymic: " << person->patron << endl;

		cout << "Number: " << person->number << endl;

		cout << "Position: " << person->position << endl;

		cout << "Name Department: " << person->nameDep << endl;

		cout << "Salary: " << person->salary << endl;

		cout << "Date: " << person->date << endl;

		cout << endl << endl;;

		cout << "\n\n\nPRESS: [1]LEFT, [2]RIGHT, [ESC]EXIT" << endl;

		while (true)
		{
			c = _getch();

			if (c == '1' && person != *persons)
			{
				person--;

				break;
			}

			else if (c == '2' && person < *persons + *count - 1)
			{
				person++;

				break;
			}

			else if (c == 27)
			{
				return;
			}
		}
	}

}

// изменение 
void EditPerson(int* count, person_t** persons, int sizePerson)
{
	line();

	cout << "EDIT PERSON" << endl;

	line();

	char id[20];

	bool flag = false;
	
	char c;

	while (true)
	{
		system("cls");

		cout << "Enter ID: ";

		cin.getline(id, 20);

		for (person_t* person = *persons; person < *persons + *count; person++)
		{

			if (!strcmp(person->id, id))
			{
				flag = true;

				system("cls");

				line();

				cout << "EDIT PERSON" << endl;

				line();

				char name[20];			// 0 - 19
				char surname[20];		// 20 - 39
				char patron[20];		// 40 - 59
				char number[20];		// 60 - 79
				char position[20];		// 80 - 99
				char nameDep[20];		// 100 - 119
				char salary[20];		// 120 - 139
				char date[20];			// 140 - 159
				char id[20];			// 160 - 179


				cout << "1. EDIT ID" << endl;
				cout << "2. EDIT SURNAME" << endl;
				cout << "3. EDIT NAME" << endl;
				cout << "4. EDIT PATRON" << endl;
				cout << "5. EDIT POSITION" << endl;
				cout << "6. EDIT NAME DEP" << endl;
				cout << "7. EDIT SALARY" << endl;
				cout << "8. DATE" << endl;

				while (true)
				{
					c = _getch();

					if (c == '1')
					{
						system("cls");

						cout << "ID: ";

						cin.getline(person->id, 20);
					}
					if (c == '2')
					{
						system("cls");

						cout << "ID: ";

						cin.getline(person->surname, 20);
					}
					if (c == '3')
					{
						system("cls");

						cout << "ID: ";

						cin.getline(person->name, 20);
					}
					if (c == '4')
					{
						system("cls");

						cout << "ID: ";

						cin.getline(person->patron, 20);
					}
					if (c == '5')
					{
						system("cls");

						cout << "ID: ";

						cin.getline(person->position, 20);
					}
					if (c == '6')
					{
						system("cls");

						cout << "ID: ";

						cin.getline(person->nameDep, 20);
					}
					if (c == '7')
					{
						system("cls");

						cout << "ID: ";

						cin.getline(person->salary, 20);
					}
					if (c == '8')
					{
						system("cls");

						cout << "ID: ";

						cin.getline(person->date, 20);
					}
					break;
				}
				
				FILE* file = fopen(".\\persons.data", "wb");


				for (person_t* person = *persons; person < *persons + *count; person++)
				{
					fwrite(person, sizeof(person_t), 1, file);
				}

				fclose(file);

				LoadingData(count, persons, sizePerson);

				return;
			}

		}

	}
}
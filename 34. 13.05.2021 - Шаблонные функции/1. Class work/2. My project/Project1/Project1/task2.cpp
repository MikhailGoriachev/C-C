#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;

void task2()
{
	// «адача 2 (5 баллов)

	// –азработать программу "ќтдел кадров", котора€ позвол€ет хранить следующую информацию о человеке :
	/*Х	номер
		Х	‘»ќ(им€)
		Х	дата рождени€
		Х	адрес
		Х	телефон
		Х	должность
		Х	название отдела
		Х	оклад
		Х	дата устройства на работу

		ѕрограмма должна использовать динамический массив структур дл€ хранени€ телефонной книги.ѕрограмма имеет меню, в котором есть следующие функции :
	Х	просмотр всех сотрудников
		Х	добавить сотрудника
		Х	удалить сотрудника
		Х	изменить сотрудника(помен€ть телефон, адрес, дату рождени€ и т.д.)
		Х	поиск по имени
		Х	поиск по окладу
		Х	поиск по должности
		Х	просмотр сотрудников одного отдела
		Х	загрузить / сохранить телефонную книгу в файл(в бинарном виде)
		Х	выход*/

	// указатель на структуру
	person_t** persons = new person_t*;

	int* count = new int;

	int sizePerson = sizeof(person_t);

	char c;

	bool f = false;

	bool f1 = false;

	// меню
	while (true)
	{
		LoadingData(count, persons, sizePerson);

		system("cls");

		line();

		cout << "MENU" << endl;

		line();

		cout << "1. ALL PERSONS" << endl;
		cout << "2. ADD PERSONS" << endl;
		cout << "3. DELETE PERSONS" << endl;
		cout << "4. SEARCH PERSONS" << endl;
		cout << "5. EDIT PERSONS" << endl;

		cout << "\n\n\n\nEXIT [ESC]" << endl;

		while (true)
		{
			c = _getch();

			//cin.ignore();

			if (c == '1')
			{
				AllPersons(count, persons, sizePerson);
			}

			else if (c == '2')
			{
				if (!f)
					cin.ignore();
				f = true;
				AddPerson(count, persons, sizePerson);
			}

			else if (c == '3')
			{
				char id[20];

				system("cls");

				line();

				cout << "DELETE PERSON" << endl;

				line();

				cout << "Enter ID: ";
				
				//if (f1)
					//cin.ignore();

				f1 = true;

				cin.getline(id, 20);

				

				DeletePerson(count, persons, sizePerson, id);
			}

			else if (c == '4')
			{
				SearchPerson(count, persons, sizePerson);
			}

			else if (c == '5')
			{
				EditPerson(count, persons, sizePerson);
			}

			break;
		}


	}


	pressAnyKey();
}
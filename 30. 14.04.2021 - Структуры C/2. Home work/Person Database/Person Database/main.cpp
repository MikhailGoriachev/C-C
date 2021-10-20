#include <iostream>
#include <conio.h>

#include "head.h"
using namespace std;

//  1. Разработать программу - базу данных о людях. О каждом человеке нужно хранить следующую информацию:
//		- номер паспорта
//		- ФИО
//		- профессия
//		- год рождения
//		- адрес
//		- зарплата

//	Программа имеет следующие функции :
//		- данные хранить в динамическом массиве структур
//		- пользовательское меню
//		- добавление человека
//		- удаление человека из БД
//		- просмотр всех людей
//		- редактирование записи
//		- поиск по адресу, ЗП
//		- сохр / загр в файл всех данных
//		- выход из программы
//

/////////////////////////////////////////////////////////////////////////
// структура файлов и папок программы
/// <summary>
/// ./Person Database 1.0/ - домашняя папка
/// ./Person Database 1.0/Security/ - папка безопасности
/// ./Person Database 1.0/Security/access.list - учётные записи
/// ./Person Database 1.0/Security/key.data - ключ шифрования
/// ./Person Database 1.0/Data/ - папка хранения базы данных
/// ./Person Database 1.0/Data/person.data - база данных людей
/// </summary>


void main()
{
	// длина ключа
	int* sizeKey = new int;
	*sizeKey = 63;

	// ключ шифрования
	key_t* key = new key_t;

	// ключ шифрования
	key->crypt = new char[*sizeKey];
	key->decrypt = new char[*sizeKey];

	// загрузка ключа шифрования
	if (LoadingKey(key, *sizeKey));

	// указатель на структуру учётных данных
	account_t** users = new account_t*;

	// количество аккаунтов
	int* countUsers = new int;

	// показатель принадлежности к группе администрации
	bool* adminFlag = new bool;

	*adminFlag = false;

	// вход в аккаунт
	if (!Login(users, countUsers, key, adminFlag))
		return;

	system("cls");

	// база данных людей
	person_t** persons = new person_t*;

	// количество людей в базе данных
	int* countPersons = new int;

	// длина данных одногго человека
	int* sizePerson = new int;

	*sizePerson = sizeof(person_t);

	// загрузка базы данных людей
	LoadingPersons(persons, countPersons, sizePerson, key, sizeKey);

	// символ меню
	char* c = new char;

	// меню
	while (true)
	{
		menu(c);

		// 1. LIST PERSON
		if (*c == '1')
		{
			ListPerson(persons, countPersons, sizePerson, key, sizeKey);
		}

		// 2. SEARCH PERSON
		else if (*c == '2')
		{
			SearchPerson(persons, countPersons, sizePerson, key, sizeKey);
		}

		// 3. ADD PERSON (ADMIN GROUP)
		else if (*c == '3')
		{
			// если пользователь не входит в группу администраторов
			if (!*adminFlag)
			{				
				system("cls");

				outLine();

				cout << "ADD PERSON" << endl;

				outLine();

				cout << "ACCESS IS DENIED! FOR ADMIN GROUP" << endl;

				pressAnyKey();

				continue;
			}
			AddPerson(persons, countPersons, sizePerson, key, sizeKey);
		}

		// 4. DELETE PERSON (ADMIN GROUP)
		else if (*c == '4')
		{
			// если пользователь не входит в группу администраторов
			if (!*adminFlag)
			{
				system("cls");

				outLine();

				cout << "ADD PERSON" << endl;

				outLine();

				cout << "ACCESS IS DENIED! FOR ADMIN GROUP" << endl;

				pressAnyKey();

				continue;
			}

			DeletePerson(persons, countPersons, sizePerson, key, sizeKey);
		}
		
		// 5. ACCOUNT MANAGEMENT (ADMIN GROUP)
		else if (*c == '5')
		{
			// если пользователь не входит в группу администраторов
			if (!*adminFlag)
			{
				system("cls");

				outLine();

				cout << "ADD PERSON" << endl;

				outLine();

				cout << "ACCESS IS DENIED! FOR ADMIN GROUP" << endl;

				pressAnyKey();

				continue;
			}

			// если был создан или удалён польозватель
			while (AccontManagement(users, countUsers, key, sizeKey))
			{
				LoadingAccess(users, countUsers, key);
			}
			


		}

		// 6. DATA ENCRYPTION (ADMIN GROUP)
		else if (*c == '6')
		{
			// если пользователь не входит в группу администраторов
			if (!*adminFlag)
			{
				system("cls");

				outLine();

				cout << "ADD PERSON" << endl;

				outLine();

				cout << "ACCESS IS DENIED! FOR ADMIN GROUP" << endl;

				pressAnyKey();

				continue;
			}


		}

		// [ESC] EXIT
		else if (*c == (char)27)
		{
			return;
		}
	}



}
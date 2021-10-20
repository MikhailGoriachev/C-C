#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>
#include <direct.h>

#include "head.h"
#include "struct.h"
using namespace std;

// структура словаря
cypher* sec = new cypher;

void main()
{
	// 1. Разработать программу - базу данных об автомобилях. О каждой машине нужно хранить следующую информацию:
	//  - номер машины(кл - 2345т или 1)
	//	- марка машины(BMW)
	//	- модель(m5)
	//	- ФИО владельца
	//	- год выпуска
	//	- цена
	//
	//	Программа имеет следующие функции :
	//  - данные хранить в динамическом массиве структур
	//	- пользовательское меню
	//	- добавление автомобилях
	//	- удаление автомобиля
	//	- просмотр всех автомобилей
	//	- редактирование автомобиля
	//	- поиск по цене
	//	- сохр / загр в файл всех данных
	//	- выход из программы

	// аутентификация если пароль будет введён неправильно более десяти раз,
	// то база файл с информации базы данных будет безопасно удалён многоразовым
	// затиранием(7 раз)

	line();

	cout << "CAR DATABASE 1.0" << endl;



	strcpy((*sec).cyp, "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890");
	strcpy((*sec).decyp, "qazwsxedcrfvtgbyhnujmikolpQAZWSXEDCRFVTGBYHNUJMIKOLP!@#$%^&*()");

	// аутентификация если пароль будет введён неправильно более десяти раз,
	// то база файл с информации базы данных будет удалён

	int* n = new int;

	// вызов функции
	*n = login();

	// если вход не выполнен
	if (*n == 0)
	{
		cout << "Exit" << endl;
		return;
	}

	// пароль был введён более десяти раз неверно
	if (*n == 2)
	{
		// удаление файла базы данных
		deleteFile(".\\Database\\save.base");

		return;
	}

	// если вход выполнен успешно

	// путь файла базы данных по умолчанию
	char* path_data = new char[_MAX_PATH];

	// путь к файлу базы дынных по умолчанию
	strcpy(path_data, ".\\Database\\save.base");

	// указатель на файл базы данных
	FILE* database = nullptr;

	// пользователь выбирает: открыть базу данных по умолчанию или 
	// ввести путь к файлу 
	cout << "Load new database? (Y/N): ";

	// переменная ввода одного символа
	char* key = new char[2];

	*(key + 1) = 0;

	// проверка ввода 
	while (true)
	{
		// ввод клавиши
		*key = _getch();

		if (!strcmp(key, "Y") || !strcmp(key, "y"))
		{
			// отчистка консоли
			system("cls");

			// вывод полосы
			line();

			cout << "----------------LOADING DATABASE---------------" << endl << endl;

			// ввод пути к файлу базы данных
			cout << "Enter path database: ";
			cin.getline(path_data, _MAX_PATH);

			cout << endl;

			// открытие файла базы данных в режиме бинарного чтения
			database = fopen(path_data, "rb");

			// если файл открыт успешно
			if (database != nullptr)
			{
				cout << "File uploaded complite!" << endl;

				// нажатие любой клавиши для продолжения
				pressAnyKey();

				// отчистка консоли
				system("cls");

				break;
			}
		}

		if (!strcmp(key, "N") || !strcmp(key, "n"))
		{
			break;
		}
	}

	// отчистка консоли
	system("cls");

	// вывод полосы
	line();

	// указатель на массив структур
	car_t* car = nullptr;

	// количество машин в базе
	unsigned int* count_car = nullptr;

	// загрузка базы данных
	loadData(path_data);


}
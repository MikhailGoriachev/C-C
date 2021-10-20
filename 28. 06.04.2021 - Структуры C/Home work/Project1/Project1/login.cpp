#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>
#include <direct.h>

#include "struct.h"
#include "head.h"

using namespace std;

extern cypher* sec;

account_data* user;

int* count_acc;

bool admin = false;

// аутентификация если пароль будет введён неправильно более десяти раз,
// то база файл с информации базы данных будет удалён

// проверка входа; возвращает: 0 - ошибка; 1 - вход выполнен; 2 - пароль введён неправильно
// более 10 раз;
int login()
{

	// файл аутентификации 
	char* path = new char[_MAX_PATH];

	// путь 
	strcpy(path, ".\\Authentication\\login.auth");

	// открытие файла аутентификации в режиме битного чтения
	FILE* file = fopen(path, "rb");

	// если файла не существует программа создаёт файл 
	// заполняет его учтёными данными записи root по умолчанию
	// и предлагает создатьпользователя
	if (file == nullptr)
	{
		// проверка на то, существует ли папка Authentication
		
		// список 
		_finddata_t list;

		// указатель на список и создание его
		long point = _findfirst(".\\Authentication", &list);

		// если не удалось найти папку
		if (point == -1)
		{
			// воздание папки "Authentication"
			if (_mkdir(".\\Authentication") == -1)
			{
				cout << "ERROR CREATE FOLDER \"Authentication\"" << endl;
				return 0;
			}
		}

		// создание файла login.auth и открытие в режиме бинарного чтения
		file = fopen(".\\Authentication\\login.auth", "wb");

		// если файла неуспешно открыт
		if (file == nullptr)
		{
			cout << "ERROR OPEN FILE \"login.auth\"" << endl;
			return 0;
		}

		// логин учётной записи admin
		char* login = new char[20];
		strcpy(login, "admin\0");

		// пароль учётной записи admin
		char* password = new char[20];
		strcpy(password, "123456\0");

		// запуск функции тихой регистрации
		if (!createAccount(login, password))
		{
			return 0;
		}

		// закрытие файла 
		fclose(file);

		// открытие файла в режиме бинарного чтения
		file = fopen(".\\Authentication\\login.auth", "rb");

		// отчистка памяти
		delete[] login, password;
	}

	// установка указателя в файле в конец
	fseek(file, 0, SEEK_END);

	// размер файла 
	size_t* size = new size_t;

	*size = ftell(file);

	// установка указателя в конец файла
	fseek(file, 0, SEEK_SET);

	// создание буфера для файла
	char* buffer = new char[*size];

	// считывание файла в буфер
	fread(buffer, sizeof(char), *size, file);

	// закрытие файла 
	fclose(file);

	// длина данных для логина и пароля всего: 40
	// login - 20 символов; максимум для ввода - 18
	// password - 20 символов; максимум для ввода - 18

	// расшифровка и заполение в структуру всех акаунтов

	// количество пользователей
	count_acc = new int;
	*count_acc = *size / 40;
	
	// отчистка памяти
	delete size;

	// массив структур по количеству пользователей
	user = new account_data[*count_acc];

	// указатель на буфер
	char* buf = buffer;


	// заполнение структуры
	for (account_data* us = user; us < user + *count_acc; us++, buf++)
	{
		// расшифровка и копирование имени в структуру
		strncpy((*us).login, buf, 20);
		
		// расшифровывание 
		decryption(*sec, (*us).login, 19);

		// смещение указателя в буфере
		buf += 19;

		// расшифровка и копирование пароля в структуру
		strncpy((*us).password, buf, 20);

		// расшифровывание 
		decryption(*sec, (*us).password, 19);

		// смещение указателя в буфере
		buf += 20;
	}

	// отчистка памяти
	delete[] buffer;

	// логин для ввода
	char* log = new char[20];

	// пароль для ввода
	char* password = new char[20];

	// счётчик 
	size_t* i = new size_t;


	for (*i = 0; *i < 10; ++*i)
	{
		// ввод логина 
		cout << "Enter login: ";
		cin.getline(log, 19);

		// ввод пароля
		cout << "Enter password: ";
		cin.getline(password, 19);

		cout << endl;

		// показатель того успешности входа
		bool* detect = new bool;
		*detect = false;

		// поиск логина и пароля в базе учётных записей
		for (account_data* us = user; us < user + *count_acc; us++)
		{
			// сравнение логина 
			if (!strcmp(log, (*us).login))
			{
				// сравнение пароля
				if (!strcmp(password, (*us).password))
				{
					// если данные совпали
					*detect = true;

					// если это админ
					if (!strcmp(log, "admin"))
					{
						admin = true;
					}

					// отчистка памяти
					delete[] path, user;

					return 1;
				}
			}
		}

		// если данные не совпали
		cout << "\n\n\n\n\nIncorrect login or password!" << endl;

		cout << "\n\n\nPRESS [ENTER] TO RE-LOGIN OR PRESS [ESC] TO EXIT" << endl;

		// переменная клавиши 
		char* n = new char;

		// символ esc 
		char* esc = new char;
		*esc = (char)27;

		// чтоб ввести ещё раз нужно нажать "Enter", чтоб выйти "Esc"
		while (true)
		{
			*n = _getch();

			if (strcmp(n, "\n"))
			{
				system("cls");

				line();

				break;
			}



			if (strcmp(n, esc))
			{
				system("cls");

				return 0;
			}
		}
	}
	
	system("cls");

	// если данные не совпали десять раз 
	return 2;
}
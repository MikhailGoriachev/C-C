#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;


// загрузка файла ./Person Database 1.0/Security/access.list - учётные записи
bool LoadingAccess(account_t** users, int* countUsers, key_t* key)
{
	// открытие файла access.list в режиме бинарного чтения
	FILE* file = fopen("./Security/access.list", "rb");

	// если файл открыт успешно
	if (file != nullptr)
	{
		// количество байт данных одного пользователя 
		int* sizeUser = new int;

		*sizeUser = 41;

		// установка указателя в конец файла
		fseek(file, 0, SEEK_END);

		// длина файла
		size_t* sizeFile = new size_t;

		*sizeFile = ftell(file);

		// количество пользователей
		*countUsers = *sizeFile / *sizeUser;

		// установка указателя в начало файла
		fseek(file, 0, SEEK_SET);

		// если длина файла без остатка делится на количество пользователей
		if (*sizeFile % *countUsers == 0)
		{
			// массив структур данных пользователей
			*users = new account_t[*countUsers];

			// считывание файла в струтуры
			for (account_t* user = *users; user < *users + *countUsers; user++)
			{
				fread(user, sizeof(char), *sizeUser, file);

				// дешифрование логина 
				CryptOrDecrypt(user->login, 20, key, 2, 63);
				
				// дешифрование пароля
				CryptOrDecrypt(user->password, 20, key, 2, 63);

				// дешифрование уровня доступа
				CryptOrDecrypt(user->accessLevel, 1, key, 2, 63);
			}

			// закрытие файла
			fclose(file);

			// отчистка памяти
			delete sizeUser, sizeFile;

			return true;
		}
		
		cout << "ERROR! BROKEN FILE \"access.list\"";

		// отчистка памяти
		delete sizeUser, sizeFile;

		return false;		
	}
	cout << "ERROR OPENING FILE \"access.list\"" << endl;

	pressAnyKey();

	return false;
}

// вход в учётную запись; 
bool Login(account_t** users, int* countUsers, key_t* key, bool* adminFlag)
{
	system("cls");

	outLine();

	cout << "LOGIN" << endl;

	outLine();

	// загрузка учётных данных пользователей из файла access.list
	if (!LoadingAccess(users, countUsers, key))
	{
		return false;
	}

	// логин
	char* login = new char[20];

	// пароль
	char* password = new char[20];

	// ввод логина и пароля
	while (true)
	{
		system("cls");

		outLine();

		cout << "LOGIN" << endl;

		outLine();

		// ввод логина 
		cout << "Login: ";
		cin.getline(login, 20);

		// ввод пароля
		cout << "Password: "; 
		cin.getline(password, 20);

		// проверка логина и пароля по базе учётных записей
		for (account_t* user = *users; user < *users + *countUsers; user++)
		{
			// если логин совпадает
			if (!strcmp(user->login, login))
			{
				// если пароль совпадает
				if (!strcmp(user->password, password))
				{
					// если пользователь принадлежит к группе администрации
					if (user->accessLevel[0] == 'a')
						*adminFlag = true;

					return true;
				}
			}
		}

		// если данные введены неправильно
		cout << "\nINCORRECT LOGIN OR PASSWORD" << endl;

		pressAnyKey();
	}
}

// 5. ACCOUNT MANAGEMENT (ADMIN GROUP)
int AccontManagement(account_t** users, int* countUsers, key_t* key, int* sizeKey)
{
	// если база данных пустая
	if (*countUsers == 0)
	{
		system("cls");

		outLine();

		cout << "ACCOUNT MANAGEMENT" << endl;

		outLine();

		cout << "THE DATABASE IS EMPTY" << endl;

		pressAnyKey();

		return 0;
	}

	char* c = new char;

	int* n = new int;

	*n = 1;

	for (account_t* user = *users;; )
	{
		system("cls");

		outLine();

		cout << "ACCOUNT MANAGEMENT" << endl;

		outLine();

		// текущий пользователь/всего пользователей
		cout << "			" << *n << "/" << *countUsers << endl;

		// логин
		cout << "Login: " << user->login << endl;

		// пароль
		cout << "Password: " << user->password << endl;

		// уровень доступа
		cout << "Access level: ";

		// админ 
		if (user->accessLevel[0] == 'a')
		{
			cout << "Admin group" << endl;
		}
		else cout << "User group" << endl;

		// если текущий аккаунт admin
		if (!strcmp(user->login, "admin"))
			cout << "\n\n\n\n\nPRESS: LAST[1] NEXT[2] QUIT[ESC] NEW USER[N]" << endl;
		else
			cout << "\n\n\n\n\nPRESS: LAST[1] NEXT[2] QUIT[ESC] DELETE[D] NEW USER[N]" << endl;

		// ввод 
		while (true)
		{
			*c = _getch();

			// LAST[1]
			if (*c == '1')
			{
				// если это первая анкета
				if (user == *users)
				{
					break;
				}

				user--;

				--* n;
				break;
			}

			// NEXT[2]
			if (*c == '2')
			{
				// если это последняя анкета
				if (user == *users + *countUsers - 1)
				{
					break;
				}

				user++;

				++* n;
				break;
			}

			// QUIT[ESC]
			if (*c == (char)27)
			{
				delete n, c;

				return 0;
			}

			// DELETE[D]
			if (*c == 'D' || *c == 'd' && strcmp(user->login, "admin"))
			{
				DeleteUser(*user, 41, key, sizeKey);
				
				return 1;
			}

			// NEW USER[N]
			if (*c == 'n' || *c == 'N')
			{
				if (CreateUser(users, countUsers, key, sizeKey))
				{
					return 1;
				}
			}
		}
	}
}

// создание пользователя; 0 - пользователь не создан, 1 - пользователь создан;
int CreateUser(account_t** users, int* countUsers, key_t* key, int* sizeKey)
{
	// анкета нового пользователя
	account_t* newUser = new account_t;

	// заполнение полей структуры случайными символами
	GenerationRandomCymbols((char*)newUser, sizeof(account_t));

	// символ ввода
	char* c = new char;

	// флаг выхода из цикла
	bool* flag = new bool;

	*flag = false;

	while (true)
	{
		system("cls");

		outLine();

		cout << "NEW USER" << endl;

		outLine();

		// ввод логин
		cout << "Login: ";
		cin.getline(newUser->login, 20);

		// проверка базы данных на совпадение логина
		for (account_t* user = *users; user < *users + *countUsers; user++)
		{
			// если логин совпал
			if (!strcmp(newUser->login, user->login))
			{
				cout << "LOGIN IS ALREADY REGISTERED!" << endl;

				cout << "PRESS: RE-ENTER[R] QUIT[ESC]" << endl;

				// ввод 
				while (true)
				{
					*c = _getch();

					// RE-ENTER[R]
					if (*c == 'r' || *c == 'R')
					{
						*flag = true;
						break;
					}

					// QUIT[ESC]
					if (*c == 27)
					{
						delete flag, c, newUser;

						return 0;
					}
				}

				if (*flag)
				{
					break;
				}
			}
		}

		if (*flag)
		{
			*flag = false;
			continue;
		}

		// ввод пароля
		cout << "Password: ";
		cin.getline(newUser->password, 20);

		// уровень доступа
		cout << "Access level((A)dmin group/(U)ser group): ";

		// ввод 
		while (true)
		{
			*c = _getch();

			// admin group 
			if (*c == 'a' || *c == 'A')
			{
				newUser->accessLevel[0] = 'a';

				cout << "A" << endl;

				break;
			}

			// user group
			if (*c == 'u' || *c == 'U')
			{
				newUser->accessLevel[0] = 'u';

				cout << "U" << endl;

				break;
			}
		}

		cout << "PRESS: SAVE[ENTER] CANCEL[ESC]" << endl;

		// ввод 
		while (true)
		{
			*c = _getch();

			// SAVE[ENTER]
			if (*c == 13)
			{
				// открытие файла учётных записей в режиме бинарного чтения/записи
				FILE* file = fopen("./Security/access.list", "rb+");

				// установка указателя в конец файла
				fseek(file, 0, SEEK_END);

				// шифрование данных
				CryptOrDecrypt((char*)newUser, sizeof(account_t), key, 1, *sizeKey);

				// запись в конец файла из структуры 
				fwrite(newUser, sizeof(account_t), 1, file);

				// закрытие файла
				fclose(file);

				cout << "SAVE" << endl;

				pressAnyKey();

				delete c, newUser, flag;

				return 1;
			}

			// CANCEL[ESC]
			if (*c == 27)
			{
				delete c, newUser, flag;

				return 0;
			}
		}
	}
	
}

// удаление пользователя
void DeleteUser(account_t user, int sizeUser, key_t* key, int* sizeKey)
{
	account_t* us = &user;

	// шифрование данных пользователя
	CryptOrDecrypt((char*)us, sizeUser, key, 1, *sizeKey);

	// открытие файла учётных записей в режиме бинарного чтения/записи
	FILE* file = fopen("./Security/access.list", "rb");

	// установка указателя в конец файла
	fseek(file, 0, SEEK_END);

	// длина файла
	size_t* sizeFile = new size_t;

	*sizeFile = ftell(file);

	// установка указателя в начало файла
	fseek(file, 0, SEEK_SET);

	// буфер для файла
	char* buffer = new char[*sizeFile];
	
	// считывание файла в буфер
	fread(buffer, sizeof(char), *sizeFile, file);

	// закрытие файла 
	fclose(file);

	// поиск данных пользователя в файле
	for (char* buf = buffer; buf < buffer + *sizeFile; buf++)
	{
		// если данные совпали
		if (!strncmp(buf, (char*)us, sizeUser))
		{
			// счётчик смещения
			int* i = new int;

			*i = 0;

			// смещение элементов строки влево
			for (; *i < sizeUser; ++*i)
			{
				for (char* b = buf; b < buffer + *sizeFile - 1; b++)
				{
					swap(*b, *(b + 1));
				}
			}

			delete i;

			// уменьшение длины файла
			*sizeFile -= sizeUser;

			// открытие файла в режиме бинарной записи
			file = fopen("./Security/access.list", "wb");

			// запись в файл
			fwrite(buffer, sizeof(char), *sizeFile, file);

			// закрытие файла 
			fclose(file);

			delete sizeFile;
			delete[] buffer;

			return;
		}
	}
}
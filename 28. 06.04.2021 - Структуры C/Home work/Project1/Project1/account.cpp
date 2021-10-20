#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

#include "head.h"
#include "struct.h"

using namespace std;

extern cypher* sec;
extern bool admin;

// управление аккаунтом; 


// принимает логин и пароль; возвращает: 0 - пользователь успешно сохранён; 1 - логин занят;
int createAccount()
{
	int* n = new int;

	while (true)
	{
		cout << "-----------------------------------------------" << endl << endl;

		cout << "-----------------Create Account----------------" << endl << endl;

		// логин 
		char* login = new char[20];

		// ввод логина 
		cout << "Enter login: ";
		cin.getline(login, 18);

		cout << endl;

		// пароль 
		char* password = new char[20];

		// ввод пароля
		cout << "Enter password: ";
		cin.getline(password, 18);

		cout << endl;

		// вызов фунцкии тихой регистрации
		*n = createAccount(login, password);

		// если логин не уникален
		if (*n == 3)
		{
			cout << "LOGIN IS NOT UNIQUE!" << endl;
			
			// отчитска консоли
			system("cls");
			continue;
		}

		// если не удалось открыть файл учётных данных пользователей
		if (*n == 0)
		{
			return 0;
		}

		cout << "\n\n\n\n\nSUCCESSFULLY REGISTRATION!" << endl;
		
		// ожидание нажатия любой клавиши
		cout << "\n\n\nPRESS ANT KEY TO CONTINUE" << endl;

		// нажатие любой клавиши
		_getch();

		break;
	}

	// отчистка консоли
	system("cls");

	return 1;
}


// тихая регистрация
int createAccount(char* login, char* password)
{
	// открытие файла базы данных пользователей в режиме бинарного дополнения
	FILE* file = fopen(".\\Authentication\\login.auth", "ab+");

	// если файл окрыт неуспешно
	if (file == nullptr)
	{
		cout << "ERROR OPEN FILE \"login.auth\"" << endl;

		return 0;
	}

	// проверка логина по базе данных
	// размер файла 
	size_t* size = new size_t;

	*size = ftell(file);

	// установка указателя в конец файла
	fseek(file, 0, SEEK_SET);

	// создание буфера для файла
	char* buffer = new char[*size];

	// считывание файла в буфер
	fread(buffer, sizeof(char), *size, file);

	// длина данных для логина и пароля всего: 40
	// login - 20 символов; максимум для ввода - 18
	// password - 20 символов; максимум для ввода - 18

	// расшифровка и заполение в структуру всех акаунтов

	// количество пользователей
	int* count_acc = new int;

	*count_acc = *size / 40;

	// отчистка памяти
	delete size;

	// массив структур по количеству пользователей
	account_data* user = new account_data[*count_acc];

	// указатель на буфер
	char* buf = buffer;


	// заполнение структуры
	for (account_data* us = user; us < user + *count_acc; us++)
	{
		// расшифровка и копирование имени в структуру
		strncpy((*us).login, buf, 19);

		// расшифровывание 
		decryption(*sec, (*us).login, 20);

		// смещение указателя в буфере
		buf += 20;

		// расшифровка и копирование пароля в структуру
		strncpy((*us).login, buf, 19);

		// смещение указателя в буфере
		buf += 20;
	}

	// отчистка памяти
	delete[] buffer;

	// показатель того что логин уникален
	bool* detect = new bool;
	*detect = false;

	// поиск логина и пароля в базе учётных записей
	for (account_data* us = user; us < user + *count_acc; us++)
	{
		// сравнение логина 
		if (!strcmp(login, (*us).login))
		{
			// если данные совпали
			*detect = true;

			// отчистка памяти
			delete[] user;
			delete count_acc;

		}
	}

	// если есть совпадения
	if (*detect)
	{
		// закрытие файла
		fclose(file);

		return 3;
	}

	// шифрование логина 
	encryption(*sec, login, 20);
	encryption(*sec, password, 20);

	// буфер 
	char* buff = new char[41];

	// заполнение буфера
	for (char* i = login, * k = password, * b = buff; i < login + 19; i++, k++, b++)
	{
		*b = *i;
		*(b + 19) = *k;
	}

	// запись в конец файла из буфера
	fwrite(buff, sizeof(char), 40, file);

	// закрытие файла
	fclose(file);

	return 1;
}
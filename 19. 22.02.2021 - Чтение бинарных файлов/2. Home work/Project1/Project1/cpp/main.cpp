#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	// логин
	char login[40];

	// пароль
	char password[40];

	// ввод логина
	cout << "Login: ";
	cin.getline(login, 40);

	cout << endl;

	// ввод пароля
	cout << "Password: ";
	cin.getline(password, 40);

	cout << endl;

	// если введённые логин и пароль совпадают с небходимыми
	if ((!strcmp(login, "Mikhail") && !strcmp(password, "Goriachev")) || (!strcmp(login, "admin") && !strcmp(password, "Qwerty12")))
	{
		// открытие файла exe в режиме чтения
		FILE* file = fopen("Project2.exe", "rb");

		// перенос указателя в файле в конец
		fseek(file, 0, SEEK_END);

		// длина файла exe
		long size = ftell(file);

		// начало cpp файла
		long start = 53760;

		// буфер
		char* buffer = new char[size - start];

		// указатель в exe файле перемещен на начало cpp файла в нем
		fseek(file, start, SEEK_SET);

		// считывание cpp файла в буфер
		fread(buffer, sizeof(char), size - start, file);

		// создания файла main.cpp
		FILE* cpp = fopen("main.cpp", "wb");

		// заполнение cpp файла его содержимым буфера
		fwrite(buffer, sizeof(char), size - start, cpp);

		// закрытие exe файла 
		fclose(file);

		// закрытие cpp файла
		fclose(cpp);

		cout << "Complete" << endl;

		// ожидание нажатия любой клавиши
		_getch();
	}

	// если логин и/или пароль неверны
	else cout << "Error login or password!" << endl;

	// ожидание нажатия любой клавиши
	_getch();
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>
#include <direct.h>

using namespace std;

// инсталлер 

// структура папок и файлов
//	.\Library\
//	.\Library\list.data
//	.\Library\Books\
//	.\Library\Books\[numberBook]
//	.\Users
//  .\Users\user.data
//	.\Security
//	.\Security\key.data
//	
//

void line()
{
	cout << "\n--------------------------------------------------------------\n\n";
}

void pressAnyKey()
{
	cout << "\n\n\n\nPRESS ANY KEY TO CONTINUE" << endl;

	_getch();
}


// случайные символы
void randomCymb(char* str, size_t size)
{


	char* a = new char[53];

	strcpy(a, "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm");

	// заполнение строки случайными сиволами
	for (char* s = str; s < str + size; s++)
	{
		*s = a[rand() % 53];
	}
}

// перемешивание строки
void mixStr(char* str, size_t size)
{
	srand(time(0));

	for (char* s = str; s < str + size; s++)
	{
		swap(s[rand() % size], s[rand() % size]);
	}
}

// шифрование
void Crypt(char* str, unsigned long size, char* a, char* b)
{

	for (char* str_p = str; str_p < str + size; str_p++)
	{
		for (char* key_a = a, *key_b = b; key_a < a + 52; key_a++, key_b++)
		{
			if (*key_b == *str_p)
			{
				*str_p = *key_a;

				break;
			}
		}
	}
}


void main()
{
	srand(time(0));

	line();

	cout << "LIBRARY 1.1 INSTALLER" << endl;

	line();

	// указатель на файл
	FILE* file = nullptr;

	// путь установки 
	char* pathInstall = new char[_MAX_PATH];

	// установка в текущую папку или ввод пути для установки
	cout << "Install in the current folder or enter the installation path? (Y/N): ";
	
	// символ 
	char* c = new char;

	// указатель на начало имени директории
	char* nameDir;
		
	// ключ шифрования
	char* a = new char[251];

	// заполнение случайными символами
	randomCymb(a, 250);

	strcpy(a, "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm");

	// перемешивание строки
	mixStr(a, 51);

	// ключ шифрования
	char* b = new char[251];

	// заполнение случайными символами
	randomCymb(b, 250);

	strcpy(b, "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm");

	// перемешивание строки
	mixStr(b, 51);


	// ввод 
	while (true)
	{
		*c = _getch();

		// 'Y' установка по текущему пути
		if (*c == 'Y' || *c == 'y')
		{
			strcpy(pathInstall, ".\\");

			// указатель на начало имени директории
			nameDir = &pathInstall[strlen(pathInstall)];

			break;
		}

		// 'N' ввод пути для установки
		if (*c == 'N' || *c == 'n')
		{
			system("cls");

			// ввод пути 
			line();

			cout << "LIBRARY 1.1 INSTALLER" << endl;

			line();

			// ввод пути 
			cout << "Enter path install: ";
			cin.getline(pathInstall, _MAX_PATH);

			strcat(pathInstall, "\\");

			// указатель на начало имени директории
			nameDir = &pathInstall[strlen(pathInstall)];

			break;
		}
	}

	line();

	cout << "LIBRARY 1.1 INSTALLER" << endl;

	line();
	
	// .\Library

	strcpy(nameDir, "Library");

	cout << "> Library" << endl;

	// если упешно
	if (_mkdir(pathInstall) != -1)
	{
		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}


	// .\Library\list.data

	strcpy(nameDir, "Library\\list.data");

	cout << "> Library\\list.data" << endl;

	file = fopen(nameDir, "w");

	// если упешно
	if (file != nullptr)
	{
		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}


	// .\Library\Books

	strcpy(nameDir, "Library\\Books");

	cout << "> Library" << endl;

	// если упешно
	if (_mkdir(pathInstall) != -1)
	{
		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}

	//	.\Users
	strcpy(nameDir, "Users");

	cout << "> Users" << endl;

	// если упешно
	if (_mkdir(pathInstall) != -1)
	{
		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}

	//  .\Users\user.data

	strcpy(nameDir, "Users\\user.data");

	cout << "> Users\\user.data" << endl;

	file = fopen(nameDir, "wb");

	// если упешно
	if (file != nullptr)
	{
		// создание логина и пароля администратора по умолчанию
		
		// буфер
		char* buffer = new char[20];

		// заполнение буфера случайными символами
		randomCymb(buffer, 20);

		// заполнение буфера
		strcpy(buffer, "admin");

		// шифрование буфера
		Crypt(buffer, strlen(buffer), a, b);

		// запись в файл
		fwrite(buffer, sizeof(char), 20, file);

		// заполнение буфера случайными символами
		randomCymb(buffer, 20);

		// заполнение буфера
		strcpy(buffer, "123456");

		// шифрование буфера
		Crypt(buffer, strlen(buffer), a, b);

		// запись в файл
		fwrite(buffer, sizeof(char), 20, file);

		// заполнение буфера случайными символами
		randomCymb(buffer, 20);

		// заполнение буфера
		strcpy(buffer, "Goriachev");

		// шифрование буфера
		Crypt(buffer, strlen(buffer), a, b);

		// запись в файл
		fwrite(buffer, sizeof(char), 20, file);

		// заполнение буфера случайными символами
		randomCymb(buffer, 20);

		// заполнение буфера
		strcpy(buffer, "Mikhail");

		// шифрование буфера
		Crypt(buffer, strlen(buffer), a, b);

		// запись в файл
		fwrite(buffer, sizeof(char), 20, file);

		int n = 1;

		// запись в файл
		fwrite(&n, sizeof(int), 1, file);

		// закрытие файла
		fclose(file);

		delete[] buffer;

		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}

	//	.\Security
	strcpy(nameDir, "Security");

	cout << "> Security" << endl;

	// если упешно
	if (_mkdir(pathInstall) != -1)
	{
		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}

	//	.\Security\key.data

	strcpy(nameDir, "Security\\key.data");

	cout << "> Security\\key.data" << endl;

	file = fopen(nameDir, "wb");

	// если упешно
	if (file != nullptr)
	{
		// создание логина и пароля администратора по умолчанию

		// запись в файл
		fwrite(a, sizeof(char), 250, file);

		// запись в файл
		fwrite(b, sizeof(char), 250, file);

		// закрытие файла
		fclose(file);

		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}

	cout << "INSTALL COMPLETE" << endl;

	delete[] a, b, nameDir;
	delete c;
}
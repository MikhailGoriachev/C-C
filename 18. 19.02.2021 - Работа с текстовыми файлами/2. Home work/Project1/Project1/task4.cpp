#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

// проверка символов
bool detectSymb(char a[]);

void task4()
{
	// 4. Пользователь вводит имя файла, программа удаляет 
	// из файла все слова, содержащие любые символы, кроме 
	// буквенных и результат записывает в другой файл.

	// имена файлов
	char name_1[40], name_2[40];

	// указатели на файл
	FILE* file_1, * file_2;

	// ввод имени первого файла
	cout << "Enter name first file: ";
	cin.ignore();
	cin.getline(name_1, 40);

	cout << endl;

	// проверка файла
	int detectFile = fileCreate(name_1);

	cout << endl;

	// если файл создан
	if (detectFile == 1)
	{
		// ввод в файл
		cout << "Enter strings in file: ";
		cout << endl;

		cin.ignore();

		file_1 = fopen(name_1, "w");

		while (true)
		{
			cout << "/ ";

			// буфер для одной строки из файла
			char buffer[40];

			// ввод строки
			cin.getline(buffer, 40);

			if (!strcmp(buffer, "0"))
			{
				break;
				cout << endl;
			}

			// проверка на '\n'
			detectBackN(buffer);

			// ввод строки из буфера в файл
			fputs(buffer, file_1);

			// отчистка буфера
			strcpy(buffer, "");

			cout << endl;
		}

		// заркытие первого файла
		fclose(file_1);

		cout << name_1 << "save" << endl;
	}

	// если файла не существует
	if (detectFile == 0)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	// ввод имени второго файла
	cout << "Enter name second file: ";
	cin.getline(name_2, 40);

	cout << endl;

	// если файла не существует
	if (!fileCreate(name_2))
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	cout << endl;

	// открытие первого файла в режими чтения
	file_1 = fopen(name_1, "r");

	// открытие второго файла в режими записи
	file_2 = fopen(name_2, "w");

	// заполнение второго файла словами без символов кроме букв из втрого файла
	while (!feof(file_1))
	{
		// буффер слова
		char buffer[200];

		// считывание одного слова с файла в буфер
		fscanf(file_1, "%s", buffer);

		// проверка слова из буфера на наличие недопустимых символов
		if (detectSymb(buffer))
			fprintf(file_2, "%s", buffer);

		// отчистка буфера
		strcpy(buffer, "");
	}

	// закрытие перого файла
	fclose(file_1);
	// закрытие второго файла
	fclose(file_2);
}

// проверка символов
bool detectSymb(char a[])
{
	for (size_t i = 0; a[i] != 0; i++)
	{
		if (!(a[i] >= 'A' && a[i] <= 'z'))
			return false;
	}

	return true;
}
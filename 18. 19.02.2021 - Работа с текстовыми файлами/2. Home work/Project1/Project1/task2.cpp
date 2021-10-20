#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"
#include <stdlib.h>

using namespace std;

void clearingNum(char a[]);

void task2()
{
	// 2. Пользователь вводит 2 имени файла, программа удаляет 
	// из первого файла все цифры и результат записывает во
	// второй файл
	
	// имена файлов
	char name_1[40];
	char name_2[40];

	// указатели на файл
	FILE* file_1, *file_2;

	// ввод имени перового файла
	cout << "Enter name first file: ";
	cin >> name_1;

	cout << endl;

	// проверка файла на наличие
	int filedetect = fileCreate(name_1);

	// если создан новый файл
	if (filedetect == 1)
	{
		// заполнение файла
		cout << "Enter strings in file (0 exit): ";

		// открытие файла в режиме редактирования 
		file_1 = fopen(name_1, "w");

		cin.ignore();

		// пользователь вводит строки в файл
		while (true)
		{
			char buffer[40];
			cin.getline(buffer, 40);
			if (!strcmp(buffer, "0"))
			{
				cout << endl;
				break;
			}

			detectBackN(buffer);

			fputs(buffer, file_1);
			strcpy(buffer, "");
		}

		// закрытие файла
		fclose(file_1);

		cout << endl << name_1 << " save complete" << endl;
		cout << endl;
	}

	// если файла не сущесвует 
	if (filedetect == 0)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	// ввод имени второго файла
	cout << "Enter name second file: ";
	cin >> name_2;
	
	cout << endl;

	// проверка файла на наличие
	filedetect = fileCreate(name_2);

	cout << endl;

	// если файла не существует
	if (filedetect == 0)
	{
		cout << endl;
		cout << "Exit";
		return;
	}

	// открытие первого файла в режиме чтения
	file_1 = fopen(name_1, "r");

	// открытие второго файла в режиме записи
	file_2 = fopen(name_2, "w");

	// заполнение второго файла содержимым первого, но без цифр
	while (!feof(file_1))
	{
		// буфер для одной строки
		char buffer[200];

		// заполнение буфера одной сторокой из первого файла
		fgets(buffer, 199, file_1);

		// отчистка строки в буфере от цифр
		clearingNum(buffer);

		// проверка на наличие "\n" в конце строки
		detectBackN(buffer);

		// заполнение второго файла строкой из буфера
		fputs(buffer, file_2);

		// отчистка буфера
		strcpy(buffer, "");
	}

	// закрытие файлов
	fclose(file_1);
	fclose(file_2);

	cout << "File copy cmplete!" << endl;
}

// отчиска строки от цифр
void clearingNum(char a[])
{
	for (size_t i = 0; a[i] != 0; i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			for (size_t k = i; a[k - 1] != 0; k++)
			{
				swap(a[k], a[k + 1]);
			}
			i--;
		}
	}
}
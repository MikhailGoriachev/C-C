#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include "header.h"

using namespace std;

void task4()
{
	// 4. Пользователь вводит имя файла, программа копирует его 
	// во второй файл, но строки будут в перевёрнум виде: первая 
	// строка станет последней, вторая - предпоследней и т.д.
	int size = 40;

	// строка для имени файла
	char* file_name_1 = new char[size];

	// ввод директории
	char* name = enterDir(file_name_1, &size);

	// ввод имени
	cout << "Enter name file: ";
	cin >> name;

	// проверка и/или создание файла
	int det = detectFile(file_name_1);

	// если создан пустой файл, то он заполняется массивом из слуйчайных символов
	if (det == 1)
	{
		fill2DArrayComb(file_name_1);
		cout << endl;
	}

	// если пользователь отказался создавать файл, то выход их программы
	if (det == 3)
	{
		cout << "Exit" << endl;
		return;
	}

	// стандартная длина строки
	size = 40;
	
	// строка для второго имени
	char* file_name_2 = new char[size];

	// ввод директории
	name = enterDir(file_name_2, &size);

	// ввод имени файла 
	cout << "Enter name file: ";
	cin >> name;

	// открытие первого файла в режиме чтения
	FILE* file = fopen(file_name_1, "r");

	// количество строк и столбоцов для двумерного динамического массива
	int rows = 0;
	int cols = 1;

	// подсчёт количества строк
	char* buffer = new char[400];
	while (!feof(file))
	{
		if (!feof(file))
		{
			fgets(buffer, 200, file);
			// счётчик строк
			rows++;
		}
		
		// длина текущей строки
		int max = strlen(buffer);

		// если длина строки больше, чем у предыдущих строк
		if (max > cols)
			cols = max;

		// отчиска буфера
		strcpy(buffer, "");
	}
	delete[] buffer;

	fclose(file);
	file = fopen(file_name_1, "r");
	// заполнение массива строками из файла
	char** content = new char* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		content[i] = new char[cols + 1];
		strcpy(content[i], "");
		fgets(content[i], cols + 1, file);
	}

	// закрытие первого файла
	fclose(file);

	// открытие второго файла в режиме записи
	file = fopen(file_name_2, "w");

	// запись файла в перевёрнутом виде
	for (int i = rows-1; i >= 0; i--)
	{
		fputs(content[i], file);
	}

	// удаление двумерного динамического массива
	deleteArr(content, rows, cols);

	// закрытие второго файла
	fclose(file);

	cout << endl;

	cout << "Save" << endl;
}
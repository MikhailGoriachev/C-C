#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "header.h"

using namespace std;

void task3()
{
	// 3. Пользователь вводит имя файла, программа копирует 
	// во второй файл только найденные числа в первом файле

	// стандартая длина строки
	int size = 40;

	// имя первого файла вместе с директорией 
	char* name_file_1 = new char[size];

	// имя первого файла, фукнция ввода директории возвращает указатель на начало ввода имени 
	char* name = enterDir(name_file_1, &size);

	// ввод имени файла
	cout << "Enter file name: ";
	cin >> name;

	cout << endl;

	// проверка файла на наличие и/или создание его
	int det = detectFile(name_file_1);

	// заполнение нового файла
	if (det == 1)
	{
		fill2DArrayComb(name_file_1);
	}	
	else if (det == 3)
	{
		cout << "Exit" << endl;
		return;
	}

	cout << endl;

	// стандартная длина строки
	size = 40;
	
	// имя второго файла вместе с директорией 
	char* name_file_2 = new char[size];

	// имя второго файла, фукнция ввода директории возвращает указатель на начало ввода имени 
	name = enterDir(name_file_2, &size);

	// ввод имени файла
	cout << "Enter file name: ";
	cin >> name;

	det = detectFile(name_file_2);
	if (det == 1)
	{
		cout << endl;
		cout << "File complete" << endl;
	}
	if (det == 3)
	{
		cout << endl;
		cout << "Exit" << endl;
		return;
	}

	cout << endl;

	// открытие первого файла
	FILE* file_1 = fopen(name_file_1, "r");

	// открытие второго файла 
	FILE* file_2 = fopen(name_file_2, "w");

	// заполнение второго файла числами из первого файла
	while (!feof(file_1))
	{
		int num;
		char sym;
		if (fscanf(file_1, "%d", &num) && !feof(file_1))
			fprintf(file_2, "%d ", num);		
		if (fscanf(file_1, "%c", &sym) && !feof(file_1))
			continue;
	}

	// закрытие первого файла
	fclose(file_1);

	// закрытие второго файла
	fclose(file_2);

	cout << "Save" << endl;
}
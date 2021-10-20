#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

void task2()
{
	// 2. Пользователь вводит имя cpp - файла,
	// программа подсчитывает количество использований операторов for, while, if внутри файла.

	// имя исходного файла
	char name[40];

	// ввод имени исходного файла
	cout << "Enter name CPP file: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// счётчик for
	size_t count_for = 0;

	// счётчик while 
	size_t count_while = 0;

	// счётчик if
	size_t count_if = 0;

	// открытие файла в режиме чтения
	FILE* file = fopen(name, "r");

	// если файла открыт успешно
	if (file != nullptr)
	{
		// буфер для одного слова
		char buff[200];
		
		// пока указатель в файле не достиг конца файла
		while (!feof(file))
		{
			// считывание по одному слову в буфер
			fscanf(file, "%199s", buff);

			// если слово в буфере "for"
			if (!strcmp(buff, "for"))
			{
				count_for++;
			}

			// если слово в буфере "while"
			if (!strcmp(buff, "while"))
			{
				count_while++;
			}

			// если слово в буфере "if"
			if (!strcmp(buff, "if"))
			{
				count_if++;
			}
		}

		// закрытие исходного файла
		fclose(file);

		// вывод результата
		cout << "Result" << endl;
		cout << "for: " << count_for << endl;
		cout << "while: " << count_while << endl;
		cout << "if: " << count_if << endl;
		cout << endl;
	}
	// если файл не удалось открыть
	else cout << "File NOT found" << endl;
}
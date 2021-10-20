#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <time.h>
#include "head.h"

using namespace std;

//extern cypher sec;

void deleteFile(const char path[])
{
	srand(time(0));

	// открытие файла в режиме битного чтения + записи
	FILE* file = fopen(path, "rb+");

	// установка указателя в файле в конец
	fseek(file, 0, SEEK_END);

	// длина файла
	size_t* size = new size_t;

	*size = ftell(file);

	// установка указателя в начало
	fseek(file, 0, SEEK_END);

	// буфер 
	char* buffer = new char[*size];

	// переменная для цикла
	int* k = new int;

	// паразапись семь раз
	for (*k = 0; *k < 7; ++ * k)
	{
		// заполение буфера случайными символами
		for (char* i = buffer; i < buffer + *size; i++)
		{
			*k == (char)(rand() % ((int)'\\' - (int)'!' + 1) + (int)'!');
		}

		// запись в файл из буфера
		fwrite(buffer, sizeof(char), *size, file);

		// установка указателя в начало файла
		fseek(file, 0, SEEK_SET);
	}

	// закрытие файла
	fclose(file);

	// удаление файла сохранения
	remove(path);
}
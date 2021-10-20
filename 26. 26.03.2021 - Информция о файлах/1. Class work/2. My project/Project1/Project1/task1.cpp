#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>

using namespace std;

void task1()
{
	// пользователь вводит название папки, программа
	// подсчитывает количество букв 'a' во всех текстовых
	// файлах в этой папке

	// директория
	char* dir = new char[255];

	// имя и путь файла
	char* name = new char[255];



	// ввод директории
	cout << "Enter directory: ";
	cin.ignore();
	cin.getline(dir, 255);

	cout << endl;

	// добавелние к пути '\'
	strcat(dir, "\\");

	// копирование пути
	strcpy(name, dir);

	// добавление к имени файла расширения
	strcat(name, "*.txt");

	// список файлов
	_finddata_t list;

	// указатель на список и создание списка
	long point = _findfirst(name, &list);

	FILE* file = nullptr;

	unsigned long* count = new unsigned long;

	*count = 0;

	// перебор файлов
	do
	{
		cout << list.name << "     ";
		strcpy(name, dir);

		strcat(name, list.name);

		file = fopen(name, "rb");
		
		if (file != nullptr)
		{
			cout << list.size << endl;
			char* buffer = new char[list.size];

			fread(buffer, sizeof(char), list.size, file);

			for (char* buf = buffer; buf < buffer + list.size; buf++)
			{
				if (*buf == 'a' || *buf == 'A')
				{
					++* count;
				}
			}

			delete[] buffer;

			fclose(file);
		}
		else cout << "FILE NO OPENING" << endl;

	} while (!_findnext(point, &list));

	cout << endl;

	cout << "Count = " << *count << endl;

}
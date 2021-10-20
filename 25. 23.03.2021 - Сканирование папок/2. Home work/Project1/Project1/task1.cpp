#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
using namespace std;

void task1()
{
	// 1. Пользователь вводит путь к папке, программа
	// подсчитывает общие размер файлов в папке

	// директория
	char* dir = new char[80];

	// ввод директории
	cout << "Enter dir: ";
	cin.ignore();
	cin.getline(dir, 80);

	strcat(dir, "\\*.*");

	cout << endl;

	// список файлов в директории
	_finddata_t list;

	// указатель на первый элемент списка
	long point = _findfirst(dir, &list);

	// сумма размера всех файлов
	unsigned long* sum = new unsigned long;

	*sum = 0;

	// количество файлов
	unsigned long* count = new unsigned long;

	*count = 0;

	cout << "File list" << endl;

	// перебор файлов и сумирование их размера
	while (!_findnext(point, &list))
	{
		// если файл является директорией
		if (list.attrib & _A_SUBDIR)
		{
			continue;
		}

		// вывод имени файла и его размера
		cout << list.name << "      " << list.size << endl;

		// прибавление к счётчику файлов
		*count += 1;

		// прибавление размера текущего файла, взятого из структуры списка
		*sum += list.size;
	}

	cout << endl;
	
	// закрытие списка
	_findclose(point);

	// вывод результата
	cout << "Count files = " << *count << "     All size = " << *sum << endl;

	delete[] dir, sum;
}
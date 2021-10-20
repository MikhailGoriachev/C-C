#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>

using namespace std;

void task2()
{
	// пользователь вводит имя папки программа подсчитывает 
	// общий размер файлов

	// директория 
	char dir[40];

	// ввод директории
	cout << "Enter dir: ";
	cin.ignore();
	cin.getline(dir, 40);

	// добавление в конец директории *.*
	strcat(dir, "\\*.*");

	// список файлов в папке
	// переменная типа структуры
	_finddata_t list;

	// указатель на список
	long point;

	// функция считывает список файлов в папке и записывает его в список,
	// возвращает указатель на список
	point = _findfirst(dir, &list);

	// размер файлов
	long size = 0;

	// пока список не 
	while (_findnext(point, &list) == 0)
	{
		// если это не подпапка
		if (!(list.attrib & _A_SUBDIR))
		{
			// прибавление к общему размеру размер взятый из стркутуры
			size += list.size;
		}
	}

	// вывод результата
	cout << "Size: " << size << endl;
}
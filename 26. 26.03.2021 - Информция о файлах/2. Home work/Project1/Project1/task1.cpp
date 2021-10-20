#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>

using namespace std;

void task1()
{
	// 1. Пользователь вводит путь к папке и маску файлов, 
	// программа подсчитывает количество файлов и общие
	// количество букв в именах в названиях файлов в папке

	// путь к папке
	char* dir = new char[_MAX_PATH];

	// ввод пути 
	cout << "Enter path: ";
	cin.ignore();
	cin.getline(dir, _MAX_PATH);

	cout << endl;

	// маска для поиска файла 
	char* mask = new char[_MAX_PATH];

	// ввод маски 
	cout << "Enter mask: ";
	cin.getline(mask, _MAX_PATH);

	cout << endl;

	// копирование пути в путь к файлу
	strcat(dir, "\\");

	// прибавление маски к пути
	strcat(dir, mask);

	// список файлов в папке
	_finddata_t list;

	// указатель на список и создание списка
	long point = _findfirst(dir, &list);

	// общее количество букв в имени
	unsigned long* count_lett = new unsigned long;

	*count_lett = 0;

	// количество файлов 
	unsigned long* count_files = new unsigned long;

	*count_files = 0;

	// размер всех файлов 
	unsigned long* count_size = new unsigned long;

	*count_size = 0;

	// сканирование списка
	if (point != -1)
	{
		do
		{
			// если файл не является папкой
			if (!(list.attrib & _A_SUBDIR))
			{
				// увелчиение счётчика колчество букв в имени 
				*count_lett += strlen(list.name);

				// увеличение счётчика файлов
				++* count_files;

				// вывод имени фала и его размера
				cout << list.name << "     " << list.size << endl;

				// увеличесние счётчика общего размера всех файлов
				*count_size += list.size;
			}
			else cout << list.name << "     <DIR>" << endl;
		} while (!_findnext(point, &list));
	}

	cout << endl;

	// удаление списка
	_findclose(point);

	// вывод колиства файлов 
	cout << "Count files = " << *count_files << endl;

	// вывод количества букв в имени
	cout << "Count letters = " << *count_lett << endl;

	// вывод общего размера фалов
	cout << "All size = " << *count_size << endl;

	// отчистка памяти
	delete[] dir, mask;
	delete count_lett, count_files, count_size;
}
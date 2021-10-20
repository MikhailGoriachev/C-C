#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

using namespace std;

// сканирование файлов и папок по маске 
void scanFile(char* dir, char* mask, unsigned long* count)
{
	// добавление к пути '\\'
	strcat(dir, "\\");

	// указатель на начало имени в пути
	char* name = dir + strlen(dir);

	// маска для нахождение всех файлов
	strcpy(name, "*");

	// список фалов в папке
	_finddata_t list;

	// указатель на список
	long point = _findfirst(dir, &list);

	// сканирование списка всех файлов
	do
	{
		if (!strcmp(list.name, ".") || !strcmp(list.name, ".."))
		{
			continue;
		}

		// добавление имени текущего файла к пути
		strcpy(name, list.name);

		// переменная для цикла 
		int* i = new int;

		// вывод символов '|' для обозначения уровня директории
		for (*i = 0; *i < *(count + 5); ++ * i)
		{
			cout << "|";
		}
		delete i;

		// вывод текущего пути с именем
		cout << name << "     ";

		// если файл является папкой
		if (list.attrib & _A_SUBDIR)
		{
			cout << "<DIR>" << endl;

			// увеличение счётчика папок
			++* (count + 4);

			// увеличение уровня папки
			++* (count + 5);

			// вызов этой же функции
			scanFile(dir, mask, count);
			
			// уменьшение уровня папки
			--* (count + 5);

			continue;
		}

		// если это обычный файл
		else 
		{
			// вывод размера файла
			cout << list.size << endl;

			// увеличение общего счётчика файлов
			++* count;

			// прибавление размера файла к общему размеру найденных файлов
			*(count + 2) += list.size;
		}
	} while (!_findnext(point, &list));

	_findclose(point);

	// к пути к папке добавляется маска 
	strcpy(name, mask);
	
	_finddata_t list_mask;

	// удаление создание нового списка по маске
	long point_mask = _findfirst(dir, &list_mask);

	if (point_mask == -1)
	{
		_findclose(point_mask);

		return;
	}

	// сканирование списка
	do
	{
		if (!(list_mask.attrib & _A_SUBDIR))
		{
			// увеличение счётчика количества файлов по маске
			++* (count + 1);

			// увелчение общего размера всех файлов по маске
			*(count + 3) += list_mask.size;
		}
	} while (!_findnext(point_mask, &list_mask));

	_findclose(point_mask);
}

void task1()
{
	// 1. Пользователь вводит путь к папке и маску файлов, 
	// программа подсчитывает общий размер файлов, найденных
	// в папке и в подпапках

	// путь к папке
	char* dir = new char[_MAX_PATH];

	// маска
	char* mask = new char[_MAX_FNAME];

	// ввод пути к папке
	cout << "Enter folder path: ";
	cin.ignore();
	cin.getline(dir, _MAX_PATH);

	cout << endl;

	// ввод маски
	cout << "Enter mask: ";
	cin.getline(mask, _MAX_FNAME);

	// пользователь нажимает любую клавишу для старта выполнения сканирования
	cout << "\n\n\n\n\nPRESS ANY KEY TO START..." << endl;

	// нажатие любой клавиши
	_getch();

	// отчистка консоли
	system("cls");

	// список файлов 
	_finddata_t list;

	// указатель на список и создание списка файлов
	long point = _findfirst(dir, &list);

	// массив счётчиков; [0] - общее количество файлов в папке; [1] - количество файлов по маске; 
	// [2] - общий размер всех файлов; [3] - размер всех файлов по маске; [4] - общее количество папок;
	// [5] - уровень текущей папки;
	unsigned long* count = new unsigned long[6];

	// [0] - общее количество файлов 
	*count = 0;
	// [1] - количество файлов по маске
	*(count + 1) = 0;
	// [2] - общий размер всех файлов
	*(count + 2) = 0;
	// [3] - размер всез файлов по маске
	*(count + 3) = 0;
	// [4] - общее количество папок
	*(count + 4) = 0;
	// [5] - уровень текущей папки
	*(count + 5) = 0;

	// запуск функции сканирования
	scanFile(dir, mask, count);

	// нажатие любой клавиши для вывода отчёта 
	cout << "\n\n\n\n\nPRESS ANY KEY TO OUTPUT THE REPORT..." << endl;

	// нажатие любой клавиши
	_getch();
	
	// отчистка консоли
	system("cls");

	// вывод отчёта 
	cout << "            REPORT            " << endl;
	// обще количество папок
	cout << "> Count all subdir: " << *(count + 4) << endl;
	// общее количество файлов
	cout << "> Count all file: " << *count << endl;
	// размер всех файлов 
	cout << "> Size all file: " << *(count + 2) << endl;
	// количество файлов по маске
	cout << "> Count mask file: " << *(count + 1) << endl;
	// размер файлов по маске 
	cout << "> Size mask file: " << *(count + 3) << endl;

	cout << "\n\n\n\n\nPRESS ANY KEY TO CLOSE THE PROGRAMM..." << endl;

	delete[] dir, count;

	// ожидание нажатия любой клавиши
	_getch();
}
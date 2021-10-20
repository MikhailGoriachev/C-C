#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <direct.h>

using namespace std;

// функция сканирования и удаления папок debug и .vs
void removeFolder(char* dir, unsigned long* count)
{
	// копирование пути
	char* path = new char[_MAX_PATH];

	strcpy(path, dir);

	// добавление к пути '\\'
	strcat(path, "\\");

	// укзаатель на начало имени файла в пути
	char* name = path + strlen(path);
	
	// имя для сканирования
	strcpy(name, "*");

	// создание списка
	_finddata_t list;

	// указатель на список и создание списка
	long point = _findfirst(path, &list);

	// сканирование списка
	do
	{
		// добавление к пути имени текущего файла
		strcpy(name, list.name);

		// если это папка с названием .vs или debug
		if (!strcmp(list.name, ".vs") || !strcmp(list.name, "debug") || !strcmp(list.name, "x64"))
		{ 
			cout << path << "     " << list.size << "     ";

			// удаление папки
			if (rmdir(path) == -1)
			{
				cout << "ERROR REMOVE FOLDER!" << endl;

				continue;
			}
		
			cout << "REMOVE COMPLITE!" << endl;

			++*count;

			continue;
		}

		// если файл явялется папкой
		if (list.attrib & _A_SUBDIR && strcmp(list.name, ".") != 0 && strcmp(list.name, "..") != 0)
		{
			removeFolder(path, count);
		}

	} while (!_findnext(point, &list));


	// удаление пути
	delete[] path;


}

void task1()
{
	// программа отчищает папки debug и .vs 

	// путь к папке
	char* dir = new char[_MAX_PATH];

	// ввод пути к папке
	cout << "Enter folder path: " << endl;
	cin.ignore();
	cin.getline(dir, _MAX_PATH);

	// добавление '\\'
	// strcat(dir, "\\");

	// указатель на начало имени
	// char* name = dir + strlen(dir);

	// счётчики
	unsigned long* count = new unsigned long[2];

	// количество удалённых папок
	*count = 0;

	// общий размер удалённых папок
	*(count + 1) = 0;

	removeFolder(dir, count);

	cout << endl;

	cout << "Folder count: " << *count << endl;

	cout << "All size: " << *(count + 1) << endl;
}
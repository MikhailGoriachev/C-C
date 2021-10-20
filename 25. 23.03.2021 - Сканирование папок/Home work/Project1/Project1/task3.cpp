#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <io.h>

using namespace std;

void task3()
{
	// 3. Пользователь вводит 2 пути к папкам, программа
	// копирует все файлы из первой папки во вторую

	// путь к дериктории ресурса
	char* source = new char[80];

	// путь к дерикотрии назначения
	char* destination = new char[80];

	// флаг пемещения файлов
	int moving = 1;
	
	// выбор режима: копирование/перемещение
	cout << "Select copy(1)/moving(2): ";
	cin >> moving;

	cout << endl;

	// ввод пути ресурса
	cout << "Enter source: ";
	cin.ignore();
	cin.getline(source, 80);

	// добавление к путю '\'
	strcat(source, "\\");

	// чистый путь к ресурсу временно хранится в строке назначения
	strcpy(destination, source);

	// добавление к имени дериктории "*.*", которая временно хранится в строке назначения
	strcat(destination, "*.*"); /// ИЗМЕНИТЬ

	// список файлов в папке ресурса
	_finddata_t list;

	// указатель на первый элемент списка
	long point = _findfirst(destination, &list);

	// ввод пути назнаения 
	cout << "Enter destination: ";
	cin.getline(destination, 80);

	// добавление к путю '\'
	strcat(destination, "\\");


	// имя и путь файла ресурса
	char* name_s = new char[255];

	// имя и путь файла назначения
	char* name_d = new char[255];

	// указатель на файл ресурса
	FILE* file_s = nullptr;

	// указатель на файл назначения
	FILE* file_d = nullptr;

	// суммарный размер файлов
	long* sum = new long;

	*sum = 0;

	// количество файлов 
	long* count = new long;

	*count = 0;

	// копирование файлов
	while (!_findnext(point, &list))
	{
		// если файл не является директорией
		if (!(list.attrib & _A_SUBDIR))
		{
			// если копирование
			if (moving == 1)
				cout << "Copy " << list.name << "     ";
			else cout << "Moving " << list.name << "     ";

			// копирование пути файла ресурса
			strcpy(name_s, source);

			// добавление к пути имени файла ресурса
			strcat(name_s, list.name);

			// копировние пути файла назначения
			strcpy(name_d, destination);

			// добавление к пути имени файла ресурса
			strcat(name_d, list.name);

			// открытие файла в ресурса в режиме бинарного чтения
			file_s = fopen(name_s, "rb");

			// если файл ресурса удалось открыть
			if (file_s != nullptr)
			{
				// создание и открытие файла назначения в режиме бинарной записи
				file_d = fopen(name_d, "wb");

				// если файл назначения удалось открыть
				if (file_d != nullptr)
				{
					// буфер для файла
					char* buffer = new char[list.size];

					// прибавление к количетсву файлов
					++*count;

					// прибавлнение размера файла к суммарному размеру
					*sum += list.size;

					// считывание файла ресурса в буфер
					fread(buffer, sizeof(char), list.size, file_s);

					// запись в файл назначения из буфера
					fwrite(buffer, sizeof(char), list.size, file_d);

					// удаление буфера
					delete[] buffer;

					// закрытие файла ресурса
					fclose(file_s);

					if (moving == 2)
						remove(name_s);

					// закрытие файла назначения
					fclose(file_d);

					cout << "save" << endl;
				}
				// если файл назначения не удалось открыть и/или создать
				else cout << "ERROR CREATE FILE" << endl;
			}
			// если файл ресурса не удалось открыть
			else cout << "ERROR OPEN FILE" << endl;
		}
	}

	cout << endl;

	cout << "The end" << endl;

	cout << endl;

	cout << "Result" << endl;
	cout << "Count files = " << *count << "      " << "All size = " << *sum << endl;

}
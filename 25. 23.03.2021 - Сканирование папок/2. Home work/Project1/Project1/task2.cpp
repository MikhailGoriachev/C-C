#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>

using namespace std;

// порверка расширения файла
bool detectExp(char* name)
{
	// строка с расширением 
	char* exp = new char[5];

	// заполнение строки проверки
	strcpy(exp, ".txt");

	// длина строки имени файла
	size_t len = strlen(name);

	// если имя короче шести символов
	if (len < 5)
	{
		delete[] exp;
		return false;
	}

	for (char* name_p  = name + strlen(name) - 4,*p = exp; *p; name_p++, p++)
	{
		// если элементы строк не совпадают
		if (*p != *name_p)
		{
			delete[] exp;
			return false;
		}
	}

	delete[] exp;

	// если расширение правильное
	return true;
}

void task2()
{
	// 2. Пользователь вводит путь к папке, программа объединяет
	// все текстовые файлы в один результирующий файл

	// директория
	char* dir = new char[80];

	// ввод директории
	cout << "Enter directory: ";
	cin.ignore();
	cin.getline(dir, 80);

	// добавление к пути символа '\'
	strcat(dir, "\\");

	// имя файла
	char* name = new char[255];

	// копировние пути в имя результирующего файла
	strcpy(name, dir);

	// добавление к пути имени результирующего файла
	strcat(name, "result.txt");

	// открытие и создание результирующего файла в режиме бинарной записи
	FILE* result = fopen(name, "wb");

	// копирование пути
	strcpy(name, dir);

	// добавление к пути первого файла расширения .txt
	strcat(name, "*.*");

	cout << endl;

	// список текстовых файлов в папке
	_finddata_t list_TXT;

	// указатель на список
	long point = _findfirst(name, &list_TXT);

	// указатель на файл
	FILE* file = nullptr;

	// суммарный размер результирующего
	unsigned long* sum = new unsigned long;

	*sum = 0;

	// количество файлов
	unsigned long* count = new unsigned long;

	*count = 0;

	// сканирование папки и накстовые файлы и объединение их 
	// в результирующий
	while (!_findnext(point, &list_TXT))
	{
		// если файл является текстовым
		if (!(list_TXT.attrib & _A_SUBDIR) && detectExp(list_TXT.name))
		{
			cout << list_TXT.name << "      size: " << list_TXT.size << endl;

			// копирование пути к файлу в строку полного имени файла с путём
			strcpy(name, dir);

			// добавление к пути к файлу имени файла 
			strcat(name, list_TXT.name);

			// открытие текущего файла в режме бинарного чтения
			file = fopen(name, "rb");

			// если файла успешно открыт
			if (file != nullptr)
			{
				// увеличение счётчика файлов
				*count += 1;

				// прибавление размера файла к размеру результирующего файла
				*sum += list_TXT.size;

				// буфер для файла
				char* buffer = new char[list_TXT.size];

				// считывание файла в буфер
				fread(buffer, sizeof(char), list_TXT.size, file);

				// запись из буфера в результирующий файл
				fwrite(buffer, sizeof(char), list_TXT.size, result);

				// удаление буфера
				delete[] buffer;
				 
				// закрытие текущего файла 
				fclose(file);
			}

			// если не удалось открыть файл
			else cout << list_TXT.name << "      Failed to open the file" << endl;
		}
	}

	// закрытие списка
	_findclose(point);

	cout << endl;

	// закрытие и сохранение результирующего файла
	fclose(result);

	cout << "Count files = " << *count << "     All size: " << *sum << endl;

	cout << endl;

	cout << "Save result.txt" << endl;

	delete[] dir, name, sum;
}
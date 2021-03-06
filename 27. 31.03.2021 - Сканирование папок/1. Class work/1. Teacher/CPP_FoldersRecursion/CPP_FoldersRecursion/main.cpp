#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>

using namespace std;

void scan_dir(const char* dir_path, const char* mask)
{
	// новый путь к подпапкам
	char* new_path = new char[4097];

	// полный путь с маской
	char* mask_path = new char[4097];

	// сканирование подпапок
	// формирование полного пути
	strcpy(mask_path, dir_path);
	strcat(mask_path, "\\*.*");

	// переменная, хранящая информацию об одном файле
	_finddata_t c_file;

	// адрес списка найденных файлов
	long hFile;

	// найти файлы по маске и вернуть адрес списка найденных файлов и информацию о первом файле
	hFile = _findfirst(mask_path, &c_file);

	// если ничего не найдено
	if (hFile == -1)
		return;

	// цикл для получения информации об остальных найденных файлах
	do
	{
		if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
		{
			if (c_file.attrib & _A_SUBDIR)
			{
				// сформировать путь к подпапке
				//cout << c_file.name << "   " << "<DIR>" << endl;
				strcpy(new_path, dir_path);
				strcat(new_path, "\\");

				// добавить к полному пути имя текущей папки
				strcat(new_path, c_file.name);
				cout << new_path << endl;

				// рекурсивный вызов функции
				scan_dir(new_path, mask);
			}
		} 
	} while (_findnext(hFile, &c_file) == 0);

	// сканирование файлов в текущей папке
	// формирование полного пути
	strcpy(mask_path, dir_path);
	strcat(mask_path, "\\");
	strcat(mask_path, mask);

	// найти файлы по маске и вернуть адрес списка найденных файлов и информацию о первом файле
	hFile = _findfirst(mask_path, &c_file);

	// если ничего не найдено
	if (hFile == -1)
		return;

	// цикл для получения информации об остальных найденных файлах
	do
	{
		if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
		{
			if (! (c_file.attrib & _A_SUBDIR))
			{
				cout << dir_path << "\\" << c_file.name << "   " << c_file.size << endl;
			}
		}
	} while (_findnext(hFile, &c_file) == 0);

	// освободить память от списка найденных файлов
	_findclose(hFile);

	delete[] new_path;
	delete[] mask_path;
}

void main()
{
	scan_dir("c:\\Temp", "n*.txt");
}

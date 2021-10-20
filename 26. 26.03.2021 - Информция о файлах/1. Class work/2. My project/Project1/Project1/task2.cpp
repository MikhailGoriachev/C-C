#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>

using namespace std;

bool scanFile(FILE* file, unsigned long size, char* word)
{
	char* buffer = new char[size];

	fread(buffer, sizeof(char), size, file);

	bool* flag = new bool;

	for (char* buf = buffer; buf < buffer + size ; buf++)
	{
		*flag = true;

		for (char* p = buf, *wd = word; *wd; wd++, p++)
		{
			if (*p != *wd)
			{
				*flag = false;
				break;
			}
		}

		if (*flag)
		{
			return true;
		}
	}

	delete[] buffer, flag;

	return false;
}

void task2()
{
	// пользователь вводит папку и слово, программа выводит имена файлов в которых есть это слово

	char* dir = new char[255];

	char* name = new char[255];

	char* word = new char[1000];

	cout << "Enter directory: ";
	cin.ignore();
	cin.getline(dir, 255);

	cout << "Enter words: ";
	cin.getline(word, 1000);

	strcat(dir, "\\");

	strcpy(name, dir);

	strcat(name, "*.txt");

	_finddata_t list;

	long point = _findfirst(name, &list);

	FILE* file = nullptr;

	unsigned long* count = new unsigned long;

	*count = 0;

	do
	{
		strcpy(name, dir);

		strcat(name, list.name);

		file = fopen(name, "rb");

		if (file != nullptr)
		{
			if (scanFile(file, list.size, word))
			{
				cout << list.name << "     " << list.size << endl;

				*count += 1;
			}

			fclose(file);
		}
	} while (!_findnext(point, &list));

	cout << "Count files = " << *count << endl;
}
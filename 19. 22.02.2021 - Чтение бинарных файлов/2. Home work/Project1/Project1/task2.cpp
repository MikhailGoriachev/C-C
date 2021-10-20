#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// создание имени с расширением
void nameFileEdit(char name[], char source[], char exp[]);

// создание имени для файла порверки
void nameFileEdit(char name[], char source[]);

void task2()
{
	// 2. Пользователь вводит имя файла, программа делит его на
	// 2 равные части и записывает их с расширениями .part1, .part2

	char source[40], name1[40], name2[40];

	char copy[40] = "copy";

	// строки с расширениями для первого и второго файла
	char exp1[10] = ".part1";
	char exp2[10] = ".part2";

	// ввод имени исходного файла
	cout << "Enter source file name: ";
	cin >> source;

	cout << endl;

	// создание имени с расширением для первого файла
	nameFileEdit(name1, source, exp1);

	// создание имени с расширением для второго файла
	nameFileEdit(name2, source, exp2);

	// создание имени с расширением для файла проверки
	nameFileEdit(copy, source);

	// открытие исходного файла в режиме бинарного чтения
	FILE* fsource = fopen(source, "rb");

	// открытие первого файла в режиме бинарной записи
	FILE* file1 = fopen(name1, "wb");

	// открытие второго файла в режиме бинарной записи
	FILE* file2 = fopen(name2, "wb");

	if (fsource != nullptr && file1 != nullptr && file2 != nullptr)
	{
		// укзатель в исходном файле устанавливается в конец 
		fseek(fsource, 0, SEEK_END);

		// количество байтов в исходном файле 
		long size_source = ftell(fsource);

		// указатель в исходном файле устанавливается в начало
		fseek(fsource, 0, SEEK_SET);

		// количество байт для первого файла
		int size1 = size_source / 2;

		// количетсво байт для второго файла
		int size2 = size_source - size1;

		// буфер для первого файла
		char* buff1 = new char[size1];

		// буфер для второго файла
		char* buff2 = new char[size2];

		// считывание первой части исходного файла в буфер для первого файла
		fread(buff1, sizeof(char), size1, fsource);

		// считывание второй части исходного файла в буфер для второго файла
		fread(buff2, sizeof(char), size2, fsource);

		// закрытие исходного файла
		fclose(fsource);

		// запись из буфера для первого файла в первый файла
		fwrite(buff1, sizeof(char), size1, file1);

		// запись из буфера для второго файла во второй файл
		fwrite(buff2, sizeof(char), size2, file2);

		delete[] buff1, buff2;
		
		// закрытие второго файла
		fclose(file1);

		// закрытие второго файла
		fclose(file2);

		// открытие файлов в режиме для чтения 
		file1 = fopen(name1, "rb");
		file2 = fopen(name2, "rb");

		// установка указателя в первом файле в конец
		fseek(file1, 0, SEEK_END);

		// длина первого файла
		size1 = ftell(file1);

		// установка указателя в первом файле на начало
		fseek(file1, 0, SEEK_SET);

		// установка указателя во втором файле в конец
		fseek(file2, 0, SEEK_END);

		// длина второго файла
		size2 = ftell(file2);

		// установка указателя во втором файле в начало
		fseek(file2, 0, SEEK_SET);

		// длина буфера для проверочного файла
		int size_buf = size1;

		// если длина второго файла больше длины первого файла
		if (size2 > size1)
			size_buf = size2;

		// буфер для файла проверки длиной на весь исходный файл
		char* buffer = new char[size_buf];

		// открытие файла проверки в режиме записи
		FILE* copyFile = fopen(copy, "wb");

		// считывание первого файла в буфер
		fread(buffer, sizeof(char), size1, file1);

		// запись первого файла в файл проверки		
		fwrite(buffer, sizeof(char), size1, copyFile);

		// закрытие первого файла
		fclose(file1);

		// считывание второго файла в буфер
		fread(buffer, sizeof(char), size2, file2);

		// запись второго файла в файл проверки
		fwrite(buffer, sizeof(char), size2, copyFile);

		// закрытие второго файла
		fclose(file2);

		// закрытие файла проверки
		fclose(copyFile);

		cout << "Files save" << endl;
	}

	else
	{
		cout << "Error opening file" << endl;
		return;
	}
}

// создание имени с расширением
void nameFileEdit(char name[], char source[], char exp[])
{
	// длина имени
	int size = strlen(source);

	// нахождение точки расширения исходного файла
	for (size_t i = 0; source[i] != 0; i++)
	{
		if (source[i] == '.')
			size = i;
	}

	// заполение имени файла именем исходного файла
	for (int i = 0; i < size; i++)
	{
		name[i] = source[i];
	}

	name[size] = 0;

	// добавка расширения 
	char* pName = &name[strlen(name)];

	//int len = strlen(name);

	for (size_t i = 0; exp[i - 1] != 0; i++)
	{
		pName[i] = exp[i];
	}

}

// создание имени для файла порверки
void nameFileEdit(char name[], char source[])
{
	// указатель на имя исходного файла
	char* pSource = &source[0];

	int size = 0;

	// поиск пути файла 
	for (size_t i = 0; source[i] != 0; i++)
	{
		if (source[i] == '/')
		{
			pSource = &source[i + 1];
			size = i;
		}
	}

	// длина имени
	int len = strlen(name);

	char* pName = &name[len+1];

	strcpy(pName, name);

	for (size_t i = len-1, k = 0; k < len; i++, k++)
	{
		swap(name[i], name[i + 1]);
	}

	len *= 2;

	name[len] = 0;

	// смещение имени на количество симиволов имени пути файла 
	// заполнение свободного места путем файла слева от имени
	for (size_t i = 0; i <= size; i++)
	{
		name[i] = source[i];
	}

	name[len] = 0;

	// длина имени
	pName = &name[strlen(name)];

	// добвалнение имени исходного файла
	for (size_t i = 0; pSource[i - 1] != 0; i++)
	{
		pName[i] = pSource[i];
	}

	name[strlen(name)] = 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// замена всех цифр на '!'
void numDel(char a[], long size);

void task1()
{
	// 1. Пользователь вводит имя файла, программа заменяет все цифровые символы на '!'

	// имя файла
	char name[40];

	// ввод имени файла
	cout << "Enter file name: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// открытие файла в режиме битного чтения
	FILE* file = fopen(name, "rb");

	// если файл успешно открыт
	if (file != nullptr)
	{
		// установка указателя в файле в конец 
		fseek(file, 0, SEEK_END);

		// длина файла
		long size = ftell(file);

		// установка указателя в начало файла
		fseek(file, 0, SEEK_SET);

		// буфер для содержимого файла
		char* buffer = new char[size];

		// считывание файла в буфер
		fread(buffer, sizeof(char), size, file);

		// закрытие файла
		fclose(file);

		// замена всех цифр в буфере на '!'
		numDel(buffer, size);

		// открытие файла в режиме битной записи
		file = fopen(name, "wb");

		// запись в файл с буфера
		fwrite(buffer, sizeof(char), size, file);

		// удаление буфера
		delete[] buffer;

		// закрытие файла
		fclose(file);

		cout << "Save" << endl;
	}
	// если файла не удалось открыть 
	else cout << "File NOT found" << endl;
}

// замена всех цифр на '!'
void numDel(char a[], long size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
			a[i] = '!';
	}
}
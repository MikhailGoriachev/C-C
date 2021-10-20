#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task3()
{
	// 3. Пользователь вводит N имен файлов, программа объединяет их в один файл

	char name[40];

	int quan = 0;

	// ввод количества частей 
	cout << "Enter the number of files: ";
	cin >> quan;

	cout << endl;

	// если количество частей меньше единицы
	if (quan < 1)
	{
		cout << "Number must be greater than zero!" << endl;
		return;
	}

	// ввод имени файла для сохранения
	cout << "Enter the filename to save: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// открытие файла для сохранения в режиме записи
	FILE* file = fopen(name, "wb");

	// запись файла частями
	for (size_t i = 0; i < quan; i++)
	{
		// ввод имени части
		cout << "Enter name file: " << i + 1 << " : ";
		cin.getline(name, 40);

		// открытие части
		FILE* part = fopen(name, "rb");

		// если файл части успешно открыт
		if (part != nullptr)
		{
			// установка указателя в конец файла части
			fseek(part, 0, SEEK_END);

			// длина файла части
			long size = ftell(part);

			// создание буфера по длине части
			char* buff = new char[size];

			// установка указателя в начало файла части
			fseek(part, 0, SEEK_SET);

			// считываение файла части в буфер
			fread(buff, sizeof(char), size, part);

			// заполнение файла для сохранения буфером
			fwrite(buff, sizeof(char), size, file);

			// удаление буфера из оперативной памяти
			delete[] buff;

			// заркрытие файла части
			fclose(part);
		}
		else
		{
			cout << "File NOT found!" << endl;
			return;
		}
	}

	cout << endl;

	cout << "Save" << endl;

	cout << endl;

	fclose(file);

}
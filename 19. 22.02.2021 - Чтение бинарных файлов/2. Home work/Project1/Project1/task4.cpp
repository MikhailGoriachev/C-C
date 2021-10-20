#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// анализация файла в буфере
void analysis(char buff[], size_t count[], char lett[], long size);

// вывод результата
void outResult(size_t count[], char lett[]);

void task4()
{
	// 4. Пользователь вводит имя файла, программа подсчитывает частотный словарь букв файла и выводит его на экран
	//  a - 23
	//	b - 3
	//	c - 456
	//	d - 44

	// имя файла
	char name[40];

	// ввод имени файла
	cout << "Enter name file: ";
	cin.ignore();
	cin.getline(name, 40);

	// массив с количеством букв
	size_t count[52] = { 0 };

	// строка со всеми бкувами
	char lett[53] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

	// открытие файла в режиме битового чтения
	FILE* file = fopen(name, "rb");

	// если файл открыт успешно 
	if (file != nullptr)
	{
		// установка указателя в файле в конец
		fseek(file, 0, SEEK_END);

		// длина файла
		long size = ftell(file);

		// буфер для содержания файла 
		char* buff = new char[size];

		// установка указателя в файле в начало
		fseek(file, 0, SEEK_SET);

		// считываение файла в буфер
		fread(buff, sizeof(char), size, file);

		// анализация буфера
		analysis(buff, count, lett, size);

		// вывод результата
		outResult(count, lett);
	}
	// если файл не удалось открыть
	else cout << "Error opening file" << endl;
}

// анализация файла в буфере
void analysis(char buff[], size_t count[], char lett[], long size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t k = 0; lett[k] != 0; k++)
		{
			if (buff[i] == lett[k])
			{
				count[k]++;
				break;
			}
		}
	}
}

// вывод результата 
void outResult(size_t count[], char lett[])
{
	cout << endl;

	cout << "Result" << endl;

	bool n = false;

	for (size_t i = 0; lett[i] != 0; i++)
	{
		if (count[i] > 0)
		{
			cout << lett[i] << " = " << count[i] << endl;
			n = true;
		}
	}

	// если никаких букв не найдено
	if (!n)
		cout << "Letters NOT found!" << endl;
}
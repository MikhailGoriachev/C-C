#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// счётчик гласных в строке
long countVowels(char a[]);

void task1()
{
	// 1. Пользователь вводит имя файла, программа подсчитывает
	// количество гласных букв в файле(fread)

	// имена файлов
	char name1[40];

	// указатели на файл
	FILE* file;

	// количество гласных букв в файле
	long countVow = 0;

	// ввод имени певрого файла
	cout << "Enter name file 1: ";
	cin.ignore();
	cin.getline(name1, 40);

	// открытие первого файла в режиме чтения бинарного файла
	file = fopen(name1, "rb");

	// если первый и второй файл успешно открыты
	if (file != nullptr)
	{
		// ствится указатель в конец файла		
		fseek(file, 0, SEEK_END);
		
		// текущая позиция указателя в файле 
		long size = ftell(file);

		cout << "Size: " << size << endl;

		// указатель в файле перемещен на начало
		fseek(file, 0, SEEK_SET);

		// буфер длиной всех байт в файле
		char* buffer = new char[size];

		// считываение бинарного содержания файла в буфер
		fread(buffer, sizeof(char), size, file);

		// анализатор буфера возвращает количество гласных букв
		countVow = countVowels(buffer);

		for (size_t i = 0; i < size; i++)
		{
			cout << buffer[i];
		}

		cout << endl;
	}

	else
	{
		cout << "File NOT found!" << endl;
		return;
	}

	// закрытие файла
	fclose(file);

	cout << "Count vowels: " << countVow << endl;
}


// счётчик гласных букв в строке
long countVowels(char a[])
{
	char b[40] = "EeYyUuIiOoAa";

	long count = 0;

	for (size_t i = 0; a[i] != 0; i++)
	{
		for (size_t k = 0; b[k] != 0; k++)
		{
			if (a[i] == b[k])
			{
				count++;
				break;
			}
		}
	}

	return count;
}
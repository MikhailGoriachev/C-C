#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

// удаление из строки цифер
size_t delNum(char buff[]);

// переворот строки
void coupStr(char buff[], size_t size);

void task3()
{
	// 3. Пользователь вводит имя файла, программа сохраняет
	// файл в перевёрнутом виде, без цифер.	(abc 123 cde = > edc cba)

	// имя исходного файла
	char name[40];

	// ввод имени исходного файла
	cout << "Enter name source file: ";
	cin.ignore();
	cin.getline(name, 40);

	// открытие файла в режиме чтения
	FILE* file = fopen(name, "r");

	// если файл удалось успешно открыть
	if (file != nullptr)
	{
		// буфер для одной строки
		char* buff = (char*)malloc(sizeof(char) * 200);

		// количество строк
		size_t rows = 0;

		// количетсво столбцов
		size_t cols = 0;

		// подсчёт количества строк в файле 
		while (!feof(file))
		{
			fgets(buff, 199, file);

			if (ftell(file) == 0)
			{
				cout << "Error! File is empty!" << endl;
				return;
			}

			rows++;
		}

		// возврат указателя в файле на начало
		fseek(file, 0, SEEK_SET);

		// отчистка буфера 
		strcpy(buff, "");

		// двумерный массив для содержания файла
		char** content = (char**)malloc(sizeof(char*) * rows);

		// пока указатель в файле не достиг конца файла
		for (size_t i = 0; i < rows; i++)
		{
			// считывание одной строки файла в буфер
			fgets(buff, 199, file);

			// удаление из буфера цифер 
			size_t size = delNum(buff);

			// переворот строки
			coupStr(buff, size);
			
			// создание строки в двумерном массиве
			content[i] = (char*)malloc(sizeof(char) * size + 1);

			// заполнение буфера файла содержимым буфера одной строки
			strcpy(content[i], buff);

			// отчистка буфера
			strcpy(buff, "");
		}

		// удаление буфера для одной строки
		free(buff);

		// закрытие файла
		fclose(file);

		// открытие исходного файла в режиме записи
		file = fopen(name, "w");


		// заполнение файла строками из буфера
		for (size_t i = 0; i < rows; i++)
		{
			fputs(content[i], file);

			// удаление строк из двумерного массива
			free(content[i]);
		}

		// удаление двумерного массива
		free(content);

		// закрытие файла
		fclose(file);

		cout << "Save file" << endl;
	}
	// если файл не удалось открыть
	else cout << "File NOT found" << endl;
}

// удаление из строки цифер
size_t delNum(char buff[])
{
	// длина строки
	long len = strlen(buff);

	// проверка строки на цифры
	for (int i = 0; i < len; i++)
	{
		// если элемент в строке является цифрой 
		if (buff[i] >= '0' && buff[i] <= '9')
		{
			// сдвиг массива влево на один элемент
			for (size_t k = i; k < len; k++)
			{
				swap(buff[k], buff[k + 1]);
			}

			i--;

			// уменьшение длины строки
			len--;
		}
	}

	return len;
}

// переворот строки
void coupStr(char buff[], size_t size)
{
	// ввеление внутренней переменной для длины
	size_t len = size;
	


	// переворот строки 
	for (size_t i = 0, k = len - 1; i < len / 2; i++)
	{
		if (buff[k - i] == '\n')
		{
			k--;

			if (k < 2)
				break;
		}
		swap(buff[i], buff[k - i]);
	}

}

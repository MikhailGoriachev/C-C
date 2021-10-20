#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// сканирование на количество предложений и их длин в исходном файле
bool scanFile(FILE* file, long* count, long* size);

// считывание файла в двумерный массив
char** readFile(FILE* file, long* count, long* size);

// запись в результирующий файл
bool writeFile(FILE* file, char** array, long* rows);

void task1()
{
	// пользователь вводит имя файла программа обрабатывает таким 
	// образом что каждое предложение оказывается на новой строке (?!.)

	// имя файла
	char* name = (char*)malloc(sizeof(char) * 40);

	// ввод имени файла
	cout << "Enter file name: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// открытие исходного файла 
	FILE* file = fopen(name, "r");

	// если файл успешно открыт
	if (file != nullptr)
	{
		// ввод имени результирующего файла
		cout << "Enter name result file: ";
		cin.getline(name, 40);

		// указатель на массив с длинами предложений
		long* size = nullptr;

		// указатель на количество предложений
		long* count = nullptr;

		// сканировние первого файла на количество предлжений
		if (!scanFile(file, count, size))
		{
			cout << "Error! File NO read" << endl;
			return;
		}

		// исчитывание файла в двумерный массив. Функция возвращает указатель на двумерный массив
		char** array = readFile(file, count, size);
		
		// закрытие исходного файла
		fclose(file);

		// создание и открытие результирующего файла в режиме записи
		file = fopen(name, "w");

		// запись двумерного массива в результирующий файл 
		if (!writeFile(file, array, count))
		{
			cout << "Error! File NO write" << endl;
			return;
		}

		// закрытие результирующего файла
		fclose(file);
	}
	// если файл не удалось открыть
	else cout << "Error! File NOT found" << endl;
}

// сканирование на количество предложений и их длин в исходном файле
bool scanFile(FILE* file, long* count, long* size)
{
	// возврат указателя в файле на начало
	fseek(file, 0, SEEK_SET);

	// выдиление памяти для указателя count
	count = (long*)malloc(sizeof(long));

	*count = 0;

	long* p_count = count;

	// буфер одной строки
	char* buff = (char*)malloc(sizeof(char) * 400);

	// вычисление количества предложений
	while (!feof(file))
	{
		fgets(buff, 400, file);

		for (char* p_buf = buff; *p_buf; p_buf++)
		{
			if (*p_buf == '.' || *p_buf == '!' || *p_buf == '?')
			{
				*p_count += 1;
			}
		}
	}

	// если количество предложений равно нулю
	if (*count == 0)
	{
		cout << "Error! Sentence NOT found!" << endl;
		return false;
	}

	// выделение памяти для указателя на массив длин предложений
	size = (long*)malloc(sizeof(long) * *count);

	*size = 0;

	// возврат указателя в файле на начало
	fseek(file, 0, SEEK_SET);

	// длины предложений
	for (long* p_size = size; !feof(file);)
	{
		fgets(buff, 400, file);

		for (char* p_buf = buff; *p_buf; p_buf++)
		{
			// если элемент не является '\n'
			if (*p_buf != '\n')
			{
				*p_size += 1;
			}

			if (*p_buf == '.' || *p_buf == '!' || *p_buf == '?')
			{
				// переход на следующий элемент массива длин строк
				p_size++;

				*p_size = 0;
			}
		}
	}

	// возврат указателя в файле на начало
	fseek(file, 0, SEEK_SET);


	return true;
}

// считывание файла в двумерный массив
char** readFile(FILE* file, long* count, long* size)
{
	// возврат указателя в файле на начало
	fseek(file, 0, SEEK_SET);


	// создание двумерного массива
	char** array = (char**)malloc(sizeof(char) * *count);

	for (char** arr = array, *buff = (char*)malloc(sizeof(char)*400); feof(file) != 0;)
	{
		// считывание одной строки в буфер
		fgets(buff, 400, file);

		// запись в двумерный массив
		for (char* p_buff = buff; arr < array + *count && *p_buff; arr++, size++)
		{
			// создание строки в двумерном массиве
			*array = (char*)malloc(sizeof(char) * *size + 1);

			// запись поэлементно в строку
			for (char* cols = *arr; cols < *arr + *size - 1; p_buff++)
			{
				// если элемент не является '\n'
				if (*cols != '\n')
				{
					*cols = *p_buff;

					cols++;
				}
			}
		}
	}

	// вставка '\n' в конец каждоый строки двумерного массива
	for (char** arr = array; arr < array + *count; arr++)
	{
		*(*arr + *count) = '\n';
	}

	// возврат указателя в файле на начало
	fseek(file, 0, SEEK_SET);

	return array;
}

// запись в результирующий файл
bool writeFile(FILE* file, char** array, long* rows)
{
	for (char** ar = array; ar < array + *rows; ar++)
	{
		fputs(*ar, file);
	}

	if (file == file - *rows)
		return true;

	return false;
}

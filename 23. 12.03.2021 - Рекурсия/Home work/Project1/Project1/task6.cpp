#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// сканирование на количество предложений и их длин в исходном файле
bool countSentence(FILE* file, long* count);

// считывание файла в двумерный массив
char** readFile(FILE* file, long* count, long* size);

// запись в результирующий файл
void writeFile(FILE* file, char** array, long* rows);

// длина каждой строки
void sizeSentence(FILE* file, long* size);

void task6()
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

		// указатель на количество предложений
		long* count = (long*)malloc(sizeof(long));

		// сканировние первого файла на количество предлжений
		if (!countSentence(file, count))
		{
			cout << "Error! File NO read" << endl;
			return;
		}

		// указатель на массив с длинами предложений
		long* size = (long*)malloc(sizeof(long) * *count);

		sizeSentence(file, size);

		// исчитывание файла в двумерный массив. Функция возвращает указатель на двумерный массив
		char** array = readFile(file, count, size);

		// закрытие исходного файла
		fclose(file);

		// создание и открытие результирующего файла в режиме записи
		file = fopen(name, "w");

		// запись двумерного массива в результирующий файл 
		writeFile(file, array, count);

		// закрытие результирующего файла
		fclose(file);
	}
	// если файл не удалось открыть
	else cout << "Error! File NOT found" << endl;
}

// сканирование на количество предложений и их длин в исходном файле
bool countSentence(FILE * file, long* count)
{
	// возврат указателя в файле на начало
	fseek(file, 0, SEEK_SET);

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

	free(buff);

	// если количество предложений равно нулю
	if (*count == 0)
	{
		cout << "Error! Sentence NOT found!" << endl;
		return false;
	}

	return true;
}

void sizeSentence(FILE* file, long* size)
{
	// выделение памяти для указателя на массив длин предложений
	*size = 0;

	// возврат указателя в файле на начало
	fseek(file, 0, SEEK_SET);

	char* buff = (char*)malloc(sizeof(char) * 400);

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
				*p_size += 2;

				//p_size -= 1;
				p_buf++;

				if (*p_buf == 0)
					break;

				// переход на следующий элемент массива длин строк
				p_size++;

				*p_size = 0;
			}

		}
	}

	// возврат указателя в файле на начало
	fseek(file, 0, SEEK_SET);

	free(buff);
}

// считывание файла в двумерный массив
char** readFile(FILE * file, long* count, long* size)
{
	// возврат указателя в файле на начало
	fseek(file, 0, SEEK_SET);

	// создание двумерного массива
	char** array = (char**)malloc(sizeof(char) * *count);

	// первая строка
	*array = (char*)malloc(sizeof(char) * *size + 1);

	long* p_size = (long*)malloc(sizeof(size));

	p_size = size;

	for (char** arr = array, *buff = (char*)malloc(sizeof(char) * 400), *cols = *arr; feof(file) == 0;)
	{
		// считывание одной строки в буфер
		fgets(buff, 400, file);

		// запись в двумерный массив
		char* p_buff = buff; 


		// запись поэлементно в строку
		for (; cols <= *arr + *p_size; p_buff++)
		{
			// если элемент не является '\n'
			if (*p_buff == '\n')
			{
				break;
			}

			if (*p_buff == '.')
			{
				arr++;

				p_size++;

				// создание строки в двумерном массиве
				*arr = (char*)malloc(sizeof(char) * *size + 1);

				*cols = *p_buff;

				cols = *arr;


				break;
			}

			*cols = *p_buff;
			cols++;
		}
	}

	p_size = size;

	// вставка '\n' в конец каждоый строки двумерного массива
	for (char** arr = array; arr < array + *count; arr++, p_size)
	{
		*(*arr + *p_size) = 0;
		*(*arr + *p_size - 1) = '\n';
	}

	// возврат указателя в файле на начало
	fseek(file, 0, SEEK_SET);

	return array;
}

// запись в результирующий файл
void writeFile(FILE * file, char** array, long* rows)
{
	for (char** ar = array; ar < array + *rows; ar++)
	{
		fputs(*ar, file);
	}
}

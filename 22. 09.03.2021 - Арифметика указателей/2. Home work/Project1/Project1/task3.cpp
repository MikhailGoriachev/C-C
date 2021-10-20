#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

// создание имени для результирующего файла
FILE* createFile(char name_file[]);

// вычисление количества строк и столбцов в файле возвращает указатель 
// на массив с количетсвом столбцов каждой строки
// 1 - файл удалось считать
// 2 - неудачно/файл пуст
long* sizeStr(long* rows, FILE* file);

// считываение файла в двумерный массив. возвращает 0 - неудачно, 1 - удачно
bool readFile(char** arr, FILE* file, long* rows, long* cols);

// переворот всех чисел в строках двумерного массива
void coupNum(char** arr, long* rows, long* count);

// запись в файл из двумерного массива
bool writeFile(char** array, FILE* file, long* rows);

void task3()
{
	// 3. Пользователь вводит имя текстового файла, программа переворачивает 
	// в файле все слова-числа наоборот и записывает результат в файл.
	//
	//	У бабушки было 234 кота.
	//
	//	У бабушки было 432 кота.

	// имя исходного текстового файла
	char* name = (char*)malloc(sizeof(char) * 40);

	// ввод имени исходного текстового файла
	cout << "Enter source name file: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	// открытие исходного файла в режиме чтения
	FILE* file = fopen(name, "r");

	// если файл открыт успешно
	if (file != nullptr)
	{
		// количество найденных чисел
		long* count = (long*)malloc(sizeof(long));

		*count = 0;

		// вычисление количества строк и столбцов в файле
		// количество строк
		long* rows = (long*)malloc(sizeof(long));

		// вычисление количества строк и столбцов в файле
		// возвращает указатель на массив с длинами всех строк
		long* cols = sizeStr(rows, file);

		// если указатель на массив с длинами чисел нулевой - файл пуст
		if (cols == nullptr)
		{
			cout << "Error! File is empty!" << endl;
			return ;
		}

		// двумерный массив для содержимого файла
		char** array = (char**)malloc(sizeof(char*) * *rows);

		// уккзатель на длину строки
		long* p_cols = cols;

		// создание строк двумерного массива
		for (char** p_ar = array; p_cols < cols + *rows; p_cols++, p_ar++)
		{
			*p_ar = (char*)malloc(sizeof(char) * *p_cols + 1);
		}

		// считываение файла в дувмерный массив
		if (!readFile(array, file, rows, cols))
		{
			cout << "Error! File NOT read!" << endl;
			return;
		}

		// закрытие исходного файла
		fclose(file);

		// переворот всех чисел в строках двумерного массива
		coupNum(array, rows, count);

		// имя результирующего файла
		char* res_name = (char*)malloc(sizeof(char) * 40);

		// содание имени результирующего файла
		file = createFile(name);

		// если файл открыт неудачно
		if (file == nullptr)
		{
			cout << "Error! File NOT Found!" << endl;
			return;
		}

		// запись из дувмерного массива в результирующий файл
		if (!writeFile(array, file, rows))
		{
			cout << "Error! File NOT write!" << endl;
			return;
		}

		// отчитска памяти от двумерного массива
		for (char** rows_ar = array; rows_ar < array + *rows; rows_ar++)
		{
			free(*rows_ar);
		}

		free(array);

		// отчистка оперативной памяти
		free(res_name);
		free(rows);
		free(cols);

		// закрытие результирующего файла
		fclose(file);

		cout << "Count number: " << *count << endl;
		cout << endl;
		cout << "Save" << endl;
	}
	// если файл не удалось открыть
	else cout << "Error! File NOT found!" << endl;
	
	// отчистка оперативной памяти
	free(name);
}

// создание имени для результирующего файла
FILE* createFile(char name_file[])
{
	// строка для вставки в начало имени
	char* result = (char*)malloc(sizeof(char) * 10);

	// заполнение строки вставки
	strcpy(result, "result_");

	// длина строки вставки
	int* len_result = (int*)malloc(sizeof(int));

	*len_result = strlen(name_file) - 1;

	// редактирование имени
	char* name, * end = name_file + strlen(name_file);

	// поиск начала имени
	for (name = end; name >= name_file; name--)
	{
		// если указатель равен окончанию записи пути директории
		if (*name == '\\' || *name == '/')
		{
			// начало имени
			name++;
			break;
		}
	}

	// если имя файла указано без директории
	if (name < name_file)
	{
		name = name_file;
	}

	// смещение имени вправо, чтоб освободить место для вставки
	for (char* orig = name; orig < name + (*len_result - 1); orig++)
	{
		// смещение 
		for (char* point = end; point > orig ; point--)
		{
			swap(*point, *(point - 1));
		}

		// увеличение длины строки имени на один элемент
		end++;
	}

	*end = 0;

	// вставка перед именем ключевого слова
	for (char* point = result, *p_name = name; *point; point++, p_name++)
	{
		*p_name = *point;
	}

	// освобождение оперативной памяти
	free(result);
	free(len_result);

	// открытие файла в режиме записи
	FILE* file = fopen(name_file, "w");

	return file;
}

// вычисление количества строк и столбцов в файле возвращает указатель на 
// массив количества столбцов каждой строки
// 1 - файл удалось считать
// 2 - неудачно/файл пуст
long* sizeStr(long* rows, FILE* file)
{
	// инициализирование
	*rows = 0;

	// установка указателя в файле на начало
	fseek(file, 0, SEEK_SET);

	// буфер для временного хранения строки
	char* buffer = (char*)malloc(sizeof(char) * 400);

	// подсчёт количества строк
	while (!feof(file))
	{
		// считывание в буфер
		char* s = fgets(buffer, 399, file);

		// если указатель на считанную стоку нулевой
		if (s == nullptr)
		{
			return nullptr;
		}

		*rows += 1;
	}

	// установка указателя в файле на начало
	fseek(file, 0, SEEK_SET);

	// массив для хранения длин каждой строки
	long* cols = (long*)malloc(sizeof(long) * *rows);

	// заполнение массива длин строк
	while (!feof(file))
	{
		// считывание строки в буфер
		fgets(buffer, 399, file);

		// длина строки
		*cols = strlen(buffer) + 1;

		// переход на следующее значение
		cols++;

		// отчистка буфера 
		strcpy(buffer, "");
	}

	// возрат указателя в массиве длин строк в начало
	cols -= *rows;

	// возврат указателя в начало 
	fseek(file, 0, SEEK_END);

	// отчистка оперативной памяти
	free(buffer);

	// возвращение укащателя на масив 
	return cols;
}

// считываение файла в двумерный массив. возвращает 0 - неудачно, 1 - удачно
bool readFile(char** arr, FILE* file, long* rows, long* cols)
{
	// установка указателя в файле в начало
	fseek(file, 0, SEEK_SET);

	// счётчик считанных строк
	long* count = (long*)malloc(sizeof(long));

	*count = 0;

	// указатель на массив с длинами строк
	long* size = cols;

	// считывание в массив построчно
	for (char** rows_ar = arr; rows_ar < arr + *rows ; rows_ar++, cols++)
	{
		// считывание строки из файла в строку двумерного массива
		fgets(*rows_ar, *cols, file);

		// увеличение счётчика считанных строк
		*count += 1;
	}

	// если количество считанных строк не совпадает с количеством строк в файле
	if (*count != *rows)
	{
		// отчистка памяти 
		free(count);

		return false;
	}

	return true;
}

// переворот всех чисел в строках двумерного массива
void coupNum(char** arr, long* rows, long* count)
{
	// сканирование массива
	for (char** rows_ar = arr; rows_ar < arr + *rows ; rows_ar++)
	{
		// сканирование строки
		for (char* cols_ar = *rows_ar, *start = nullptr, *end = nullptr; *cols_ar; cols_ar++)
		{
			// если элемент строки является цифрой
			if (*cols_ar >= '0' && *cols_ar <= '9')
			{
				// если указатель на начало числа равен нулю и/или является началом строки или прошлый
				// элемент является пробелом
				if (start == nullptr && (*(cols_ar - 1) == ' ' || cols_ar == *rows_ar))
				{
					start = cols_ar;
				}

				// если указатель на начало числа не ровняется нулю
				if (start != nullptr)
				{
					// указатель на окончание числа
					end = cols_ar;

					// если следующий элемент не цифра
					if (*(cols_ar + 1) < '0' || *(cols_ar + 1) > '9')
					{
						// увеличение счётчика найденных чисел
						*count += 1;

						// если число состоит из одной цифры
						if (end == nullptr)
						{
							start = nullptr;
							continue;
						}

						// переворот числа
						for (; start < end; start++, end--)
						{
							swap(*start, *end);
						}

						// обнуление указателей
						start = nullptr;
						end = nullptr;

						continue;
					}
				}
			}
		}
	}
}

// запись в файл из двумерного массива
bool writeFile(char** array, FILE* file, long* rows)
{
	// установка указателя в файле на начало
	fseek(file, 0, SEEK_SET);

	long* count = (long*)malloc(sizeof(long));

	*count = 0;

	// запись в файл
	for (char** rows_ar = array; rows_ar < array + *rows; rows_ar++)
	{
		// запись строки из двумерного массива в файл
		fputs(*rows_ar, file);

		// увеличение счётчика
		*count += 1;
	}

	// проверка счётчика записанных строк, с количеством строк двумерного массива
	if (*count != *rows)
	{
		// отчитска памяти
		free(count);

		return false;
	}

	free(count);

	return true;
}
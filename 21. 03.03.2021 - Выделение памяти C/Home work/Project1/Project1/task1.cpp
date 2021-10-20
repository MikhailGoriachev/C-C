#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

// создание и заполнение второго файла (бинарный)
void fileCreate(char buff[], long size, char name[]);

// создание и заполнение второго файла (текстовый)
void fileCreate(char** source, char name[], long rows, long cols[]);


void task1()
{
	// 1. Пользователь вводит имя файла, программа увеличивает 
	// все слова-числа на 1 и сохраняет результат в другой файл.

	// имя файла
	char name[40];

	// ввод имени файла
	cout << "Enter file name: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	FILE* source = nullptr;

	// открытие исходного файла в режиме текстового файла
	source = fopen(name, "r");


	// если файла успешно 
	if (source != nullptr)
	{
		// количество строк 
		long rows = 0;

		// подсчет количества строк и столбцов
		while (!feof(source))
		{
			char* buff = (char*)malloc(sizeof(char) * 200);
			fgets(buff, 199, source);

			rows++;

			free(buff);
		}

		fseek(source, 0, SEEK_SET);

		long* cols = (long*)malloc(sizeof(long) * rows);

		// двумерный массив по количеству строк
		char** buff = (char**)malloc(sizeof(char*) * rows);

		for(size_t i = 0; i < rows; i++)
		{
			// буфер для одной строки
			char* temp = (char*)malloc(sizeof(char) * 200);

			// запись одной строки в буфер
			fgets(temp, 199, source);

			// длина строки
			cols[i] = strlen(temp);

			// создание строки двумерного массива по длине строки из буфера
			buff[i] = (char*)malloc(sizeof(char) * cols[i] + 1);

			// запись строки из буфера в строку двумерного массива
			strcpy(buff[i], temp);

			// отчистка буфера
			free(temp);
		}

		fileCreate(buff, name, rows, cols);
		
		// закрытие исходного файла
		fclose(source);
	}

	else cout << "File NOT found" << endl;
}

// создание и заполнение второго файла (тестовый)
void fileCreate(char** source, char name[], long rows, long cols[])
{
	// показатель других симфолов не цифр
	bool symb = false;

	// количество слов-чисел
	long num_count = 0;


	// количество чисел в строке
	long* num_count_str = (long*)malloc(sizeof(long) * rows);

	// поиск слов-цифер в буфере исходного файла
	for (size_t i = 0; i < rows; i++)
	{
		// обнуление счётчика чисел текущей строки
		num_count_str[i] = 0;

		for (size_t k = 0; k < cols[i] + 1; k++)
		{
			// ПРОБЕЛ
			if (source[i][k] == ' ')
			{
				// обнуление показателя символов
				symb = false;
			}

			// ЦИФРА
			if (source[i][k] >= '0' && source[i][k] <= '9')
			{
				// если следующий символ пробел то увеличивается количество слов-чисел
				if (source[i][k + 1] < '0' || source[i][k + 1] > '9')
				{
					// количество чисел в текущей строке
					num_count_str[i]++;

					// общий счётчик чисел
					num_count++;
				}
				continue;
			}

			// СИМВОЛЫ (НЕ ЦИФРЫ И НЕ ТОЧКА)
			if (source[i][k] != '.')
			{
				symb = true;
			}
		}
	}

	// вывод количества слов-чисел в консоль
	cout << "Count number = " << num_count << endl;

	cout << endl;

	// показатель цифр
	bool num = false;

	// показатель точки
	bool dot = false;

	// показатель других симфолов не цифр
	symb = false;

	// длина числа
	long size_num = 0;

	// временный буфер для одного слова
	char* temp = (char*)malloc(sizeof(char) * 200);

	// создание буфера для второго файла длиной с возможным увеличением по количеству чисел 
	char** buff = (char**)malloc(sizeof(char*) * rows);



	// копировние текущего буфера 
	for (size_t i = 0; i < rows; i++)
	{
		// создание строки двумерного массива
		buff[i] = (char*)malloc(sizeof(char) * ++cols[i] + 1 + num_count_str[i]);
		for (size_t k = 0; k < cols[i]; k++)
		{
			buff[i][k] = source[i][k];
			if (k + 1 == cols[i])
			{
				buff[i][k + 1] = 0;
			}
		}
	}


	for (size_t i = 0, poz_Y = 0, poz_X = 0, len = 0; i < rows; i++)
	{
		// длина 
		long len_line = strlen(buff[i]);
		for (size_t k = 0; k < cols[i]; k++)
		{
			// ПРОБЕЛ
			if (buff[i][k] == ' ' || k + 1 == cols[i])
			{
				// если это слово-число
				if (num && strlen(temp) > 0)
				{
					// если длина исходного числа меньше, чем результат
					if (len < strlen(temp))
					{
						// увеличение общей длины
						cols[i]++;

						// сдвиг строки на один элемент для освобождения места
						for (int k = cols[i]; k >= poz_X + 1; k--)
						{
							swap(buff[i][k], buff[i][k - 1]);
						}
					}

					buff[i][cols[i]] = 0;

					// указатель начало числа в буфере 
					char* p = &buff[poz_Y][poz_X];

					// копирование строки с числом в буфер 
					for (size_t k = 0; temp[k] != 0; k++)
					{
						p[k] = temp[k];
					}

					// обнуление длины исходного числа
					len = 0;

					// отчистка буфера 
					strcpy(temp, "");
				}

				// обнуление показателя цифр
				num = false;

				// обнуление показателя точек
				dot = false;

				// обнуление показателя символов
				symb = false;

				// обнуление длины числа
				size_num = 0;

				continue;
			}

			// ЦИФРА
			if (buff[i][k] >= '0' && buff[i][k] <= '9' && !symb && !dot)
			{
				// позиция начала числа
				if (num == false)
				{
					poz_Y = i;
					poz_X = k;
				}

				// заполнение временного буфера одного числа символом цифры
				temp[size_num++] = buff[i][k];

				// если следующий символ пробел то увеличивается количество слов-чисел
				if (buff[i][k + 1] < '0' || buff[i][k + 1] > '9' || buff[i][k + 1] == 0)
				{
					// символ оконачания строки
					temp[size_num] = 0;

					// длина исходного числа
					len = strlen(temp);

					// число увеличивается на 1
					long numb = atoi(temp) + 1;

					// конвертирование полученного числа обратно в строку
					_itoa(numb, temp, 10);
				}

				num = true;

				continue;
			}

			// ТОЧКА
			if (buff[i][k] == '.')
				dot = true;

			// СИМВОЛЫ (НЕ ЦИФРЫ И НЕ ТОЧКА)
			if (buff[i][k] != '.')
			{
				symb = true;
			}
		}
	}

	// создание имени файла для сохранения
	
	// длина исходного имени
	size_t len = strlen(name);

	// позиция слеша
	int poz = 0;

	// поиск позиции последнего слеша пути
	for (int i = len - 1; i >= 0; i--)
	{
		if (name[i] == '/' || name[i] == '\\')
		{
			poz = i + 1;
			break;
		}
	}

	// сдвиг имени на четыре элемента
	for (size_t i = 0; i < 4; i++)
	{
		for (int k = len; k > poz; k--)
		{
			swap(name[k], name[k - 1]);
		}
		len++;
	}

	name[len] = 0;

	// заполнение начала имени словом "copy"
	name[poz] = 'c';
	name[poz + 1] = 'o';
	name[poz + 2] = 'p';
	name[poz + 3] = 'y';

	// создание и открытие файла для сохранения в режиме бинарной записи 
	FILE* file = fopen(name, "wb");

	// если файл создан и открыт успешно
	if (file != nullptr)
	{
		// запись в файл
		for (size_t i = 0; i < rows; i++)
		{
			fputs(buff[i], file);
			free(buff[i]);
		}

		free(buff);

		// сохранение файла
		fclose(file);

		cout << "File save" << endl;

		cout << endl;

	}
	else cout << "Error create file" << endl;
}

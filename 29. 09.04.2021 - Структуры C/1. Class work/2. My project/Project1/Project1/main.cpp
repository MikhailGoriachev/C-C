#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void comb(char** board, const int size, int count)
{
	// показатель пригодности координат
	bool* flag = new bool;

	*flag = true;


	// установка ферзя
	for (char** y = board; *y < board[size]; y++)
	{
		for (char* x = *y; x < *y + size; x++)
		{
			// проверка расположея не попадает ли ферзь под удар других ферзей
			// проверка по горизонтали
			for (char* x_pr = *y; x_pr < *y + size; x_pr++)
			{
				// если найдена корона 'W'
				if (*x_pr == 'W')
				{
					*flag = false;

					break;
				}
					
			}

			// проверка по вертикали
			for (char** y_pr = board; y_pr < board + size; y_pr++)
			{
				// если найдена корона 'W'
				if (**y_pr == 'W')
				{
					*flag = false;

					break;

				}
			}

			int* i = new int;

			*i = 0;

			// проверка наклонной в влево вверх 
			for (char** y_pr = y, * x_pr = x; ; y_pr--, *y_pr -= 1)
			{
				// если найдена корона 'W'
				if (**y_pr == 'W')
				{
					*flag = false;

					break;
				}

				// если по x это послежний элемент
				if (x_pr == *y_pr || y_pr == board)
				{
					break;
				}
			}

			// если координаты пригодны
			if (*flag)
			{
				*x = 'W';

				// если текущая ладья не является по счёту восьмой
				// запуск функции рекурсивно
				if (count < 8)
				{
					comb(board, size, ++count);
				}
			}
		}
	}

	
}

void main()
{
	// 8 ферзей программа расставляет на шахматной доске, чтоб они друг друга не били. Прогрмамма находит все комбинации.

	const int size = 8;

	// двумерный массив шахматной доски
	char** board = new char*[size];
	
	// счётчик для цикла
	int* color = new int;

	*color = 0;

	// заполнение шахматной доски полями
	for (char** b = board; b < board + size; b++)
	{
		*b = new char[size + 1];
		for (char* n = *b; n < *b + size; n++, ++*color)
		{
			// если черное то X
			if (*color % 2 == 0)
			{
				*n = (int)'X';
			}

			// если белое то O
			if (*color % 2 == 1)
			{
				*n = (int)'O';
			}
		}
	}

	// вызов функции
	comb(board, size, 0);
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

using namespace std;

// вывод шахматной доски
void printBoard(int** board);

void comb(int** board, int y, int* count, FILE** file);

// сохранение текущей доски в файл
void saveBoard(FILE** file, int** board, int* count);

void main()
{
	// программа вычисляет все комбинации расстановки восьми ферзей
	// на шахматной доске таким образом, чтоб они не перебивали друг 
	// друга

	// константа длины одной стороны
	int* size = new int;

	*size = 8;

	// двумерный динамический массив - шахматная доска
	int** board = new int* [*size];

	// счётчик
	int* i = new int;

	*i = 1;

	// создание одномерных массивов для двумерного массива
	for (int** _board = board; _board < board + *size; _board++)
	{
		*_board = new int[*size];

		// заполнение ячеек: 1 - белый, 0 - чёрный
		for (int* x = *_board; x < *_board + *size; x++)
		{
			// если счётчик без остатка делится на 8
			if (*i % 9 == 0)
				++* i;

			// если значение счётчика без остатка делится на два - черный(0)
			if (*i % 2 == 0)
			{
				*x = 0;
			}

			// если значение счётчика делится с остатком на два - белый(1)
			if (*i % 2 == 1)
			{
				*x = 1;
			}
			++* i;
		}
	}

	// отчистка памяти
	delete i;

	// счётчик количества найденных комбинаций
	int count = 0;

	// указатель на указатель на файл
	FILE** file = new FILE*;

	// создание и открытие результирующего файла
	*file = fopen(".\\result.txt", "w");

	// запуск рекурсивной функции поиска комбинаций
	comb(board, 0, &count, file);

	// закрытие файла
	fclose(*file);

	// отчистка памяти
	for (int** y = board; y < board + 8; y++)
	{
		delete *y;
	}

	delete board;

	cout << endl;

	cout << "\n\n\n\nPRESS ANY KEY..." << endl;

	_getch();
}

// вывод шахматной доски
void printBoard(int** board)
{
	for (int** _board = board; _board < board + 8; _board++)
	{
		for (int* x_board = *_board; x_board < *_board + 8; x_board++)
		{
			// если значение 1
			if (*x_board == 1)
			{
				cout << " O ";
			}

			// если значение 0
			if (*x_board == 0)
			{
				cout << " X ";
			}

			// если значение 3
			if (*x_board == 3)
			{
				cout << " W ";
			}
		}

		cout << endl << endl;
	}

}

// сохранение текущей доски в файл
void saveBoard(FILE** file, int** board, int* count)
{
	fprintf(*file, "------------------ %i -------------------\n\n", *count);

	for (int** y = board; y < board + 8; y++)
	{
		for (int* x = *y; x < *y + 8; x++)
		{
			// если значение 1
			if (*x == 1)
				fprintf(*file, "  O  ");

			// если значение 2 
			else if (*x == 0)
				fprintf(*file, "  X  ");

			// если значение 3
			else if (*x == 3)
				fprintf(*file, "  W  ");
		}

		fprintf(*file, "\n\n");
	}

	fprintf(*file, "\n\n\n");
}

// поиск комбинаций
void comb(int** board, int y, int* count, FILE** file)
{
	// флаг 
	bool flag = true;
	
	// позиция по x
	int x = -1;

	// временное хранение значения клетки доски
	int temp;

	while (true)
	{
		// точка goto
		point:

		if (x == 7)
		{
			return;
		}

		// увеличение позиции по x
		x++;

		int yy, xx;

		// проверка по вертикали
		for ( yy = 0; yy < 8; yy++)
		{
			// если наёден ферзь по вертикали
			if (board[yy][x] == 3)
			{
				flag = false;

				// переход на точку
				goto point;

				break;
			}
		}

		// проверка по горизонтали
		for ( xx = 0; xx < 8; xx++)
		{
			// если найден ферзь по горизонтали
			if (board[y][xx] == 3)
			{
				flag = false;

				// переход на точку
				goto point;

				break;
			}
		}


		// проверка от текущей позиции к левому верхнему углу
		for ( xx = x, yy = y; xx > -1 && yy > -1; xx--, yy--)
		{
			// если найден ферзь
			if (board[yy][xx] == 3)
			{
				flag = false;

				// переход на точку
				goto point;

				break;
			}
		}


		// проверка от текущей позиции к правому нежнему углу
		for ( xx = x, yy = y; xx < 8 && yy < 8; xx++, yy++)
		{
			// если найден ферзь
			if (board[yy][xx] == 3)
			{
				flag = false;

				// переход на точку
				goto point;

				break;
			}
		}

		// проверка от текущей позиции к левому нижнему углу
		for ( xx = x, yy = y; xx > -1 && yy < 8; xx--, yy++)
		{
			// если найден ферзь
			if (board[yy][xx] == 3)
			{
				flag = false;

				// переход на точку
				goto point;

				break;
			}
		}

		// проверка от текущей позиции к правому верхнему углу
		for ( xx = x, yy = y; xx < 8 && yy > -1; xx++, yy--)
		{
			// если найден ферзь 
			if (board[yy][xx] == 3)
			{
				flag = false;

				// переход на точку
				goto point;

				break;
			}
		}

		
		// сохранение элемента доски в буфер
		temp = board[y][x];

		// установка W на текущее место
		board[y][x] = 3;

		// если это не последний ряд
		if (y < 7)
		{
			// рекурсивный запуск функции
			comb(board, y + 1, count, file);
		}

		// увеличение счётчика удачных комбинаций
		else
		{
			++* count;
			
			system("cls");

			printBoard(board);

			cout << "Count: " << *count << endl;

			saveBoard(file, board, count);
		}

		// удаление ферзя с текущей позиции
		board[y][x] = temp;
	}
}
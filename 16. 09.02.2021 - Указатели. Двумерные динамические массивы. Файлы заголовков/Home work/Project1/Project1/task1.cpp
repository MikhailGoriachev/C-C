#include <iostream>
#include <time.h>

using namespace std;

// функция вывода двумерного массива (задание 1)
void out2DArrayTask1(int** a, size_t rows, size_t cols);


void task1()
{
	srand(time(0));
	// 1. Пользователь вводит количество строк двумерного динамического массива, программа выводит массив такой формы:
	//	5 5 5 5 5
	//	5 5 5 5
	//	5 5 5
	//	5 5
	//	5

	//	Заполнить случайными числами

	size_t rows;

	cout << "Enter rows: ";
	cin >> rows;

	cout << endl;

	// создание динамического двумерного массива 
	int** a = new int* [rows];

	// создание длины строк 
	for (size_t i = 0, j = rows; i < rows; i++, j--)
	{
		a[i] = new int[j];
		// заполнение строки рандомными числами
		for (size_t k = 0; k < j; k++)
		{
			a[i][k] = rand() % 10;
		}
	}

	// вывод двумерного динамического массива
	out2DArrayTask1(a, rows, rows);

	delete[] a;
}

// функция вывода двумерного массива
void out2DArrayTask1(int** a, size_t rows, size_t cols)
{
	for (size_t i = 0, j = rows; i < rows; i++, j--)
	{
		for (size_t k = 0; k < j; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}
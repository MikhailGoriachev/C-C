#include <iostream>

using namespace std;

// ввод двумерного динамического массива
void enter2DArray(int** a, size_t rows, size_t cols);

// вывод двумерного динамического массива
void out2DArray(int** a, size_t rows, size_t cols);

// функция переворота двумерного массива на 90 градусов 
void coup2DArray(int** a, int** b, size_t rows, size_t cols);

void task3()
{
	// 3. Пользователь водит размеры и сам двумерный динамический 
	// массив.Программа поворачивает его на 90 градусов по часовой
	// стрелке и результат копирует в другой массив : 3х4 = > 4x3

	int rows, cols;

	// ввод количеста строк
	cout << "Enter rows: ";
	cin >> rows;

	// ввод количества рядов
	cout << "Enter cols: ";
	cin >> cols;

	// создание первого двумерного массива
	int** a = new int* [rows];

	// создание второго двумерного массива
	int** b = new int* [cols];

	for (size_t i = 0; i < cols; i++)
	{
		b[i] = new int[rows];
	}


	// ввод массива
	enter2DArray(a, rows, cols);

	cout << endl;

	// вывод массива
	out2DArray(a, rows, cols);

	cout << endl;

	// заполнение второго массива перевернутым на 90 градусов первым
	coup2DArray(a, b, rows, cols);

	cout << "Result" << endl;

	cout << endl;

	// вывод второго масива 
	out2DArray(b, cols, rows);
	
	cout << endl;

	delete[] a, b;
}

// ввод двумерного динамического массива
void enter2DArray(int** a, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		a[i] = new int[cols];
		for (size_t k = 0; k < cols; k++)
		{
			cout << "Enter element [" << i << "][" << k << "]: ";
			cin >> a[i][k];
		}
		cout << endl;
	}
}

// вывод двумерного динамического массива
void out2DArray(int** a, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < cols; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}

// функция переворота двумерного массива на 90 градусов 
void coup2DArray(int** a, int** b, size_t rows, size_t cols)
{
	// заполнение второго массива перевёрнутым на 90 градусов первым
	for (size_t i = 0, n = 0; i < cols; i++)
	{
		for (size_t k = 0, n = rows-1, m = i; k < rows; k++)
		{
			b[i][k] = a[n--][m];
		}
	}
}
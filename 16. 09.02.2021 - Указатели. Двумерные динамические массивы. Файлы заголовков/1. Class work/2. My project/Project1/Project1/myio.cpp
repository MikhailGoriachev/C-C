#include <iostream>

using namespace std;

// ФАЙД С ФУНКЦИЯМИ

// ввод двумерного динамичекого массива
void enter2DArray(int** a, size_t height, size_t width)
{
	for (size_t i = 0; i < height; i++)
	{
		for (size_t k = 0; k < width; k++)
		{
			cin >> a[i][k];
		}
		cout << endl;
	}
}

void enter2DArray(char** a, size_t height, size_t width)
{
	for (size_t i = 0; i < height; i++)
	{
		for (size_t k = 0; k < width; k++)
		{
			cin >> a[i][k];
		}
		cout << endl;
	}
}

// вывод двумерного масива
void print2DArray(int** a, size_t height, size_t width)
{
	for (size_t i = 0; i < height; i++)
	{
		for (size_t k = 0; k < width; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}

void print2DArray(char** a, size_t height, size_t width)
{
	for (size_t i = 0; i < height; i++)
	{
		for (size_t k = 0; k < width; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}
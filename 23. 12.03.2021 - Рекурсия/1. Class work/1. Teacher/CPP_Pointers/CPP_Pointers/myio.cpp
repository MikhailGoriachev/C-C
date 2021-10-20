#include <iostream>

using namespace std;

// ввод двумерного массива с клавиатуры
void enter2DCharArray(char a[3][4])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cin >> a[i][k];
		}
	}
}

// печать двумерного массива
void print2DCharArray(char a[3][4])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// ввод двумерного массива с клавиатуры
void enter2DArray(int** a, size_t width, size_t height)
{
	for (size_t i = 0; i < height; i++)
	{
		for (size_t k = 0; k < width; k++)
		{
			cin >> a[i][k];
		}
	}
}

void enter2DArray(char** a, size_t width, size_t height)
{
	for (size_t i = 0; i < height; i++)
	{
		for (size_t k = 0; k < width; k++)
		{
			cin >> a[i][k];
		}
	}
}

void print2DArray(int** a, size_t width, size_t height)
{
	for (size_t i = 0; i < height; i++)
	{
		for (size_t k = 0; k < width; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void print2DArray(char** a, size_t width, size_t height)
{
	for (size_t i = 0; i < height; i++)
	{
		for (size_t k = 0; k < width; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
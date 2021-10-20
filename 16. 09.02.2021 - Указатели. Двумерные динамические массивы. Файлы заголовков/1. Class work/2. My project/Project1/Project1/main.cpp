#include <iostream>

// подключенеи файла заголовков
#include "myio.h"
using namespace std;

// задание 1
int numRevers(float a);

// задание 2
void task2();

// задание 3
void task3();

void main()
{
	int num;

	cout << "Enter Task: ";
	cin >> num;

	if (num == 1)
	{
		// число переворачивется
		float n;

		cout << "Enter num: ";
		cin >> n;

		n = numRevers(n);

		cout << "Result: " << n << endl;
	}

	// ДВУМЕРНЫЕ ДИНАМИЧЕСКИЕ МАССИВЫ
	if (num == 2)
	{
		task2();
	}

	if (num == 3)
	{
		task3();
	}
}

// задание 1
int numRevers(float num)
{
	// длина числа
	int size = 0;

	int temp = num;

	for (size_t i = 0; ; i++)
	{
		if ((int)temp != 0)
		{
			temp /= 10;
			size++;
		}
		else
			break;
	}

	temp = num;

	// текущая цифра
	int n = 0;

	int num1 = 0;

	for (size_t i = 0; i < size; i++)
	{
		temp = num;

		for (size_t k = 0;;k++)
		{
			if (temp / 10 != 0)
				temp /= 10;
			if (temp / 10 == 0)
			{
				if (i == 0)
					k++;
				n = temp;
				if (i >= 1)
				{
					for (size_t j = 0; j < i; j++)
					{
						n *= 10;
					}
				}


				num1 += n;

				for (size_t w = 1; w < i; w++)
				{
					n /= 10;
				}
					

				for (size_t j = 0; j < k; j++)
				{
					n *= 10;
				}

				

				num -= n;

				break;
			}
			
		}
		
	}

	return num1;
}

// задание 2
void task2()
{
	// ДВУМЕРНЫЕ ДИНАМИЧЕСКИЕ МАССИВЫ
	size_t rows;
	size_t cols;

	// ввод размера двумерного массива

	cout << "Enter rows number: ";
	cin >> rows;

	cout << "Enter cols number: ";
	cin >> cols;

	// создание двумерного динамического массива

	// создание количества строк
	int** a = new int* [rows];

	// каждая строка это одномерный массив

	for (size_t i = 0; i < rows; i++)
	{
		// создание одномерных массивов каждой строки
		a[i] = new int[cols];
	}

	cout << "Enter Array: " << endl;

	enter2DArray(a, rows, cols);

	cout << endl;

	cout << "Array" << endl;

	print2DArray(a, rows, cols);

	for (size_t i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}

// задание 3
void task3()
{
	// двумерный динамический массив с различной длиной строк

	// ДВУМЕРНЫЕ ДИНАМИЧЕСКИЕ МАССИВЫ
	size_t rows;
	size_t cols;

	// ввод размера двумерного массива

	cout << "Enter rows number: ";
	cin >> rows;


	// создание двумерного динамического массива

	// создание количества строк
	int** a = new int* [rows];

	// каждая строка это одномерный массив

	for (size_t i = 0; i < rows; i++)
	{
		// создание одномерных массивов каждой строки
		a[i] = new int[i+1];

		// заполнение данной строки
		for (size_t k = 0; k < i+1; k++)
		{
			a[i][k] = k + 1;
		}
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < i + 1; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}

	/*cout << "Enter Array: " << endl;

	enter2DArray(a, rows, cols);

	cout << endl;

	cout << "Array" << endl;

	print2DArray(a, rows, cols);
	*/
	for (size_t i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}

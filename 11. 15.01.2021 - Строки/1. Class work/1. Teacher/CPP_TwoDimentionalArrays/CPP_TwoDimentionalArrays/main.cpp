#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	srand(time(0));

	/*const int sizeY = 2;
	const int sizeX = 3;

	//int a[sizeY][sizeX] = { 1, 2, 3, 4, 5, 6 };
	int a[sizeY][sizeX] = { {1, 2, 3}, {4, 5, 6} };

	// цикл по строкам
	for (size_t i = 0; i < sizeY; i++)
	{
		// цикл по ячейкам строки
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}*/

	// массив заполняется случайными числами и подсчитывается сумма чисел
	/*const int sizeY = 3;
	const int sizeX = 5;

	int a[sizeY][sizeX];

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			a[i][k] = rand() % 10;
		}
	}

	int sum = 0;
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
			sum += a[i][k];
		}
		cout << endl;
	}

	cout << "Sum = " << sum << endl;
	*/

	// пользователь вводит массив 3х3, программа подсчитывает произведение угловых элементов

	/*a[0][0] a[0][1] a[0][2]
	a[1][0] a[1][1] a[1][2]
	a[2][0] a[2][1] a[2][2]*/

	/*const int sizeY = 3;
	const int sizeX = 3;

	int a[sizeY][sizeX];

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
		}
	}

	int pro = a[0][0] * a[0][sizeX-1] * a[sizeY-1][0] * a[sizeY-1][sizeX-1];

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << "Pro = " << pro << endl;*/

	// пользователь вводит массив 3х3, программа подсчитывает количество чётных, нечётных,
	// положительных и отрицательных чисел
	/*const int sizeY = 3;
	const int sizeX = 3;

	int a[sizeY][sizeX];

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
		}
	}

	int even = 0, odd = 0, neg = 0, pos = 0;

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
			if (a[i][k] < 0) neg++;
			if (a[i][k] > 0) pos++;
			if (a[i][k] % 2 == 0 && a[i][k] != 0) even++;
			if (a[i][k] % 2 == 1) odd++;
		}
		cout << endl;
	}
	cout << "Even = " << even << endl;
	cout << "Odd = " << odd << endl;
	cout << "Negatives = " << neg << endl;
	cout << "Positioves = " << pos << endl;*/

	// пользователь вводит массив 3х3, программа подсчитывает количество троек, пятёрок и семёрок
	// использовать switch
	/*const int sizeY = 3;
	const int sizeX = 3;

	int a[sizeY][sizeX];

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
		}
	}

	int n3 = 0, n5 = 0, n7 = 0;

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
			switch (a[i][k])
			{
				case 3:
					n3++;
					break;
				case 5:
					n5++;
					break;
				case 7:
					n7++;
			}
		}
		cout << endl;
	}
	cout << "n3 = " << n3 << endl;
	cout << "n5 = " << n5 << endl;
	cout << "n7 = " << n7 << endl;*/

	// пользователь вводит массив 3х5, программа меняет местами первую и последнюю строку массива
	/*const int sizeY = 3;
	const int sizeX = 5;

	int a[sizeY][sizeX];

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
		}
	}
	cout << endl;
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (size_t k = 0; k < sizeX; k++)
	{
		int temp = a[0][k];
		a[0][k] = a[sizeY - 1][k];
		a[sizeY - 1][k] = temp;
	}
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}*/

	// пользователь вводит массив из 9 элементов, программа копирует все элементы
	// этого массива в массив 3х3 в обратном порядке
	/*int b[9];
	for (size_t i = 0; i < 9; i++)
	{
		cin >> b[i];
	}

	for (size_t j = 0; j < 8; j++)
	{
		cout << b[j] << " ";
	}
	cout << endl;

	const int sizeY = 3;
	const int sizeX = 3;

	int a[sizeY][sizeX];

	// копирование элементов из одномерного массива в двумерный
	int j = 8;
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			a[i][k] = b[j--];
		}
	}

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}*/

	// пользователь вводит массив 2x4, программа копирует все элементы
	// этого массива в одномерный массив
	/*const int sizeY = 2;
	const int sizeX = 4;

	int a[sizeY][sizeX];

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
		}
	}

	int b[sizeX*sizeY];

	for (size_t i = 0, j = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			b[j++] = a[i][k];
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (size_t j = 0; j < 8; j++)
	{
		cout << b[j] << " ";
	}*/

	// пользователь вводит массив 3x4, программа копирует все чётные элементы
	// этого массива в одномерный массив b, а нечётные в одномерный массив c
	/*const int sizeY = 3;
	const int sizeX = 4;

	int a[sizeY][sizeX];

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
		}
	}

	int b[sizeX * sizeY];
	int c[sizeX * sizeY];

	int n = 0, m = 0;

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			if(a[i][k] % 2 == 1)
				b[n++] = a[i][k];
			if(a[i][k] % 2 == 0 && a[i][k] != 0)
				c[m++] = a[i][k];

			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (size_t j = 0; j < n; j++)
	{
		cout << b[j] << " ";
	}
	cout << endl;

	for (size_t j = 0; j < m; j++)
	{
		cout << c[j] << " ";
	}
	cout << endl;*/

	// Пользователь вводит массив 3х4, программа переворачивает его на 90 градусов, так что получается массив
	// 4х3 и выводит его на экран
	//
	// 1 2 3 4		9 5 1
	// 5 6 7 8	=>	0 6 2
	// 9 0 1 2		1 7 3
	//				2 8 4

	/*int a[3][4], b[4][3];
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cin >> a[i][k];
		}
	}

	// n - номер строки в результирующей матрице
	int n = 0;

	// m - номер столбца в результирующей матрице
	int m = 2;

	for (size_t i = 0; i < 3; i++, m--)
	{
		for (size_t k = 0, n = 0; k < 4; k++, n++)
		{
			b[n][m] = a[i][k];
		}
	}

	cout << endl;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t k = 0; k < 3; k++)
		{
			cout << b[i][k] << " ";
		}
		cout << endl;
	}*/

	// пользователь вводит матрицу 3x4 и одно число, программа выясняет, сколько раз это число встречается
	// в матрице
	/*int a[3][4], n = 0;

	cout << "Enter a matrix 3x4:" << endl;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cin >> a[i][k];
		}
	}

	cout << "Enter a number: ";
	cin >> n;

	int count = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			if (a[i][k] == n)
				count++;

			cout << a[i][k] << " ";
		}
		cout << endl;
	}

	cout << "Result = " << count << endl;*/

	// пользователь вводит матрицу 3x4, программа заменяет все повторяющиеся в матрице числа на 0
	// и выводит матрицу на экран
	// 1 2 3 4
	// 5 6 7 1
	// 1 2 3 5
	
	/*int a[3][4];

	cout << "Enter a matrix 3x4:" << endl;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cin >> a[i][k];
		}
	}
	
	cout << endl;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}

	cout << endl;

	// циклы по всем элементам двумерного массива
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4;)
		{
			// циклы по проверяемым элементам двумерного массива
			for (size_t n = 0; n < 3; n++)
			{
				for (size_t m = 0; m < 4; m++)
				{
					// если при проверке во вложенных циклах достигнут элемент, с которым происходит сравнение,
					// то прекратить проверку и поменять проверяемый элемент
					if (i == n && k == m)
						goto end;	// прыжок на метку вне циклов по n, m

					if (a[i][k] == a[n][m])
						a[i][k] = 0;
				}
			}
		end: 
			k++;
		}
	}

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}*/

	// Пользователь вводит массив 3х4, программа меняет все простые числа в массиве на ближайшие НЕ простые числа
	int a[3][4];

	// ввод массива
	cout << "Enter a matrix 3x4:" << endl;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cin >> a[i][k];
		}
	}

	// вывод исходного массива
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// замена простых элементов
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			bool flag = true;

			if (a[i][k] < 2)
				continue;
				
			for (int j = 2; j <= a[i][k] / 2; j++)
			{
				// проверка на простоту
				if (a[i][k] % j == 0)
				{
					flag = false;
					break;
				}
			}

			// число a[i][k] - простое
			if (flag)
			{
				if (a[i][k] == 2)
					a[i][k] += 8;
				else a[i][k]++;
			}
		}
	}

	// вывод результата
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}
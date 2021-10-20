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
	const int sizeY = 3;
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
	cout << endl;
}
#include <iostream>
#include <time.h>
// библиотека лагоритмов
#include <algorithm>

using namespace std;

void main()
{
	while (true)
	{
		srand(time(0));

		int num;
		cout << endl << "--------------------------------------------" << endl << endl;
		cout << "Enter the task number (0 = exit): ";
		cin >> num;
		cout << endl << "--------------------------------------------" << endl << endl;
		// ---------------------- parameters for entering the task number
		if (num == 0)
			break;
		if (num < 1)
		{
			cout << "Error! Pleace, enter the correct number." << endl << endl;
			continue;
		}
		// --------------------------------------------------------------

		if (num == 1)
		{
			// 1. Пользователь вводит массив 3х5, программа меняет 
			// местами 2 и предпоследний столбцы массива и выводит 
			// его на экран			
			
			cout << "                 The task 1                 " << endl << endl;

			const int sizeY = 3, sizeX = 5;

			int a[sizeY][sizeX], temp;

			// ввод массива 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << "Enter a[" << i << "][" << k << "]: ";
					cin >> a[i][k];
				}
				cout << endl;
			}

			cout << endl;

			// вывод массива 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}
			
			for (size_t i = 0; i < sizeY; i++)
			{
				temp = a[i][1];
				a[i][1] = a[i][sizeX - 2];
				a[i][sizeX - 2] = temp;
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
		}

		if (num == 2)
		{
			// 2. Пользователь вводит массив 3х4, программа 
			// хаотично перемешивает элементы этого массива
			// и выводит его на	экран

			cout << "                 The task 2                 " << endl << endl;


			const int sizeY = 3, sizeX = 4;

			int a[sizeY][sizeX];

			// ввод массива 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << "Enter a[" << i << "][" << k << "]: ";
					cin >> a[i][k];
				}
				cout << endl;
			}

			cout << endl;

			// вывод массива 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl;
			
			// перемешивание элементов массива
			for (size_t i = 0, temp, sY1, sX1, sY2, sX2; i < sizeY*sizeX; i++)
			{
				sY1 = rand() % sizeY;
				sX1 = rand() % sizeX;

				sY2 = rand() % sizeY;
				sX2 = rand() % sizeX;

				temp = a[sY1][sX1];
				a[sY1][sX1] = a[sY2][sX2];
				a[sY2][sX2] = temp;
			}

			cout << endl;

			// вывод массива 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

		if (num == 3)
		{
			// 3. Пользователь вводит массив 3х4, программа меняет 
			// местами 2 случайных элемента этого массива и выводит 
			// его на экран

			cout << "                 The task 3                 " << endl << endl;

			const int sizeY = 3, sizeX = 4;

			int a[sizeY][sizeX];

			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << "Enter a[" << i << "][" << k << "]: ";
					cin >> a[i][k];
				}
				cout << endl;
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


			int sY1 = rand() % sizeY;
			int sX1 = rand() % sizeX;

			int sY2 = rand() % sizeY;
			int sX2 = rand() % sizeX;

			int temp = a[sY1][sX1];
			a[sY1][sX1] = a[sY2][sX2];
			a[sY2][sX2] = temp;

			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}
		}

		if (num == 4)
		{
			// 4. Пользователь вводит массив 3х4, программа 
			// меняет местами минимальный и максимальный 
			// элементы массива и выводит его на экран

			cout << "                 The task 4                 " << endl << endl;

			const int sizeY = 3, sizeX = 4;

			int a[sizeY][sizeX];

			// ввод массива 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << "Enter a[" << i << "][" << k << "]: ";
					cin >> a[i][k];
				}
				cout << endl;
			}

			// вывод массива 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl;

			int max[3]{ 0,0 }, min[3]{ 0,0 };

			max[3] = a[0][0];
			min[3] = a[0][0];

			// нахождение максималоного и минимального элеманта массива
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					if (a[i][k] > max[3])
					{
						max[3] = a[i][k];
						max[0] = i;
						max[1] = k;
					}

					if (a[i][k] < min[3])
					{
						min[3] = a[i][k];
						min[0] = i;
						min[1] = k;
					}
				}
			}

			// вывод максимального элемента массива и минимального до изменений 
			cout << "Max a[" << max[0] << "][" << max[1] << "] = " << max[3] << endl;
			cout << "Min a[" << min[0] << "][" << min[1] << "] = " << min[3] << endl;

			cout << endl;
			
			// замена местами максимального и минимального элементов массива 
			int temp = a[max[0]][max[1]];
			a[max[0]][max[1]] = a[min[0]][min[1]];
			a[min[0]][min[1]] = temp;

			// вывод массива 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl;
		}

		if (num == 5)
		{
			// 5. Пользователь вводит массив 3х4, программа 
			// переворачивает его на 90 градусов, так что
			// получается массив 4х3 и выводит его на экран

		  /*a[0][0] a[0][1] a[0][3]									a[0][0] a[0][1] a[0][2] a[0][3]	1  2  3  4		9  5  1
			a[1][0] a[1][1] a[1][2]									a[1][0] a[1][1] a[1][2] a[1][3] 5  6  7  8		10 6  2
			a[2][0] a[2][1] a[2][2]									a[2][0] a[2][1] a[2][2] a[2][3] 9  10 11 12		11 7  3
			a[3][0] a[3][1] a[3][2]																					12 8  4 */


			cout << "                 The task 5                 " << endl << endl;

			const int sizeY_1 = 3, sizeX_1 = 4, sizeY_2 = 4, sizeX_2 = 3, size = sizeY_1*sizeX_1;

			int a[sizeY_1][sizeX_1];
			int b[sizeY_2][sizeX_2];

			// ввод массива 
			for (size_t i = 0; i < sizeY_1; i++)
			{
				for (size_t k = 0; k < sizeX_1; k++)
				{
					cout << "Enter a[" << i << "][" << k << "]: ";
					cin >> a[i][k];
				}
				cout << endl;
			}

			cout << endl;

			// вывод массива 
			for (size_t i = 0; i < sizeY_1; i++)
			{
				for (size_t k = 0; k < sizeX_1; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl;

			// перевод из массива 3х4 в 4х3
			for (size_t i = 0; i < sizeY_1; i++)
			{
				for (size_t k = 0; k < sizeX_1; k++)
				{
					b[k][i] = a[i][k];
				}
			}

			// перевод массива 4х3 из зеркального в правильное состояние 
			for (size_t i = 0, temp; i < sizeY_2; i++)
			{
				temp = b[i][0];
				b[i][0] = b[i][sizeX_2 - 1];
				b[i][sizeX_2 - 1] = temp;
			}

			for (size_t i = 0; i < sizeY_2; i++)
			{
				for (size_t k = 0; k < sizeX_2; k++)
				{
					cout << b[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl;

		}

		if (num == 6)
		{
			// 6. Пользователь вводит массив 3х4, программа
			// копирует все простые числа в одномерный массив
			// и выводит его на экран

			cout << "                 The task 6                 " << endl << endl;


			const int sizeY = 3, sizeX = 4, size = sizeY * sizeX;

			int a[sizeY][sizeX], b[size];

			// ввод массива 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << "Enter a[" << i << "][" << k << "]: ";
					cin >> a[i][k];
				}
				cout << endl;
			}

			// вывод массива 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}

			int n = 0;
			// нахождение простых чисел и заполнение ими однорядного массива 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					bool res = false;
					if (a[i][k] > 1)
					{
						res = true;
						if (a[i][k] == 2)
						{
							b[n++] = a[i][k];
							continue;
						}
						for (size_t r = 2; r < (a[i][k] / 2) + 1; r++)
						{
							if (a[i][k] % r == 0)
							{
								res = false;
								break;
							}
						}
					}
					if (res)
						b[n++] = a[i][k];
				}
			}

			cout << endl;

			// вывод однорядного массива с простыми числами
			if (n > 0)
			{
				for (size_t i = 0; i < n; i++)
				{
					cout << b[i] << " ";
				}
			}
			else
				cout << "No prime numbers!" << endl;

			cout << endl;

		}

		if (num == 7)
		{
			// 7. Пользователь вводит одномерный массив из 7 элементов.
			// Программа сортирует его в порядке возрастания и выводит
			// на экран

			cout << "                 The task 7                 " << endl << endl;


			const int size = 7;

			int a[size], solution;

			// ввод массива
			for (size_t i = 0; i < size; i++)
			{
				cout << "Enter a[" << i << "]: ";
				cin >> a[i];
			}

			cout << endl;

			// выбор варианта решения 
			while (true)
			{
				cout << "Enter solution number(1-3), exit(0): ";
				cin >> solution;

				if (solution == 0)
					break;

				if (solution > 0 && solution < 4)
					break;

				else
					cout << endl << "Enter the correct number!" << endl << endl;
				
			}

			cout << endl;

			// вывод массива 
			for (size_t i = 0; i < size; i++)
			{
				cout << a[i] << " ";
			}

			cout << endl;

			// первый способ
			if (solution == 1)
			{
				for (size_t i = 0; i < size - 1; i++)
				{
					for (size_t k = i + 1; k < size; k++)
					{
						if (a[i] > a[k])
							swap(a[k], a[i]);
					}
				}
			}

			// второй способ
			if (solution == 2)
				sort(a, a + size);

			
			cout << endl;

			// третий способ
			if (solution == 3)
			{
				for (size_t n = 0; n < size - 1; n++)
				{
					int z = 0;
					for (size_t i = 0, k = 1; k < size; i++, k++)
					{
						if (a[i] > a[k])
						{
							z++;
							int temp = a[i];
							a[i] = a[k];
							a[k] = temp;
						}
					}
					if (z == 0)
						break;
				}
			}

			// вывод массива на экран
			for (size_t i = 0; i < size; i++)
			{
				cout << a[i] << " ";
			}

			cout << endl;
		}
	}
}
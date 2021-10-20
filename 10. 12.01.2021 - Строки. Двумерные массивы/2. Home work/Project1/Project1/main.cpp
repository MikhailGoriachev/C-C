#include <iostream>
#include <time.h>

using namespace std;


void main()
{
	srand(time(0));

	while (true)
	{
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
			// 1. Пользователь вводит массив 3х3, программа 
			// меняет местами 1 строку и послейний столбец массива

			const int sizeY = 3, sizeX = 3;

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

			cout << endl << endl;

			// вывод массива 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl << endl;

			// программа меняет первую строку и последний столбец местами
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					int temp = a[0][k];
					a[0][k] = a[i][sizeX - 1];
					a[i][sizeX - 1] = temp;
				}
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
		}

		if (num == 2)
		{
			// 2. Пользователь вводит массив 3х4, программа 
			// подсчитывает количество положительных 
			// повторяющихся элементов

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

			int count = 0;

			// программа находит посторяющиеся числа
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					for (size_t m = 0; m < sizeY; m++)
					{
						for (size_t n = 0; n < sizeX; n++)
						{
							if (m == i && n == k)
								goto end;
							if (a[i][k] == a[m][n] && a[i][k] > 0)
							{
								count++;
								goto end;
							}
						}
					}
				end:;
				}
			}

			// вывод результата 
			cout << "Count = " << count << endl;
		}

		if (num == 3)
		{
			// 3. Пользователь вводит массив 3х4, программа 
			// меняет все простые числа в массиве на ближайшие 
			// НЕ простые числа

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


			// замена простых чисел на непростые
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					if (a[i][k] < 2)
						continue;

					bool flag = true;

					if (a[i][k] == 2)
					{
						a[i][k]--;
						continue;
					}

					for (size_t n = 2; n < (a[i][k] / 2 + 1); n++)
					{
						if (a[i][k] % n == 0)
							flag = false;
					}

					if (flag)
						a[i][k]++;
				}
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
		}

		if (num == 4)
		{
			// 4. Пользователь вводит 2 массива 3х4, 
			// программа проверяет равны ли они поэлементно

			const int sizeY = 3, sizeX = 4;

			int a[sizeY][sizeX], b[sizeY][sizeX];

			bool res = true;

			// ввод первого массива 
			cout << "Array A" << endl;
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << "Enter a[" << i << "][" << k << "]: ";
					cin >> a[i][k];
				}
			}

			cout << endl;

			// ввод второго массива 
			cout << "Array B" << endl;
			for (size_t i = 0, flag = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << "Enter b[" << i << "][" << k << "]: ";
					cin >> b[i][k];

					// проверка на равность элементов 
					if (flag == 0 && a[i][k] != b[i][k])
					{
						res = false;
						flag++;
					}
				}
			}

			cout << endl;

			// вывод первого массива 
			cout << "Array A" << endl;
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl;

			// вывод второго массива 
			cout << "Array B" << endl;
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << b[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl << endl;

			// вывод результата
			if (res == true)
				cout << "Yes!" << endl;
			else
				cout << "No!" << endl;
		}

		if (num == 5)
		{
			// 5. Пользователь вводит диапазон случайных чисел, программа
			// заполняет массив 5х4 сгенерированными случайными числами 
			// и заменяет на 0 все числа в массиве, которые меньше среднего
			// значения чисел в массиве и выводит массив на экран.

			const int sizeY = 5, sizeX = 4;

			int a[sizeY][sizeX], max, min;

			// ввод диапазона случайных чисел
			do
			{
				cout << "Max number: ";
				cin >> max;

				cout << "Min number: ";
				cin >> min;

				// проверка на корректность введенного диапазона 
				if (max <= min)
				{
					cout << endl << "Error, MAX < MIN! Enter agin!" << endl << endl;
				}
			} while (max <= min);


			// заполнение массива случайными числами и сумирование значений элементов 
			int sum = 0;
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					a[i][k] = rand() % (max - min + 1) + min;
					sum += a[i][k];
				}
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

			// программа вычисляет среднее арифметическое значение элементов массива 
			int avg = sum / (sizeY * sizeX);

			// вывод среднего арифметического значения 
			cout << "Average: " << avg;

			cout << endl;

			// программа заменяет все значение элементов массива, которые меньше 
			// среднего значения на 0 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					if (a[i][k] < avg)
						a[i][k] = 0;
				}
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
	}
}
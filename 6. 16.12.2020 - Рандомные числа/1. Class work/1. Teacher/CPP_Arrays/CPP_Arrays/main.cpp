#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// настройка "датчика случайных чисел"
	srand(time(0));

	/*-------------------------------- МАССИВЫ ----------------------------------------------*/
	// объявление массива (тип имя и размер)
	/*int a[30];

	a[0] = 1;
	a[1] = 5;
	a[2] = 12;
	a[3] = 12;
	a[4] = 11;*/


	// объявление константы
	/*const int size = 3;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;*/

	/*const int size = 5;

	int a[size] = {0};

	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;*/

	/*const int size = 5;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}

	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
		sum += a[i];
	}
	cout << endl;

	cout << "Sum = " << sum << endl;*/

	/*const int size = 5;

	int a = 0, sum = 0;

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a;
		sum += a;
	}

	cout << "Sum = " << sum << endl;*/

	// Пользователь вводит массив из 5 чисел, программа выводит все числа массива на экран в прямом и в обратном порядке
	/*const int size = 5;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}

	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = size-1; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
	cout << endl;*/

	// Пользователь вводит массив из 5 чисел, программа заменяет все тройки в массиве на 0 и выводит массив на экран
	/*const int size = 5;

	int a[size];

	// ввод массива
	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}

	// обработка элементов
	for (int i = 0; i < size; i++)
	{
		if (a[i] == 3)
			a[i] = 0;
		cout << a[i] << " ";
	}
	cout << endl;*/

	// Пользователь вводит массив из 5 чисел, программа меняет местами нулевой элемент массива с последним элементом и выводит
	// массив на экран
	/*const int size = 5;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}

	// поменять местами 0 элемент массива с последним
	int temp = a[0];
	a[0] = a[size - 1];
	a[size - 1] = temp;

	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;*/

	// Пользователь вводит массив из 6 чисел, если сумма элементов первой половины массива равна сумме элементов второй половины
	// массива, программа пишет "YES", иначе программа пишет "NO"
	/*const int size = 6;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}

	int sum = 0, sum2 = 0;

	// обработка a[0], a[1], a[2]
	for (int i = 0; i < size/2; i++)
	{
		sum += a[i];
		cout << a[i] << " ";
	}
	cout << endl;

	// обработка a[3], a[4], a[5]
	for (int i = size/2; i < size; i++)
	{
		sum2 += a[i];
		cout << a[i] << " ";
	}
	cout << endl;

	if (sum == sum2)
		cout << "YES!" << endl;
	else
		cout << "NO!" << endl;*/

		//1. Пользователь вводит массив из 5 чисел. Программа заменяет в массиве все тройки на пятёрки,
		//а все пятёрки на тройки.
		/*const int size = 5;

		int a[size];

		// ввод массива
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter " << i << " element: ";
			cin >> a[i];
		}

		// обработка элементов
		for (int i = 0; i < size; i++)
		{
			if (a[i] == 3)
				a[i] = 5;
			else
			{
				if (a[i] == 5)
					a[i] = 3;
			}

			cout << a[i] << " ";
		}
		cout << endl;*/

		// 2. Пользователь вводит массив из 5 чисел. Программа находит суммы положительных и отрицаетельных элементов массива
		// и выводит их на экран
		/*const int size = 5;

		int a[size];

		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter " << i << " element: ";
			cin >> a[i];
		}

		int sum = 0, sum2 = 0;

		for (int i = 0; i < size; i++)
		{
			if (a[i] > 0)
				sum += a[i];
			else
				sum2 += a[i];

			cout << a[i] << " ";
		}
		cout << endl;

		cout << "Sum = " << sum << endl;
		cout << "Sum2 = " << sum2 << endl;*/

		// 3. Пользователь вводит массив из 5 чисел. Программа находит минимальный и максимальный элементы и заменяет их
		// в массиве на 0
		/*const int size = 5;

		int a[size];

		// ввод массива
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter " << i << " element: ";
			cin >> a[i];
		}

		int min = a[0], max = a[0], minPos = 0, maxPos = 0;

		for (int i = 1; i < size; i++)
		{
			if (a[i] > max)
			{
				max = a[i];
				maxPos = i;
			}

			if (a[i] < min)
			{
				min = a[i];
				minPos = i;
			}
		}

		cout << "Min = " << min << endl;
		cout << "Max = " << max << endl;

		a[minPos] = 0;
		a[maxPos] = 0;

		for (int i = 0; i < size; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;*/

		// 4. Пользователь вводит массив из 5 чисел. Программа находит минимальный и максимальный элементы и меняет их
		// местами в массиве, после чего выводит массив на экран
		/*const int size = 5;

		int a[size];

		// ввод массива
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter " << i << " element: ";
			cin >> a[i];
		}

		int min = a[0], max = a[0], minPos = 0, maxPos = 0;

		for (int i = 1; i < size; i++)
		{
			if (a[i] > max)
			{
				max = a[i];
				maxPos = i;
			}

			if (a[i] < min)
			{
				min = a[i];
				minPos = i;
			}
		}

		cout << "Min = " << min << endl;
		cout << "Max = " << max << endl;

		// поменять местами минимум и максимум
		int temp = a[minPos];
		a[minPos] = a[maxPos];
		a[maxPos] = temp;

		for (int i = 0; i < size; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;*/

		// 5. Пользователь вводит массив из 6 чисел. Если произведение элементов первой половины массива равно
		// сумме элементов второй половины массива, программа вывод "YES!" или "NO!" иначе.
		/*const int size = 6;

		int a[size];

		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter " << i << " element: ";
			cin >> a[i];
		}

		int pro = 1, sum = 0;

		// обработка a[0], a[1], a[2]
		for (int i = 0; i < size / 2; i++)
		{
			pro *= a[i];
			cout << a[i] << " ";
		}
		cout << endl;

		// обработка a[3], a[4], a[5]
		for (int i = size / 2; i < size; i++)
		{
			sum += a[i];
			cout << a[i] << " ";
		}
		cout << endl;

		if (pro == sum)
		cout << "YES!" << endl;
		else
		cout << "NO!" << endl;*/

		// Пользователь вводит массив из 5 чисел, программа "переворачивает" все числа в массиве и
		// выводит массив на экран 1 2 3 4 5 -> 5 4 3 2 1
		/*const int size = 8;

		int a[size];

		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter " << i << " element: ";
			cin >> a[i];
		}

		// вывод массива на экран
		for (size_t i = 0; i < size; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;

		// переворот элементов массива
		for (size_t i = 0; i < size/2; i++)
		{
			int temp = a[i];
			a[i] = a[size-i-1];
			a[size-i-1] = temp;
		}

		// вывод массива на экран
		for (size_t i = 0; i < size; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;*/

		// пользователь вводит 2 массива по 4 элемента каждый, программа объединяет их в один массив из 8 элементов и выводит его на
		// экран
		/*int a[4], b[4], c[8];

		for (size_t i = 0; i < 4; i++)
		{
			cout << "Enter " << i << " element: ";
			cin >> a[i];
		}
		cout << endl;

		for (size_t i = 0; i < 4; i++)
		{
			cout << "Enter " << i << " element: ";
			cin >> b[i];
		}
		cout << endl;

		for (size_t i = 0; i < 4; i++)
		{
			c[i] = a[i];
			c[i+4] = b[i];
		}
		cout << endl;

		// вывод массива на экран
		for (int i = 0; i < 8; i++)
		{
			cout << c[i] << " ";
		}
		cout << endl;*/

		// пользователь вводит массив из 8 элементов, программа разделяет его на 2 равных массива из 4 элементов каждый
		// и выводит их на экран
		/*int a[4], b[4], c[8];

		for (int i = 0; i < 8; i++)
		{
			cout << "Enter " << i << " element: ";
			cin >> c[i];
		}
		cout << endl;

		for (int i = 0; i < 4; i++)
		{
			a[i] = c[i];
			b[i] = c[i+4];
		}
		cout << endl;

		// вывод массива a на экран
		for (int i = 0; i < 4; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;

		// вывод массива b на экран
		for (int i = 0; i < 4; i++)
		{
			cout << b[i] << " ";
		}
		cout << endl;*/

	// пользователь вводит 2 массива по 4 элемента каждый, программа проверяет равны ли эти массивы друг-другу поэлементно
	/*int a[4], b[4], n = 0;

	for (size_t i = 0; i < 4; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}
	cout << endl;

	for (size_t i = 0; i < 4; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> b[i];
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		if (a[i] == b[i])
			n++;
	}

	if (n == 4)
		cout << "YES!" << endl;
	else
		cout << "NO!" << endl;*/

	// 1. Пользователь вводит массив из 5 чисел. Программа увеличивает положителные числа в массиве в 2 раза и
	//	уменьшает отрицательные числа на 3.
	/*const int size = 5;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}

	for (int i = 0; i < size; i++)
	{
		if (a[i] > 0)
			a[i] *= 2;

		if (a[i] < 0)
			a[i] -= 3;

		cout << a[i] << " ";
	}
	cout << endl;*/

	// 2. Пользователь вводит 2 массива из 4 чисел кажлый. Программа выясняет, равен ли 0 элемент первого массива сумме
	//	элементов второго массива.
	/*int a[4], b[4], sum = 0;

	for (size_t i = 0; i < 4; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}
	cout << endl;

	for (size_t i = 0; i < 4; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> b[i];
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		sum+=b[i];
	}

	if (sum == a[0])
		cout << "YES!" << endl;
	else
		cout << "NO!" << endl;*/

	//3. Пользователь вводит 2 массива из 4 чисел кажлый. Программа копирует элементы из введенных массивов в третий
	//	массив через один : 1 2 3 4, 5 6 7 8 -> 1 5 2 6 3 7 4 8
	/*int a[4], b[4], c[8];

	for (size_t i = 0; i < 4; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}
	cout << endl;

	for (size_t i = 0; i < 4; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> b[i];
	}
	cout << endl;
	
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		c[n] = a[i];
		n++;
		c[n] = b[i];
		n++;
	}

	for (int i = 0; i < 8; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;*/

	// 4. Пользователь вводит 2 массива из 4 чисел кажлый. Программа меняет местами минимальный элемент первого массива
	//	и максимальный элемент второго массива
	/*int a[4], b[4];

	for (size_t i = 0; i < 4; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}
	cout << endl;

	for (size_t i = 0; i < 4; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> b[i];
	}
	cout << endl;

	int min = a[0], max = b[0], minPos = 0, maxPos = 0;

	for (int i = 1; i < 4; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			minPos = i;
		}

		if (b[i] > max)
		{
			max = b[i];
			maxPos = i;
		}
	}

	cout << "Min = " << min << endl;
	cout << "Max = " << max << endl;
	cout << endl;

	int temp = a[minPos];
	a[minPos] = b[maxPos];
	b[maxPos] = temp;

	for (int i = 0; i < 4; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	*/

	// 5. Пользователь вводит 2 массива из 4 чисел кажлый. Программа меняет местами все элементы обоих массивов так,
	// что в первом массиве будут элементы второго массива и наоборот.
	/*int a[4], b[4];

	for (size_t i = 0; i < 4; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}
	cout << endl;

	for (size_t i = 0; i < 4; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> b[i];
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		int temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}

	for (int i = 0; i < 4; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;*/

	// СЛУЧАЙНЫЕ ЧИСЛА
	/*
	int a, b;
	cout << "Enter min random number: ";
	cin >> a;

	cout << "Enter max random number: ";
	cin >> b;

	for (int i = 0; i < 20; i++)
	{
		cout << rand() % (b-a+1) + a << endl;
	}*/

	// пользователь вводит количество случайных чисел и их диапазон. Программа пишет
	// на экран сами числа и вычисляет их среднее арифметическое
	/*int a, b, n;
	cout << "Enter number of random numbers: ";
	cin >> n;

	cout << "Enter min random number: ";
	cin >> a;

	cout << "Enter max random number: ";
	cin >> b;

	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		int current = rand() % (b - a + 1) + a;
		cout << current << endl;
		sum += current;
	}

	cout << "Avg = " << sum / n << endl;*/

	// пользователь вводит диапазон случайных чисел, программа заполняет массив из 10
	// элементов случайными числами во введенном диапазоне и заменяет отрицательные
	// элементы массива на 0
	/*int a, b, c[10];

	cout << "Enter min random number: ";
	cin >> a;

	cout << "Enter max random number: ";
	cin >> b;

	for (size_t i = 0; i < 10; i++)
	{
		c[i] = rand() % (b - a + 1) + a;
		cout << c[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < 10; i++)
	{
		if (c[i] < 0)
			c[i] = 0;

		cout << c[i] << " ";
	}
	cout << endl;*/

	// пользователь вводит массив из 5 чисел, программа меняет местами 2 случайных
	// элемента этого массива и выводит массив на экран
	/*const int size = 5;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}
	
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	int pos1 = rand() % 5;
	int pos2 = rand() % 5;

	int temp = a[pos1];
	a[pos1] = a[pos2];
	a[pos2] = temp;

	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;*/
	
	_getch();
}
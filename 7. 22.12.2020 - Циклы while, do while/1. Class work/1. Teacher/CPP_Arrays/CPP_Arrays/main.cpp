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

	// 1. Пользователь вводит массив из 5 чисел. Программа перемешивает все элементы массива случайным образом из
	// выводит массив на экран

	/*const int size = 7;

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
	for (size_t i = 0; i < size; i++)
	{
		// получить 2 случайных индекса в массиве
		int index1 = rand() % size;
		int index2 = rand() % size;

		// поменять местами 2 случайных элемента в массиве
		int temp = a[index2];
		a[index2] = a[index1];
		a[index1] = temp;
	}

	// вывод массива на экран
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;*/

	// 2. Пользователь задаёт диапазон случайных чисел,
	// программа генериует ТОЛЬКО нечётные случайные числа в этом диапазоне.

	/*int a, b;
	cout << "Enter min random number: ";
	cin >> a;

	cout << "Enter max random number: ";
	cin >> b;

	for (int i = 0; i < 20; i++)
	{
		int number = rand() % (b - a + 1) + a;
		if (number % 2 == 0)
		{
			if (number < b) number++;
			else number--;
		}
		cout << number << endl;
	}*/

	// 3. Программа заполняет массив из 10 элементов случайнвми числами в диапазоне от 10 до 20, 
	// после чего массив выводится на экран, второй элемент массива меняется 
	// местами с предпоследним и массив ещё раз выводится
	/*const int size = 10;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		a[i] = rand() % 11 + 10;
	}

	// вывод массива на экран
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// поменять местами 2 и предпоследний элементы массива
	int temp = a[1];
	a[1] = a[size - 2];
	a[size - 2] = temp;

	// вывод массива на экран
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;*/

	// 4. Программа заполняет массив из 10 элементов случайнвми числами в диапазоне
	// от -10 до 20, после чего программа меняет местами 2 самых маленьких числа 
	// в массиве и выводит массив на экран
	/*const int size = 10;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		a[i] = rand() % 31 - 10;
	}

	// вывод массива на экран
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	int min1 = a[0], index1 = 0;
	int min2 = a[1], index2 = 1;

	// поиск 2 минимальных элементов
	for (size_t i = 2; i < size; i++)
	{
		if (min1 > min2)
		{
			if (min1 > a[i])
			{
				min1 = a[i];
				index1 = i;
			}
		}
		else
		{
			if (min2 > a[i])
			{
				min2 = a[i];
				index2 = i;
			}
		}
	}

	cout << endl << "min1 = " << min1 << endl;
	cout << "min2 = " << min2 << endl << endl;

	// поменять элементы местами
	int temp = a[index1];
	a[index1] = a[index2];
	a[index2] = temp;

	// вывод массива на экран
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;*/

	// 5. Программа заполняет массив из 7 элементов случайными числами 
	// в диапазоне от -20 до 10, после чего программа меняет местами 2 самых 
	// больших числа в массиве и выводит массив на экран
	/*const int size = 7;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		a[i] = rand() % 31 - 20;
	}

	// вывод массива на экран
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	int max1 = a[0], index1 = 0;
	int max2 = a[1], index2 = 1;

	// поиск 2 минимальных элементов
	for (size_t i = 2; i < size; i++)
	{
		if (max1 < max2)
		{
			if (max1 < a[i])
			{
				max1 = a[i];
				index1 = i;
			}
		}
		else
		{
			if (max2 < a[i])
			{
				max2 = a[i];
				index2 = i;
			}
		}
	}

	cout << endl << "max1 = " << max1 << endl;
	cout << "max2 = " << max2 << endl << endl;

	// поменять элементы местами
	int temp = a[index1];
	a[index1] = a[index2];
	a[index2] = temp;

	// вывод массива на экран
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;*/

	// вывести числа в диапазоне [0; 4]
	/*int i = 0;
	while(i<5)
	{
		cout << "i = " << i << endl;
		i++;
	}*/

	// вводить числа, пока не введен 0, посчитать сумму введенных чисел
	/*int sum = 0, a = 1;
	while (a != 0)
	{
		cin >> a;
		sum += a;
	}
	cout << "sum = " << sum << endl;*/

	/*int sum = 0;
	for (int a = 1; a != 0;)
	{
		cin >> a;
		sum += a;
	}
	cout << "sum = " << sum << endl;*/

	// пользователь вводит числа, пока их произведение меньше 20
	// программа подсчитывает произведение и сумму отрицательных
	// чисел из введенных
	/*int a;
	int pro = 1, npro = 1, nsum = 0;
	while (pro < 20)
	{
		cin >> a;
		pro *= a;
		if (a < 0)
		{
			npro *= a;
			nsum += a;
		}
	}
	cout << "Sum of negatives: " << nsum << endl;
	cout << "Production of negatives: " << npro << endl;*/

	/*int a;
	int npro = 1, nsum = 0;
	for (int pro = 1; pro < 20; pro *= a)
	{
		cin >> a;
		if (a < 0)
		{
			npro *= a;
			nsum += a;
		}
	}
	cout << "Sum of negatives: " << nsum << endl;
	cout << "Production of negatives: " << npro << endl;*/

	/*int a;
	int pro = 1, npro = 1, nsum = 0;
	do
	{
		cin >> a;
		pro *= a;
		if (a < 0)
		{
			npro *= a;
			nsum += a;
		}
	} while (pro < 20);
	cout << "Sum of negatives: " << nsum << endl;
	cout << "Production of negatives: " << npro << endl;*/

	// пользователь вводит числа, пока количество нечётных чисел
	// меньше 5. Программа подсчитывает произведение чётных чисел
	// while, do..while, for
	/*int odd = 0, pro = 1, a;
	while (odd < 5)
	{
		cin >> a;
		if (a % 2 == 1)
			odd++;
		if (a % 2 == 0 && a != 0)
			pro *= a;
	}
	cout << "pro = " << pro << endl;*/

	/*int odd = 0, pro = 1, a;
	do
	{
		cin >> a;
		if (a % 2 == 1)
			odd++;
		if (a % 2 == 0 && a != 0)
			pro *= a;
	} while (odd < 5);
	cout << "pro = " << pro << endl;*/

	/*int pro = 1, a;
	for (int odd = 0; odd < 5;)
	{
		cin >> a;
		if (a % 2 == 1)
			odd++;
		if (a % 2 == 0 && a != 0)
			pro *= a;
	}
	cout << "pro = " << pro << endl;*/

	/*int odd = 0, pro = 1, a;
	for(;;)
	{
		cin >> a;
		if (a % 2 == 1)
			odd++;
		if (a % 2 == 0 && a != 0)
			pro *= a;

		if (odd > 5)
			break;
	}
	cout << "pro = " << pro << endl;*/

	// пользователь вводит числа, пока не введёт 0
	// программа подсчитывает среднее арифм. и минимум введенных
	// чисел, 0 не считается
	// while, do..while, for, for + break
	/*int a = 1, sum = 0, min;

	cin >> min;
	sum += min;
	while (a != 0 && min != 0)
	{
		cin >> a;
		sum += a;
		if (min > a && a != 0)
			min = a;
	}
	cout << "min = " << min << ", sum = " << sum << endl;*/

	/*int a = 0, sum = 0, min;

	cin >> min;
	sum += min;
	do
	{
		cin >> a;
		sum += a;
		if (min > a && a != 0)
			min = a;
	} while (a != 0 && min != 0);
	cout << "min = " << min << ", sum = " << sum << endl;*/

	/*int sum = 0, min;

	cin >> min;
	sum += min;
	for (int a = 1; a != 0 && min != 0;)
	{
		cin >> a;
		sum += a;
		if (min > a && a != 0)
			min = a;
	}
	cout << "min = " << min << ", sum = " << sum << endl;*/

	/*int a = 1, sum = 0, min;

	cin >> min;
	sum += min;
	for (; min != 0;)
	{
		cin >> a;

		if (a == 0)
			break;

		sum += a;
		if (min > a && a != 0)
			min = a;
	}
	cout << "min = " << min << ", sum = " << sum << endl;*/

	
	
	_getch();
}
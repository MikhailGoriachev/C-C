#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// основная функция программы
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*cout << "Hello\nworld\t__________\n";
	cout << "ok" << endl;
	cout << "end" << endl;*/

	// int a = 0, b = 0;

	/*float a = 0, b = 0;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "a + b = " << a + b << endl;
	cout << "a * b = " << a * b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a / b = " << a / b << endl;
	//cout << "a % b = " << a % b << endl;*/

	/*float a = 0, b = 0, c = 0;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	cout << "result = " << (a + b + c) / 3 << endl;*/

	/*int a = 0;

	cout << "Enter a: ";
	cin >> a;
	if (a != 3)
	{
		cout << "YES!";
	}
	else
	{
		cout << "NO!";
	}*/
	
	// вводится 3 числа, программа находит 2 максимальных
	/*int a = 0, b = 0, c = 0;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	if (a >= b && a >= c)
	{
		if (b >= c)
			cout << "max = " << a << ", max2 = " << b << endl;
		else
			cout << "max = " << a << ", max2 = " << c << endl;
	}

	if (b >= a && b >= c)
	{
		if (a >= c)
			cout << "max = " << a << ", max2 = " << b << endl;
		else
			cout << "max = " << b << ", max2 = " << c << endl;
	}

	if (c >= a && c >= b)
	{
		if (a >= b)
			cout << "max = " << a << ", max2 = " << c << endl;
		else
			cout << "max = " << b << ", max2 = " << c << endl;
	}*/

	// пользователь вводит 3 числа, если их сумма больше 10, то программа выводит "YES",
	// иначе программа выводит "NO"
	/*int a = 0, b = 0, c = 0;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	int sum = a + b + c;
	if (sum > 10)
	{
		cout << "YES!";
	}
	else
	{
		cout << "NO!";
	}*/

	// Пользователь вводит четыре числа. Если каждое следующее число
	// в 2 раза больше предыдущего, то программа пишет 'YES', иначе No

	/*int a = 0, b = 0, c = 0;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	// если a == b И b == c
	if (a == b && b == c)
	{
		cout << "YES!" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}*/

	/*int a = 0, b = 0, c = 0, d = 0;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter d: ";
	cin >> d;

	if (b == 2*a && c == 2*b && d == 2*c)
	{
		cout << "YES!" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}*/

	/*int a = 0, b = 0, c = 0;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	// если a < 0 ИЛИ b < 0 ИЛИ c < 0
	if (a < 0 || b < 0 || c < 0)
		cout << "YES!" << endl;
	else
		cout << "NO" << endl;*/

	// бесконечный цикл
	/*for(;;)
	{
		cout << "YES!" << endl;
	}*/

	/*for (int i = 1; i<=6; i++)
	{
		if (i != 4)
			cout << i << endl;
	}*/

	// подсчёт суммы 5 чисел
	/*int sum = 0, a = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		sum = sum + a;
	}

	cout << "Sum = " << sum << endl;*/

	// подсчёт произведения положительных чисел
	/*int pro = 1, a = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		if(a>0)
			pro = pro * a;
	}

	cout << "Pro = " << pro << endl;*/

	// пользователь вводит 5 чисел, программа подсчитывает сколько из этих
	// чисел больше 3 и меньше 5
	/*int n = 0, a = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (a >= 3 && a <= 5)
			n++;
	}

	cout << "Count = " << n << endl;*/

	// пользователь вводит 5 чисел, программа подсчитывает количество троек, пятёрок
	// и семёрок
	/*int n3 = 0, n5 = 0, n7 = 0, a = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (a == 3) 
			n3++;
		if (a == 5) 
			n5++;
		if (a == 7) 
			n7++;
	}

	cout << "Count of 3 = " << n3 << endl;
	cout << "Count of 5 = " << n5 << endl;
	cout << "Count of 7 = " << n7 << endl;*/

	// пользователь вводит 5 чисел, программа находит количество чётных и нечётных
	// чисел
	/*int even = 0, odd = 0, a = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (a % 2 == 0 && a != 0)
			even++;
		if (a % 2 == 1)
			odd++;
	}

	cout << "Count of even = " << even << endl;
	cout << "Count of odd = " << odd << endl;*/

	// 1. Пользователь вводит 4 числа. Программа подсчитывает количество положительных нечётных чисел
	/*int a = 0, count = 0;
	
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		if (a > 0 && a % 2 == 1)
			count++;
	}

	cout << "Result = " << count << endl;*/

	// 2. Пользователь вводит 5 чисел. Программа подсчитывает сумму отрицательных чисел
	/*int a = 0, sum = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (a < 0)
			sum += a;
	}

	cout << "Result = " << sum << endl;*/

	// 3. Пользователь вводит 5 чисел. Программа находит максимальное число
	/*int a = 0, max = 0;

	cin >> max;
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		if (max < a)
			max = a;
	}

	cout << "Result = " << max << endl;*/

	// 3. Пользователь вводит 5 чисел. Программа находит минимальное число
	/*int a = 0, min = 0;

	cin >> min;
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		if (min > a)
			min = a;
	}

	cout << "Result = " << min << endl;*/

	// Пользователь вводит 5 чисел, программа находит максимальное отрицательное число
	/*int a = 0, max = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> a;

		// если a - отрицательное число и не было отрицальных чисел до этого
		if (a < 0 && max == 0)
			max = a;

		// если a - отрицательное число и максимум меньше a
		if (a < 0 && max < a)
			max = a;

		// если a - отрицательное число 
		// и не было отрицальных чисел до этого или максимум меньше a
		//if (a < 0 && (max < a || max == 0))
		//	max = a;
	}

	if (max == 0)
		cout << "There is no negative numbers!" << endl;
	else cout << "Result = " << max << endl;*/

	// пользователь вводит 5 чисел, программа пишет "YES", если среднее арифметическое
	// этих чисел меньше 10, иначе программа пишет "NO"
	/*float a = 0, sum = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		sum += a;
	}

	float avg = sum / 5;
	cout << "Avg = " << avg << endl;

	if (avg < 10)
		cout << "YES!" << endl;
	else cout << "NO!" << endl;*/

	// пользователь вводит 5 чисел, если они все отрицательные, программа пишет "YES",
	// иначе программа пишет "NO"

	/*int a = 0, n = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if(a < 0)
			n++;
	}

	if(n == 5)
		cout << "YES!" << endl;
	else 
		cout << "NO!" << endl;*/

	// пользователь вводит 5 чисел, если они все нечётные, программа пишет "YES",
	// иначе программа пишет "NO"

	/*int a = 0, n = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (a % 2 == 1)
			n++;
	}

	if (n == 5)
	cout << "YES!" << endl;
	else
	cout << "NO!" << endl;*/

	// пользователь вводит 5 чисел, если они все идут в порядке возрастания,
	// программа пишет "YES", иначе программа пишет "NO"
	/*int a = 0, n = 0, prev = 0;

	cin >> prev;
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		if (a > prev)
			n++;

		prev = a;
	}

	if (n == 4)
	cout << "YES!" << endl;
	else
	cout << "NO!" << endl;*/

	// пользователь вводит 5 чисел, если они все идут в порядке убывания и являются чётными числами,
	// программа пишет "YES", иначе программа пишет "NO"
	/*int a = 0, n = 0, prev = 0;

	cin >> prev;
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		if (a < prev && a%2 == 0)
			n++;

		prev = a;
	}

	if (n == 4)
	cout << "YES!" << endl;
	else
	cout << "NO!" << endl;*/

	// пользователь вводит 5 чисел, программа подсчитывает среднее арифметическое минимального
	// и максимального чисел
	/*float a = 0, max = 0, min = 0;

	cin >> max;
	min = max;

	for (int i = 0; i < 4; i++)
	{
		cin >> a;

		if (max < a)
			max = a;

		if (min > a)
			min = a;
	}
	
	cout << "Max = " << max << endl;
	cout << "Min = " << min << endl;
	cout << "Avg = " << (min + max) / 2 << endl;*/

	// 1. Пользователь вводит 5 чисел. Программа подсчитывает количество троек, пятёрок и семёрок.
	/*int a = 0, n3 = 0, n5 = 0, n7 = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (a == 3)
			n3++;
		if (a == 5)
			n5++;
		if (a == 7)
			n7++;
	}

	cout << "N3 = "<< n3 << endl;
	cout << "N5 = " << n5 << endl;
	cout << "N7 = " << n7 << endl;*/

	// 2. Пользователь вводит 5 чисел. Программа подсчитывает количество чисел, которые делятся без остатка одновременно
	// на 2 и на 3 и на 5
	/*int a = 0, n = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (a % 2 == 0 && a % 3 == 0 && a % 5 == 0)
			n++;
	}

	cout << "Result = " << n << endl;*/

	// 3. Пользователь вводит 5 чисел. Программа находит максимальное нечётное число
	/*int a = 0, max = 0;

	for (int i = 0; i < 5; i++)
	{
		// ввод текущего числа
		cin >> a;

		// если введенное число нечётное и максимальное число меньше введенного
		if (max < a && (a % 2 == 1 || a % 2 == -1))
			max = a;

		// если введенное число нечётное и максимальное число пока не определено
		if (max == 0 && (a % 2 == 1 || a % 2 == -1))
			max = a;
	}

	if(max == 0)
		cout << "There are no odd numbers entered!" << endl;
	else
		cout << "Max = " << max << endl;*/

	// 4. Пользователь вводит 5 чисел. Программа находит 2 самых больших числа среди них
	/*int a = 0, max = 0, max2 = 0;

	// ввод первых 2х чисел
	cin >> max;
	cin >> max2;

	// ввод остальных чисел
	for (int i = 0; i < 3; i++)
	{
		// ввод числа
		cin >> a;

		// найти наименьшее максимальное число из двух
		if (max < max2)
		{
			// если введенное число больше наименьшего максимального, то поменять максимум
			if (a > max)
				max = a;
		}
		else
		{
			// если введенное число больше наименьшего максимального, то поменять максимум
			if (a > max2)
				max2 = a;
		}
	}

	cout << "Max = " << max << endl;
	cout << "Max2 = " << max2 << endl;*/

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
	int a[4], b[4], n = 0;

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
		cout << "NO!" << endl;

	// ожидание нажатия на любую клавишу
	_getch();
}
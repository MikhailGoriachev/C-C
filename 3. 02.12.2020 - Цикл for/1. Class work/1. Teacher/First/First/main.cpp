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
	float a = 0, max = 0, min = 0;

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
	cout << "Avg = " << (min + max) / 2 << endl;

	// ожидание нажатия на любую клавишу
	_getch();
}
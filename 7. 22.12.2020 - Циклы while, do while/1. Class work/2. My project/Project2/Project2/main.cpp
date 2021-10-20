#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	srand(time(0));

	// вывести числа в диапазоне от 0 до 4
	/*int i = 0;
	while (i < 5)
	{
		cout << "i = " << i << endl;
		i++;
	} */

	// вводить числа, пока не введен 0, посчитать сумму введенных чисел

	// с помощью while
	/*int sum = 0, a = 1;
	while (a != 0)
	{
		cin >> a;
		sum += a;
	}

	cout << "sum = " << sum << endl;*/

	// с помощью for

	/*int sum = 0, a;

	for (size_t a = 1; a != 0;)
	{
		cin >> a;
		sum += a;
	}

	cout << "sum = " << sum << endl;*/

	// пользователь вводит числа, пока их произведение 
	// меньше 20 программа подсчитывает произведение и сумму 
	// отрицательных чисел из введенных

	//int a, pro = 1, npro = 1, nsum = 0;

	/*while (pro < 20)
	{
		cin >> a;
		pro *= a;
		if (pro < 20 && a < 0)
		{
			nsum += a;
			npro *= a;
		}
	}

	cout << "Sum = " << nsum << endl;
	cout << "Pro = " << npro << endl;*/

	/*for  (; pro < 20;)
	{
		cin >> a;
		pro *= a;
		if (pro < 20 && a < 0)
		{
			nsum += a;
			npro *= a;
		}
	}*/	

	// то же самое через do
	/*do {
		cin >> a;
		pro *= a;
		if (pro < 20 && a < 0)
		{
			nsum += a;
			npro *= a;
		}
	} while (pro < 20);

	cout << "Sum = " << nsum << endl;
	cout << "Pro = " << npro << endl;*/

	// пользватель вводит числа, пока количество нечётных чисел
	// меньше 5. Программа подсчитывает произведение четных чисел
	// while, do..while, for 

	/*int nnum, num, a, pro = 1;

	while (nnum < 5)
	{
		cin >> a;
		if (a % 2 == 1)
			nnum++;
		if (a % 2 == 0)
			pro *= a;
	}

	do
	{
		cin >> a;
		if (a % 2 == 1)
			nnum++;
		if (a % 2 == 0)
			pro *= a;
	} while (nnum < 5);

	for (;nnum < 5;)
	{
		cin >> a;
		if (a % 2 == 1)
			nnum++;
		if (a % 2 == 0)
			pro *= a;
	}
	cout << "Prod even: " << pro << endl;*/

	// использование ключевого слова break
	/*int odd = 0, pro = 1, a;
	for (;;)
	{
		cin >> a;
		if (a % 2 == 1)
			odd++;
		if (a % 2 == 0)
			pro *= a;
		if (odd > 5)
			break;
	}*/
	
	// пользователь вводит числа пока не введет 0
	// программа подсчитывает среднее арифметическе 
	// и минимум чисел, 0 не считается
	// while, do while, for, for + break
	
	/*int a, n = 0, avg = 0, min, sum = 0;

	cin >> a;
	sum += a;
	if (a != 0)
		min = a;

	while (a != 0)
	{
		cin >> a;
		n++;
		sum += a;
		if (a < min && a != 0)
			min = a;
	}

	do
	{
		cin >> a;
		n++;
		sum += a;
		if (a < min && a != 0)
			min = a;
	} while (a != 0);


	for (; a != 0;)
	{
		cin >> a;
		n++;
		sum += a;
		if (a < min && a != 0)
			min = a;
	}

	for (;;)
	{
		cin >> a;
		if (a == 0)
			break;
		n++;
		sum += a;
		if (a < min && a != 0)
			min = a;

	}
	avg = sum / n;



	cout << "Avg = " << avg << endl;
	cout << "Min = " << min << endl;*/
}
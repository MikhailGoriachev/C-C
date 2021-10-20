#include <iostream>
#include <Windows.h>//для того чтобы работать с русским языком
using namespace std;

void main() 
{
	SetConsoleCP(1251);//для того чтобы работать с русским языком
	SetConsoleOutputCP(1251);//для того чтобы работать с русским языком

	// Пользователь вводит 5 чисел, программа находит 
	// максимальное отрицательное число

	/*int n, max = 0;

	for (int i = 0; i < 5; i++)
	{
		cout << "N: ";
		cin >> n;
		// еще один способ
		if (n < 0 && (max < n || max == 0))
			max = n;

		// более компактный способ
		if (max == 0 && n < 0 || n > max)
			max = n;
		
		// если а - отрицательное число и не было отрицательных чисел до этого
		if (max == 0 && n < 0) 
			max = n;
		// если а - отпмцательное число и максимум меньше  а
		if (n > max) 
			max = n;
	}
	if (max == 0) 
		cout << "NO";
	else 
		cout << "Result: " << max;
	*/

	/* пользователь вводит 5 чисел, программа пишет "YES",
	если среднее арифметическое этих чисел меньше 10,
	иначе программа пишет "NO"*/

	/*float n = 0, sum = 0;

	for (int i = 1; i <= 5; i++)
	{
		cin >> n;
		sum += n;
	}

	float avg = sum / 5;
	cout << "AVG = " << avg;

	if(avg < 10)
		cout << "YES";
	else 
		cout << "NO";
	*/

	// пользователь вводит 5 чисел, если они все отрицательные
	// то программа пишет "YES", иначе пишет "NO"

	/*int n, n1 = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		if (n < 0)
			n1++;
	}

	if (n1 == 5)
		cout << "YES";
	else
		cout << "NO";*/

	// пользователь вводит 5 чисел, если они все нечетные
	// то программа пишет "YES", иначе пишет "NO"
	/*int n, over = 0;

	for (int i = 0; i < 5; i++) 
	{
		cin >> n;
		if (n % 2 == 1)
			over++;
	}

	if (over == 5)
		cout << "YES";
	else
		cout << "NO";*/
	 

	// Пользователь вводит 5 чисел, если они все идут в порядке возрастания,
	// то программа пишет "YES", иначе пишет "NO"

	/*int a, prev, n = 0;

	cin >> prev;

	for (int i = 0; i < 4; i++) // в случае второго варианта i < 5
	{
		cin >> a;
		//if (i == 0)
		//{
		//	prev = a; // второй вариант
		//}
		if (a > prev)
		{
			prev = a;
			n++;
		}
	}
	if (n == 4)
		cout << "YES";
	else
		cout << "NO";*/

	// Пользователь вводит 5 чисел, если они все идут в порядке убывания 
	// и являются чётными числами то программа пишет "YES", иначе пишет "NO"

	/*int a, n = 0, prev = 0;


	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (i == 0 && a % 2 == 0)
			prev = a;
		if (prev > a && a % 2 == 0) {
			prev = a;
			n++;
		}
	}
	if (n == 4)
		cout << "YES";
	else
		cout << "NO";*/

	// Пользователь вводит 5 чисел, программа подсчитывает среднее арифметическое минимального
	// и максимального чисел
	
	int a, max, min;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (i == 0)
		{
			max = a;
			min = a;
		}
		if (a > max)
			max = a;
		if (a < min)
			min = a;		
	}
	float over = (max + min) / 2;

	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	cout << "Result: " << over;
}
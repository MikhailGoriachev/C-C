#include <iostream>

using namespace std;

void outNumber(int a, int b)
{
	if (a < b)
	{
		cout << a << endl;

		outNumber(++a, b);
	}

	if (a > b)
	{
		cout << b << endl;
		outNumber(a, ++b);
	}
}

void task2()
{
	// 2. Рекурсивная функция принимает 2 числа [a, b] 
	// и выводит диапазон чисел от [a; b]

	int a, b;

	// ввод a
	cout << "Enter a: ";
	cin >> a;

	// ввод b 
	cout << "Enter b: ";
	cin >> b;

	cout << endl;

	// вызов функции
	outNumber(a, b);

	cout << endl;

	cout << "End." << endl;
}
#include <iostream>

using namespace std;

void outOdd(int num)
{
	// если число больше нуля
	if (num > 0)
	{
		// если число нечётное 
		if (num % 2 != 0)
			cout << num << endl;
		// от числа отнимается один и вызывается функция 
		outOdd(--num);
	}
}

void task1()
{
	// 1. Рекурсивная функция принимает число и выводит 
	// все нечётные числа от 1 и до этого числа
	
	int num;

	// ввод числа
	cout << "Enter number: ";
	cin >> num;

	cout << endl;

	// вызов функции
	outOdd(num);

	cout << endl;

	cout << "End." << endl;
}
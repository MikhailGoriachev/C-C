#include <iostream>
#include <conio.h>

using namespace std;

// основная функция программы
void main()
{
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
	int a = 0, b = 0, c = 0;

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
	}

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
	}
	*/
	// ожидание нажатия на любую клавишу
	_getch();
}
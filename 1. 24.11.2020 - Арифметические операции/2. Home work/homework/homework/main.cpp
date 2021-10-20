#include <iostream>

using namespace std;

void main()
{
	/*1. Пользователь вводит 4 числа. Если сумма первых двух чисел меньше суммы вторых двух чисел,
	то программа пишет "YES", иначе она пишет "NO".*/

	/*int a, b, c, d;

	cout << "Please enter a: ";
	cin >> a;
	cout << "Please enter b: ";
	cin >> b;
	cout << "Please enter c: ";
	cin >> c;
	cout << "Please enter d: ";
	cin >> d;

	if ((a + b) < (c + d))
		cout << "YES";
	else
		cout << "NO";
	*/

	/*2. Пользователь вводит 4 числа. Если сумма всех чисел равна произведению первых двух чисел,
	то программа пишет "YES", иначе она пишет "NO".*/

	/*int a, b, c, d;

	cout << "Please enter a: ";
	cin >> a;
	cout << "Please enter b: ";
	cin >> b;
	cout << "Please enter c: ";
	cin >> c;
	cout << "Please enter d: ";
	cin >> d;

	if ((a+b+c+d) == a*b)
		cout << "YES";
	else
		cout << "NO";
	*/

	/*3. Пользователь вводит 4 числа. Программа находит 2 самых больших числа из них и выводит их на экран.*/

	int a, b, c, d, max, max2;

	cout << "Please enter a: ";
	cin >> a;
	cout << "Please enter b: ";
	cin >> b;
	cout << "Please enter c: ";
	cin >> c;
	cout << "Please enter d: ";
	cin >> d;


	max = a;

	if (max < b) max = b;
	if (max < c) max = c;
	if (max < d) max = d;
	cout << "Max: " << max << endl;

	max2 = 0;

	if (max == a)
	{		
			cout << "WWW" << endl;
			if (max == b) 
			{
				max2 = max;
			}
			if (max == c)
			{
				max2 = max;
			}
			if (max == d)
			{
				max2 = max;
			}
		else if (max != b && max != c && max != d) {
			if (b <= c && b <= d) {
				if (c >= d) max2 = c;
				else max2 = d;
			}
			else if (b >= c && b <= d || b <= c && b >= d) { max2 = c; }
			else { max2 = b; cout << "WWW" << endl; }
		}
	}
	if (b == max) {

		if (max == a)
			max2 = max;

		if (max == c)
			max2 = max;

		if (max == d)
			max2 = max;
		else if (max != a && max != c && max != d) {
			if (c <= a && c <= d) {
				if (a >= d) max2 = a;
				else  max2 = d;
			}
			else if (c >= a && c <= d || c <= a && c >= d) { max2 = d; }
			else max2 = c;
		}
	}
	if (c == max) {
		if (max == a)
			max2 = max;

		if (max == b)
			max2 = max;

		if (max == d)
			max2 = max;
		else if (max != a && max != b && max != d) {
			if (d <= b && d <= a) {
				if (b >= a) max2 = b;
				else  max2 = a;
			}
			else if (d >= b && d <= a || d <= b && d >= a) { max2 = a; }
			else max2 = d;
		}
	}
	if (d == max) {
		if (max == a)
			max2 = max;

		if (max == b)
			max2 = max;

		if (max == c)
			max2 = max;
		else if (max != a && max != b && max != c) {
			if (a <= b && a <= c) {
				if (b >= c) max2 = b;
				else  max2 = c;
			}
			else if (a >= b && a <= c || a <= b && a >= c) { max2 = b; }
			else max2 = a;
		}
	}


	cout << "Max two: " << max2;
	
}
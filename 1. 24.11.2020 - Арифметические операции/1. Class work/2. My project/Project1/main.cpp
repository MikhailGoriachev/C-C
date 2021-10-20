#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
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

	/*
	int a, b, c, d, max, twomax;

	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;

	max = a;

	if (max < b)
		max = b;
	if (max < c)
		max = c;

	twomax = 0;


	if (max != a)
	{
		twomax = a;
	}

	cout << "two" << twomax << endl;

	if (max != b && twomax < b && twomax != b) {
		twomax = b;
	}

	cout << "two" << twomax << endl;

	if (max != c && twomax < c && twomax != c) {
		twomax = c;
	}

	cout << "two" << twomax << endl;

	if (a == b && b == c && a == c)
		twomax = max;

	cout << "two" << twomax << endl;

	if (max == a == b || max == a == c || max == b == c ) {
		twomax = max;
		cout << "co" << endl;
	}

	cout << "Max: " << max << endl << "Twomax: " << twomax;

	*/




	/*int a, b, c, d, e, max, min;

	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	cout << "d: ";
	cin >> d;
	cout << "e: ";
	cin >> e;

	max = a;

	if (max < b)
		max = b;
	if (max < c)
		max = c;
	if (max < d)
		max = d;
	if (max < c)
		max = c;


	min = a;

	if (min > b)
		min = b;
	if (min > c)
		min = c;
	if (min > d)
		min = d;
	if (min > c)
		min = c;

	cout << "NOD: " << (max + min) / 2;
	*/
	_getch();
}

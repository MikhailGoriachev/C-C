#include <iostream>

using namespace std;

void main()
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	//                                                                                                 //
	//                                                                                                 //
	//                                      Enter the task number                                      //
	//                                                                                                 //
	//                                                                                                 //
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	cout << "---------------------------------------------------" << endl << endl;
	cout << "Enter the task number: ";
	int enter;
	cin >> enter;
	cout << endl<< "---------------------------------------------------" << endl << endl;
	

	if (enter == 1) 
	{
		// 1. Пользователь вводит 5 чисел. Программа подсчитывает 
		// количество троек, пятёрок и семёрок.

		int a, three = 0, five = 0, seven = 0;

		cout << "---------------------------------------------------" << endl << endl;
		cout << "                     The task 1                    " << endl << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << "Enter num: ";
			cin >> a;
			if (a == 3)
				three++;
			if (a == 5)
				five++;
			if (a == 7)
				seven++;
		}

		cout << endl << "---------------------------------------------------" << endl << endl;
		cout << "Three: " << three << endl;
		cout << "Five: " << five << endl;
		cout << "Seven: " << seven << endl;
		cout << endl << "---------------------------------------------------" << endl << endl;
	}

	
	if (enter == 2)
	{
		//2. Пользователь вводит 5 чисел.Программа подсчитывает
		//количество чисел, которые делятся без остатка
		//одновременно на 2 и на 3 и на 5

		int a, n = 0;
		cout << "---------------------------------------------------" << endl << endl;
		cout << "                     The task 2                    " << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "Enter num: ";
			cin >> a;
			if (a % 2 == 0 && a % 3 == 0 && a % 5 == 0)
			{
				n++;
			}
		}
		cout << endl << "---------------------------------------------------" << endl << endl;
		cout << "Result: " << n << endl << endl;
		cout << "---------------------------------------------------" << endl << endl;
	}

	if (enter == 3)
	{
		// 3. Пользователь вводит 5 чисел. Программа находит 
		// максимальное нечётное число

		int a = 0, max = 0;

		cout << "---------------------------------------------------" << endl << endl;
		cout << "                     The task 3                    " << endl << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << "Enter num: ";
			cin >> a;
			if (i == 0 && a % 2 == 1)
				max = a;
			if (a > max && a % 2 == 1)
				max = a;
		}
		cout << endl << "---------------------------------------------------" << endl << endl;
		cout << "Max: " << max;
		cout << endl << endl << "---------------------------------------------------" << endl << endl;
	}

	if (enter == 4) {

		// 4. Пользователь вводит 5 чисел. Программа находит 2
		// самых больших числа среди них

		int n, a, b, c, max, max2;

		cout << "---------------------------------------------------" << endl << endl;
		cout << "                     The task 4                    " << endl << endl;
		for (int i = 0; i < 5; i++)
		{

			cout << "Enter num: ";
			cin >> n;

			if (i == 0)
				c = n;
			if (i == 1)
			{
				if (n >= c) {
					b = c;
					c = n;
				}
				else
					b = n;
			}

			if (i == 2)
			{
				if (n > c && n > b)
				{
					a = b;
					b = c;
					c = n;
				}
				else
					a = n;
			}

			if (i > 2)
			{
				if (n > a && n > b && n == c)
				{
					a = b;
					b = c;
					c = n;
				}
				if (n > a && n > b && n > c)
				{
					a = b;
					b = c;
					c = n;
				}
				if (n > a && n > b && n < c)
				{
					a = b;
					b = n;
				}
				if (n > a && n < b && n < c)
				{
					a = n;
				}
			}

			if (i == 0)
				max = n;

			if (n > max) // максимальное число
				max = n;

			if (i > 2)
			{

				if (i == 4 && (a == b && a == max || a == c && a == max || b == c && b == max))
				{
					max2 = a;
				}

				if (a <= b && b <= c || a >= b && b >= c)
				{
					max2 = b;

				}
				else {
					if (a >= c || a < c)
						max2 = a;

				}
			}
		}
		cout << endl << "---------------------------------------------------" << endl << endl;
		cout << "Max: " << max << endl << "Max two: " << max2 << endl << endl;
		cout << "---------------------------------------------------" << endl;
	}
}

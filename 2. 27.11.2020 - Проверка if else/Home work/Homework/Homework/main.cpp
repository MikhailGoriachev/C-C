#include <iostream>

using namespace std;

void main() {
	/*1. Пользователь вводит 4 числа. Программа подсчитывает
	количество положительных нечётных чисел*/
	/*int n, num = 0;
	for  (int i = 0; i < 4; i++)
	{
		cout << "Enter num: ";
		cin >> n;
		if (n > 0 && n % 2 == 1) {
			num++;
		}
	}
	cout << "Result: " << num;*/

	/*2. Пользователь вводит 5 чисел. 
	Программа подсчитывает сумму отрицательных чисел*/
	/*int n, sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter num: ";
		cin >> n;
		if (n < 0) {
			sum += n;
		}
	}
	cout << "Sum of negative numbers: " << sum;*/

	/*3. Пользователь вводит 5 чисел.
	Программа находит максимальное число*/
	/*int n1, nmax = 0;

	cout << "Enter num: ";
	cin >> nmax;

	for (int i = 0; i < 4; i++)
	{
		cout << "Enter num: ";
		cin >> n1;
		if (n1 > nmax)
		{
			nmax = n1;
		}
	}
	cout << "Max number: " << nmax;*/

	/*4. Пользователь вводит 5 чисел. 
	Программа находит минимальное число*/
	int n1, nmin;

	for (int i = 0; i < 4; i++)
	{
		cout << "Enter num: ";
		cin >> n1;
		if (i == 0) nmin = n1;
		if (n1 < nmin)
		{
			nmin = n1;
		}
		 
	}
	cout << "Min number: " << nmin; 
}
#include <iostream>

using namespace std;

bool primeNumber(int* num, int n)
{
	// если делитель больше половины делимого числа и при этом число больше 1
	if (n > *num / 2 && *num > 1)
		return true;
	// если делитель меньше половины и остаток от деления числа на делитель больше 0 и предыдущее деление не является делением нацело
	else if (n <= *num / 2 && *num % n > 0 && primeNumber(num, n + 1))
	{
		return true;
	}

	// если нет отстатка от деления или число меньше двух
	return false;
}

void task2()
{
	// 2. Рекурсивная функция принимает число и определяет, 
	// является ли оно простым числом

	// число
	int* num = new int;

	// ввод числа
	cout << "Enter number: ";
	cin >> *num;

	// проверка на то является ли число простым
	if (primeNumber(num, 2))
		cout << "Yes!" << endl;
	else cout << "No!" << endl;

	// отчистка памяти
	delete num;
}
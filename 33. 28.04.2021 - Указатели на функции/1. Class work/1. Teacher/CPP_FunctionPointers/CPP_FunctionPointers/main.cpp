#include <iostream>

using namespace std;

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

typedef bool (*comparator)(int a, int b);

bool ascend(int a, int b)
{
	return a < b;
}

bool descend(int a, int b)
{
	return a > b;
}

int cnt = 0;

// компаратор, который обеспечивает следующий принцип сортировки
// сначала идут отрицательные числа в порядке возрастания,
// а потом идут положительные числа в порядке убывания
bool mycomp(int a, int b)
{
	cnt++;

	cout << cnt << ". compare: " << a << ", " << b << endl;

	return a < b;

	/*if (a < 0 && b < 0)
		return a < b;

	if (a >= 0 && b >= 0)
		return a > b;

	if (a >= 0 && b < 0)
		return false;

	if (a < 0 && b >= 0)
		return true;*/
}

bool mycomp2(int a, int b)
{
	cnt++;

	//cout << cnt << ". compare: " << a << ", " << b << endl;

	return a > b;
}

bool mycomp3(int a, int b)
{
	cnt++;

	cout << cnt << ". compare: " << a << ", " << b << endl;

	if (a < 0 && b < 0)
		return a < b;

	if (a >= 0 && b >= 0)
		return a > b;

	if (a >= 0 && b < 0)
		return false;

	if (a < 0 && b >= 0)
		return true;
}

bool mycomp4(int a, int b)
{
	if ((a % 2 == 1 || a % 2 == -1) && (b % 2 == 1 || b % 2 == -1))
		return a < b;

	if (a % 2 == 0 && b % 2 == 0)
		return a > b;

	if ((a % 2 == 1 || a % 2 == -1) && b % 2 == 0)
		return true;

	if (a % 2 == 0 && (b % 2 == 1 || b % 2 == -1))
		return false;
}

void selectionSort(int* array, size_t size, comparator comp) {
	size_t i, j, imin;
	for (i = 0; i < size - 1; i++) {
		imin = i;
		for (j = i + 1; j < size; j++)

			// вызов сравнения элементов через указатель
			if (comp(array[j], array[imin]))
				imin = j;

		swap(array[i], array[imin]);
	}
}

void main()
{
	
	cout << add(1, 3) << endl;

	// вывод адрес функций языка С
	cout << add << endl;
	cout << sub << endl;
	cout << main << endl;

	// объявление указателя на функции, принимающие (int a, int b) и возвращающие int
	//int (*func)(int a, int b);

	// объявление типа func_type - указатели на функции, принимающие (int a, int b) и возвращающие int
	typedef int (*func_type)(int a, int b);

	// объявление переменной типа func_type
	func_type func, func2, func3;

	// поместить в указатель func адрес функции add
	func = add;

	// запустить функцию add через указатель
	cout << func(3, 5) << endl;

	// поместить в указатель func адрес функции sub
	func = sub;

	// запустить функцию sub через указатель
	cout << func(3, 5) << endl;

	int a[] = { 1, 0, 3, 2, 6, 7, 0, 9, 4, -1, -3, -7, -2, -4, 0 };

	selectionSort(a, 15, mycomp4);

	for (size_t i = 0; i < 15; i++)
	{
		cout << a[i] << " ";
	}

	/*char str[] = "Hello world!!!";

	// вывод строки на экран при помощи указателей
	for (char*s = str; *s; s++)
	{
		cout << *s << endl;
	}*/

	// компаратор при сортировке позволяет возвращать сначала нечётные числа в порядке возрастания, 
	// потом чётные числа в порядке убывания
}
#include <iostream>
#include <conio.h>

using namespace std;

typedef bool (*comporator)(long a, long b);

bool comp1(long a, long b)
{
	if (a % 2 == 1)
	{
		if (b % 2 == 1)
		{
			if (a < b)
				return true;
			return false;
		}

		return true;
	}

	if (a % 2 == 0)
	{
		if (b % 2 == 0)
		{
			if (a > b)
				return true;
			return false;
		}

		return false;
	}
}

void SelectSort(long* arr, long* size, comporator comp)
{
	long* n = new long;

	long* arr_k;

	for (long* arr_i = arr; arr_i < arr + *size; arr_i++)
	{
		*n = *arr_i;

		for (arr_k = arr + *size - 1; arr_k > arr_i && comp(*n, *arr_k); arr_k--)
		{
			*arr_k = *arr_k - 1;
		}

		*(arr_k + 1) = *n;
	}
}

void prtintArray(long* arr, size_t size)
{
	for (long* arr_i = arr; arr_i < arr + size; arr_i++)
	{
		cout << *arr_i << endl;
	}
}

void task1()
{
	srand(time(0));

	// компаратор при сортировке позволяет возвращать нечётные числа
	// в порядке возрастания, потом чётные числа в порядке убывания

	// размер массива
	long* sizeArr = new long;

	cout << "Enter size array: ";
	cin >> *sizeArr;

	system("cls");

	// массив 
	long* arr = new long[*sizeArr];

	// заполнение лучайными числами
	for (long* arr_p = arr; arr_p < arr + *sizeArr; arr_p++)
	{
		*arr_p = rand() % (*sizeArr + 1);
	}

	void (*sort)(long* arr, long* size, comporator comp);

	comporator comp;

	comp = comp1;

	sort = SelectSort;

	// запуск сортировки
	sort(arr, sizeArr, comp);

	prtintArray(arr, *sizeArr);

	_getch();
}
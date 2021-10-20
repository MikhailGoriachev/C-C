#include <iostream>

using namespace std;

long sumArr(int* array, long size)
{
	long sum = *array;
	if (size > 0)
	{
		sum += sumArr(array + 1, size - 1);

		return sum;
	}

	return 0;
}

void task1()
{
	// 1. Рекурсивная функция принимает массив чисел и его 
	// размер и вычисляет сумму элементов массива

	srand(time(0));

	// размер массива
	long* size = new long;

	// ввод размера массива
	cout << "Enter size array: ";
	cin >> *size;

	// массив
	int* array = new int[*size];

	// заполнение массива случайными числами от 10 до 99
	for (int* arr = array; arr < array + *size; arr++)
	{
		// элемент массива заполняется случайным числом
		*arr = rand() % 100 + 10;
	}

	// вывод элементов массива 
	for (int* arr = array, num = 0, *n = &num; arr < array + *size; arr++, ++*n)
	{
		cout << "array " << "[" << *n << "] : " << *arr << endl;
	}

	// выделение памяти для суммы
	long* summer = new long;

	// сумма элементов массива
	*summer = sumArr(array, *size);

	// вывод суммы элементов массива
	cout << "Summer: " << *summer << endl;

	// отчистка памяти
	delete[] array;
	delete size, summer;
}
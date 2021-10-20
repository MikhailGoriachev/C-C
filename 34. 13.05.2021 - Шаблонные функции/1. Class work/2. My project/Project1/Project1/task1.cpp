#include <iostream>

#include "head.h"

using namespace std;

void EnterArr(int* arr, int size)
{
	for (int* p_arr = arr, i = 0; p_arr < arr + size; p_arr++, i++)
	{
		system("cls");

		cout << "Enter array[" << i << "]: ";
		cin >> *p_arr;
	}


}

void PrintArr(int* arr, int size)
{
	cout << "Array" << endl;

	for (int* p_arr = arr, i = 0; p_arr < arr + size; p_arr++, i++)
	{
		cout << *p_arr << " " << endl;
	}


}


void task1()
{
	// Задача 1 (7 баллов)

	// Пользователь вводит размер массива и все его элементы.Программа подсчитывает для введенного массива :
	//  •	среднее арифметическое всех элементов
	//	•	сумму нечётных отрицательных элементов
	//	•	количество элементов, которые одновременно делятся на 3 и на 5

	int size;

	cout << "Enter size array: ";
	cin >> size;

	int* arr = new int[size];

	EnterArr(arr, size);

	PrintArr(arr, size);

	pressAnyKey();

	system("cls");

	// среднее арифметическое 
	int avg = 0;
	int summNeg = 0;
	int count = 0;

	for (int* p_arr = arr, i = 0; p_arr < arr + size; p_arr++, i++)
	{
		avg += *p_arr;

		if (*p_arr % 2 == -1 && *p_arr < 0)
			summNeg += *p_arr;

		if (*p_arr % 3 == 0 && *p_arr % 5 == 0)
			count++;
	}

	avg /= size;

	// отчистка памяти
	delete[] arr;

	cout << "Result" << endl;

	cout << "AVG = " << avg << endl;

	cout << "Summer negative odd number = " << summNeg << endl;

	cout << "Count divisor 3 and 5 = " << count << endl;

	pressAnyKey();

	return;
}
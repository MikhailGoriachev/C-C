#include <iostream>
#include <time.h>

using namespace std;

template <typename A, typename S>
void ArrGet(A* arr, S size, A max)
{
	srand(time(0));

	for (A* arr_p = arr; arr_p < arr + size; arr_p++)
	{
		*arr_p = rand() % (max + 1);
	}
}

template <typename T>
void SearchMax(T* arr, size_t size, T* maxArr)
{
	*maxArr = *arr;

	for (T* max = maxArr; max < maxArr + 2; max++)
	{	
		for (T* arr_p = arr; arr_p < arr + size; arr_p++)
		{
			if (*maxArr < *arr_p)
				*max = *arr_p;
		}
	}
}


void task1()
{
	system("cls");

	long* size = new long;

	cout << "Enter size array: " << endl;
	cin >> *size;

	system("cls");

	long* arr = new long[*size];

	ArrGet(arr, *size, *size);

	long* max = new long[2];

	SearchMax(arr, *size, max);

	cout << "Max 1: " << *max << endl;
	cout << "Max 2: " << *(max + 1) << endl;

}
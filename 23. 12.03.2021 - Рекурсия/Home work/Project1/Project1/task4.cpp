#include <iostream>

using namespace std;

// поиск максимального числа
int maxArray(int arr[], int size)
{
	if (size - 1 > 0)
	{
		int a = maxArray(arr + 1, --size);
		if (a > *arr)
			return a;
	}

	return *arr;
}

void task4()
{
	// 4. Рекурсивная функция принимает массив и его размер
	// и находит максимум массиве

	srand(time(0));

	// размер массива
	int size;

	// ввод размера массива
	cout << "Enter size array: ";
	cin >> size;

	cout << endl;

	// длинамический массив указанного размера
	int* arr = (int*)malloc(sizeof(int) * size);

	// заполнение массива случайными числами
	for (int* p_arr = arr; p_arr < arr + size; p_arr++)
	{
		*p_arr = rand() % (100 - 10) + 10;
	}

	// вывод массива
	for (int* p_arr = arr; p_arr < arr + size; p_arr++)
	{
		cout << *p_arr << " ";
	}

	cout << endl << endl;

	// вызов функции и вывод максимального числа в массиве
	cout << "Max: " << maxArray(arr, size) << endl;

	free(arr);
}
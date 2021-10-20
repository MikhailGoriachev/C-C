#include <iostream>

#include "head.h"

using namespace std;

// слияние 
void merge(long* arr, long lBorder, long rBorder, long* split, data_arr* data);

// 6. MERGE SORT
void MergeSort(long* arr, long leftBorder, long rightBorder, data_arr* data)
{
	// индекс границы разделения
	long* split = new long;

	// увеличение счётчика сравнений
	data->comp++;

	// пока левая граница не равна правой
	if (leftBorder < rightBorder)
	{
		*split = (leftBorder + rightBorder) / 2;

		// сортировка левой части
		MergeSort(arr, leftBorder, *split, data);

		// сортировка правой части
		MergeSort(arr, 1 + *split, rightBorder, data);

		// сортировка и слияние части в общий массив
		merge(arr, leftBorder, rightBorder, split, data);
	}

	delete split;
}

// слияние 
void merge(long* arr, long lBorder, long rBorder, long* split, data_arr* data)
{

	// временный буфер
	long* temp = new long[rBorder - lBorder + 1];

	long* temp_p = temp;

	long* pos1 = arr + lBorder;
	long* pos2 = arr + *split + 1;

	// увеличение счётчика сравнений
	data->comp++;

	// цикл заполнение буфера
	for (; pos1 <= arr + *split && pos2 <= arr + rBorder;)
	{
		// увеличение счётчика сравнений
		data->comp++;

		data->moving++;

		// если элемент первой части больше, элемента во второй части
		if (*pos1 > *pos2)
			*temp_p++ = *pos2++;
		else
			*temp_p++ = *pos1++;
	}
	
	// увеличение счётчика сравнений
	data->comp++;

	// копирование оставшихся элементов массива 
	while (pos1 <= arr + *split)
	{
		// увеличение счётчика сравнений
		data->comp++;
		
		data->moving++;

		*temp_p++ = *pos1++;
	}

	// увеличение счётчика сравнений
	data->comp++;

	while (pos2 <= arr + rBorder)
	{
		// увеличение счётчика сравнений
		data->comp++;

		data->moving++;

		*temp_p++ = *pos2++;
	}

	temp_p = temp;

	// заполнение буфера элементами из буфера 
	for (long pos = 0; temp_p < temp + rBorder - lBorder + 1; pos++)
	{
		// увеличение счётчика сравнений
		data->comp++;

		data->moving++;

		*(arr + lBorder + pos) = *temp_p++;
	}

	delete[] temp;
}
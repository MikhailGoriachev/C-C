#include <iostream>

#include "head.h"

using namespace std;

// 1. SORT BY BUBBLE
void BubbleSort(long* array, data_arr* data, long size)
{
	// время начала 
	data->start = clock();

	// сортировка пузырьком
	for (long* arr = array + size - 1; arr > array; arr--, size--)
	{
		for (long* i = array; i < arr; i++)
		{
			// увеличение счётчика сравнений
			data->comp++;
			// если текущий элемент больше следующего
			if (*i > *(i + 1))
			{
				swap(*i, *(i + 1));

				// увеличение счётчика перемещение 
				data->moving++;
			}
		}
	}

	// время окончания
	data->stop = clock();

	// запись времени выполнения в структуру
	data->time = data->stop - data->start;
}
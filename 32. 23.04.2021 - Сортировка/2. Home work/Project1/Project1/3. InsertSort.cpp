#include <iostream>

#include "head.h"

using namespace std;

// 3. SORT BY INSERTS
void InsertSort(long* array, data_arr* data)
{
	// время начала
	data->start = clock();

	long* tmp = new long;

	long* k;

	for (long* i = array; i < array + data->sizeArray; i++)
	{
		*tmp = *i;

		// увеличение счётчика сравнений
		data->comp++;

		for (k = i - 1; k >= array && *k > *tmp; k--)
		{
			// увеличение счётчика сравнений
			data->comp++;

			data->moving++;

			*(k + 1) = *k;
		}

		*(k + 1) = *tmp;
	}

	// время окончания
	data->stop = clock();

	// время выполнения
	data->time = data->stop - data->start;
}

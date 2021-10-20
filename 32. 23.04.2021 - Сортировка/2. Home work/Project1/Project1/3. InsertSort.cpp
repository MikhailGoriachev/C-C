#include <iostream>

#include "head.h"

using namespace std;

// 3. SORT BY INSERTS
void InsertSort(long* array, data_arr* data)
{
	// ����� ������
	data->start = clock();

	long* tmp = new long;

	long* k;

	for (long* i = array; i < array + data->sizeArray; i++)
	{
		*tmp = *i;

		// ���������� �������� ���������
		data->comp++;

		for (k = i - 1; k >= array && *k > *tmp; k--)
		{
			// ���������� �������� ���������
			data->comp++;

			data->moving++;

			*(k + 1) = *k;
		}

		*(k + 1) = *tmp;
	}

	// ����� ���������
	data->stop = clock();

	// ����� ����������
	data->time = data->stop - data->start;
}

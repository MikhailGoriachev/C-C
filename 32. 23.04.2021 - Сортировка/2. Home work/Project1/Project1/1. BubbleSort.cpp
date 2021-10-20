#include <iostream>

#include "head.h"

using namespace std;

// 1. SORT BY BUBBLE
void BubbleSort(long* array, data_arr* data, long size)
{
	// ����� ������ 
	data->start = clock();

	// ���������� ���������
	for (long* arr = array + size - 1; arr > array; arr--, size--)
	{
		for (long* i = array; i < arr; i++)
		{
			// ���������� �������� ���������
			data->comp++;
			// ���� ������� ������� ������ ����������
			if (*i > *(i + 1))
			{
				swap(*i, *(i + 1));

				// ���������� �������� ����������� 
				data->moving++;
			}
		}
	}

	// ����� ���������
	data->stop = clock();

	// ������ ������� ���������� � ���������
	data->time = data->stop - data->start;
}
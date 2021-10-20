#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "head.h"

using namespace std;

// 2. SORT BY SELECTION
void SelectSort(long* array, data_arr* data)
{
	// ����� ������
	data->start = clock();

	for (long* arr = array; arr < array + data->sizeArray - 1; arr++)
	{
		for (long* i = arr; i < array + data->sizeArray; i++)
		{
			// ���������� �������� ���������
			data->comp++;

			if (*i < *arr)
			{
				for (long* k = i + 1; k < array + data->sizeArray; k++)
				{
					// ���������� �������� ���������
					data->comp++;

					if (*k < *i)
					{
						i = k;
					}
				}

				// ���������� �������� ����������� 
				data->moving++;

				swap(*arr, *i);

				break;
			}
		}
	}

	// ����� ���������
	data->stop = clock();

	// ����� ����������
	data->time = data->stop - data->start;
}

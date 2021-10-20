#include <iostream>

#include "head.h"

using namespace std;

// 4. QUICK SORT
void QuickSort(long* array, long size, data_arr* data)
{
	// ��������� �� �������� ��������

	// ��������� 1
	long* i = new long;

	*i = 0;

	// ��������� 2
	long* k = new long;

	*k = size - 1;

	// ����������� �������
	long* centr = new long;

	*centr = array[size >> 1];

	// ���������� �������
	do
	{
		// ���������� �������� ���������
		data->comp++;

		// ���� �������� �������� ������� ��������� ������ �������� ������������ ��������
		while (*(array + *i) < *centr)
		{
			++* i;

			// ���������� �������� ���������
			data->comp++;
		}
			
		// ���������� �������� ���������
		data->comp++;

		// ���� �������� �������� ������� ��������� ������ �������� ������������ ��������
		while (*(array + *k) > *centr)
		{
			--* k;

			// ���������� �������� ���������
			data->comp++;
		}

		if (*i <= *k)
		{
			swap(*(array + *i), *(array + *k));

			// ���������� �������� �����������
			data->moving++;

			++* i;
			--* k;
		}

	} while (*i <= *k);

	//delete centr;

	// ����������� ������ �������
	if (*k > 0) QuickSort(array, *k, data);
	// ���������� �������� ���������
	data->comp++;
	if (size > *i) QuickSort(array + *i, size - *i, data);
	// ���������� �������� ���������
	data->comp++;
}

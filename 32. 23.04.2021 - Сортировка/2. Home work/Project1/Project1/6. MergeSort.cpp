#include <iostream>

#include "head.h"

using namespace std;

// ������� 
void merge(long* arr, long lBorder, long rBorder, long* split, data_arr* data);

// 6. MERGE SORT
void MergeSort(long* arr, long leftBorder, long rightBorder, data_arr* data)
{
	// ������ ������� ����������
	long* split = new long;

	// ���������� �������� ���������
	data->comp++;

	// ���� ����� ������� �� ����� ������
	if (leftBorder < rightBorder)
	{
		*split = (leftBorder + rightBorder) / 2;

		// ���������� ����� �����
		MergeSort(arr, leftBorder, *split, data);

		// ���������� ������ �����
		MergeSort(arr, 1 + *split, rightBorder, data);

		// ���������� � ������� ����� � ����� ������
		merge(arr, leftBorder, rightBorder, split, data);
	}

	delete split;
}

// ������� 
void merge(long* arr, long lBorder, long rBorder, long* split, data_arr* data)
{

	// ��������� �����
	long* temp = new long[rBorder - lBorder + 1];

	long* temp_p = temp;

	long* pos1 = arr + lBorder;
	long* pos2 = arr + *split + 1;

	// ���������� �������� ���������
	data->comp++;

	// ���� ���������� ������
	for (; pos1 <= arr + *split && pos2 <= arr + rBorder;)
	{
		// ���������� �������� ���������
		data->comp++;

		data->moving++;

		// ���� ������� ������ ����� ������, �������� �� ������ �����
		if (*pos1 > *pos2)
			*temp_p++ = *pos2++;
		else
			*temp_p++ = *pos1++;
	}
	
	// ���������� �������� ���������
	data->comp++;

	// ����������� ���������� ��������� ������� 
	while (pos1 <= arr + *split)
	{
		// ���������� �������� ���������
		data->comp++;
		
		data->moving++;

		*temp_p++ = *pos1++;
	}

	// ���������� �������� ���������
	data->comp++;

	while (pos2 <= arr + rBorder)
	{
		// ���������� �������� ���������
		data->comp++;

		data->moving++;

		*temp_p++ = *pos2++;
	}

	temp_p = temp;

	// ���������� ������ ���������� �� ������ 
	for (long pos = 0; temp_p < temp + rBorder - lBorder + 1; pos++)
	{
		// ���������� �������� ���������
		data->comp++;

		data->moving++;

		*(arr + lBorder + pos) = *temp_p++;
	}

	delete[] temp;
}
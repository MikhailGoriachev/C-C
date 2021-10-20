#include <iostream>

#include "head.h"

using namespace std;

// 4. QUICK SORT
void QuickSort(long* array, long size, data_arr* data)
{
	// указатели на исходных позициях

	// указатель 1
	long* i = new long;

	*i = 0;

	// указатель 2
	long* k = new long;

	*k = size - 1;

	// центральный элемент
	long* centr = new long;

	*centr = array[size >> 1];

	// разделение массива
	do
	{
		// увеличение счётчика сравнений
		data->comp++;

		// пока значение элемента первого указателя меньше значения центрального элемента
		while (*(array + *i) < *centr)
		{
			++* i;

			// увеличение счётчика сравнений
			data->comp++;
		}
			
		// увеличение счётчика сравнений
		data->comp++;

		// пока значение элемента второго указателя больше значения центрального элемента
		while (*(array + *k) > *centr)
		{
			--* k;

			// увеличение счётчика сравнений
			data->comp++;
		}

		if (*i <= *k)
		{
			swap(*(array + *i), *(array + *k));

			// увеличение счётчика перемещений
			data->moving++;

			++* i;
			--* k;
		}

	} while (*i <= *k);

	//delete centr;

	// рекурсивные вызовы функции
	if (*k > 0) QuickSort(array, *k, data);
	// увеличение счётчика сравнений
	data->comp++;
	if (size > *i) QuickSort(array + *i, size - *i, data);
	// увеличение счётчика сравнений
	data->comp++;
}

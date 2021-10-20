#include <iostream>

using namespace std;

void PrintArray(int* a, int size)
{
	for (size_t i = 0; i < 7; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void selection_sort(int array[], const size_t size)
{
    // цикл по всем элементам
    for (size_t i = 0; i < size - 1; i++)
    {
        // индекс минимального элемента
        size_t min_index = i;

        // цикл для поиска минимального элемента
        for (size_t k = i + 1; k < size; k++)
        {
            // если текущий элемент миньше минимального элемента
            if (array[k] < array[min_index])
            {
                // изменить индекс минимального элемента
                min_index = k;
            }
        }

        // минимальный элемент не стоит на своём месте
        if (min_index != i)
        {
            // поменять местами текущий элемент и минимальный элемент
            swap(array[i], array[min_index]);
        }

        //PrintArray(array, size);
    }
}

void main()
{
	int a[] = { 3, 4, 6, 2, 0, 9, 1 };

	PrintArray(a, 7);

    selection_sort(a, 7);

    PrintArray(a, 7);
}
#include <iostream>

#include "head.h"
using namespace std;

// 7. HEAP SORT

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void heapify(long* arr, long n, long i, data_arr* data)
{
    long largest = i;
    // Инициализируем наибольший элемент как корень
    long l = 2 * i + 1; // левый = 2*i + 1
    long r = 2 * i + 2; // правый = 2*i + 2

    data->comp++;

 // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    data->comp++;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    data->comp++;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        data->moving++;

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest, data);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void HeapSort(long* arr, data_arr* data)
{
    data->start = clock();

    long n = data->sizeArray;

    // Построение кучи (перегруппируем массив)
    for (long i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, data);

    // Один за другим извлекаем элементы из кучи
    for (long i = n - 1; i >= 0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        data->moving++;

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0, data);
    }

    data->stop = clock();

    data->time = data->stop - data->start;
}

/* Вспомогательная функция для вывода на экран массива размера n*/
/*void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Управляющая программа
/*int HeapSort()
{
    int arr[] = { 1, 5, 3, 4, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}*/
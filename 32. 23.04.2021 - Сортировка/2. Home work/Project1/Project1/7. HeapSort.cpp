#include <iostream>

#include "head.h"
using namespace std;

// 7. HEAP SORT

// ��������� ��� �������������� � �������� ���� ��������� � �������� ����� i, ��� ��������
// �������� � arr[]. n - ������ ����

void heapify(long* arr, long n, long i, data_arr* data)
{
    long largest = i;
    // �������������� ���������� ������� ��� ������
    long l = 2 * i + 1; // ����� = 2*i + 1
    long r = 2 * i + 2; // ������ = 2*i + 2

    data->comp++;

 // ���� ����� �������� ������� ������ �����
    if (l < n && arr[l] > arr[largest])
        largest = l;

    data->comp++;

    // ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
    if (r < n && arr[r] > arr[largest])
        largest = r;

    data->comp++;

    // ���� ����� ������� ������� �� ������
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        data->moving++;

        // ���������� ����������� � �������� ���� ���������� ���������
        heapify(arr, n, largest, data);
    }
}

// �������� �������, ����������� ������������� ����������
void HeapSort(long* arr, data_arr* data)
{
    data->start = clock();

    long n = data->sizeArray;

    // ���������� ���� (�������������� ������)
    for (long i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, data);

    // ���� �� ������ ��������� �������� �� ����
    for (long i = n - 1; i >= 0; i--)
    {
        // ���������� ������� ������ � �����
        swap(arr[0], arr[i]);

        data->moving++;

        // �������� ��������� heapify �� ����������� ����
        heapify(arr, i, 0, data);
    }

    data->stop = clock();

    data->time = data->stop - data->start;
}

/* ��������������� ������� ��� ������ �� ����� ������� ������� n*/
/*void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// ����������� ���������
/*int HeapSort()
{
    int arr[] = { 1, 5, 3, 4, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}*/
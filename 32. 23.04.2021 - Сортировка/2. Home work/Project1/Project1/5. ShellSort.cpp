#include <iostream>

#include "head.h"

using namespace std;

// 5. SORT BY SHELL
int increm(long* inc, long size, data_arr* data) 
{
    // inc[] ������, � ������� ��������� ����������
    // size ����������� ����� �������
    int p1, p2, p3, s;

    p1 = p2 = p3 = 1;
    s = -1;
    do {// ��������� ������ ��������� �� ������� ������� ��������
        if (++s % 2) 
        {
            inc[s] = 8 * p1 - 6 * p2 + 1;
        }
        else 
        {
            inc[s] = 9 * p1 - 9 * p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
        p1 *= 2;
        // ��������� ������, ���� ������� ���������� ���� �� � 3 ���� ������ ���������� ��������� � �������

        // ���������� �������� ���������
        data->comp++;

    } while (3 * inc[s] < size);

    // ���������� �������� ���������
    data->comp++;

    return s > 0 ? --s : 0;// ���������� ���������� ��������� � �������
}

void ShellSort(long* a, data_arr* data) 
{
    data->start = clock();

    long size = data->sizeArray;

    // inc ���������, ���������� ����� ���������� ���������
    // i � j ����������� ���������� �����
    // seq[40] ������, � ������� �������� ����������
    long inc, i, j, seq[40], temp;
    int s;//���������� ��������� � ������� seq[40]

    // ���������� ������������������ ����������
    s = increm(seq, size, data);

    while (s >= 0) 
    {
        //��������� �� ������� ��������� ����������
        inc = seq[s--];
        // ���������� ��������� � ������������ inc
        for (i = inc; i < size; i++) 
        {
            temp = a[i];

            // ���������� �������� ���������
            data->comp++;

            // �������� �������� �� ��� ���, ���� �� ������ �� ����� ��� �� ���������� � ������ �������
            for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc)
            {
                // ���������� �������� ���������
                data->comp++;

                // ���������� �������� �����������
                data->moving++;

                a[j + inc] = a[j];
            }
            // ����� ���� ������� ������ �� ����� j+inc �������, ������� ��������� �� i �����
            a[j + inc] = temp;
        }
    }

    data->stop = clock();

    data->time = data->stop - data->start;
}

// ���������� �����������; �������� ������� ��������
/*long searchIncrement(long* inc, long* size, long* s)
{
    //// ����������
    //long* p1 = new long;
    //long* p2 = new long;
    //long* p3 = new long;

    long point1, point2, point3;

    long* p1 = &point1;
    long* p2 = &point2;
    long* p3 = &point3;


    *p1 = *p2 = *p3 = 1;

    *s = -1;

    // ���� ��������� ��� ������� � ��� ���� ������ ����� �������
    do
    {
        // ���� ������� ����� �������� ������� ����������� �� ������
        if (++*s % 2)
        {
            inc[*s] = 8 * *p1 - 6 * *p2 + 1;
        }

        // ���� ������
        else
        {
            inc[*s] = 9 * *p1 - 9 * *p3 + 1;

            // ��������� �� ��� ����������
            *p2 *= 2;
            *p3 *= 2;
        }

        // ��������� �� ��� ����������
        *p1 *= 2;

    } while (inc[*s] * 3 < *size);

    // �������� ������
    //delete p1, p2, p3;

    // ���� ��������� � � ������� ����������� ������ ����
    if (*s > 0)
        return -- * s;

    return 0;
}

void ShellSort(long* arr, data_arr* data)
{

   // // ������� ���������
   // long* increment = new long;

   // // i-��
   // long* i = new long;

   // // k-��
   // long* k = new long;

   // // ��������� �� �����
   // long* size = &data->sizeArray;

   // // �������� ��������
   // long* temp = new long;

   // // ���������� ��� ������� ������ �����������
   // long* s = new long;
   // 

    long _increment, _i, _k, _size, _temp, _s;

    long* increment = &_increment;

    long* i = &_i;

    long* k = &_k;

    _size = data->sizeArray;

    long* size = &_size;

    long* temp = &_temp;

    long* s = &_s;

    // ������ ��� �����������
    long* increments = new long[40];

    // ����� ������ 
    data->start = clock();


    // ������ ������� ������ ����������� ��� ����������
    *s = searchIncrement(increments, &data->sizeArray, s);

    // ���������� �� ��� ��� ���� ����� �������� � ������� �����������
    // �� ����� ������ ����
    while (*s >= 0)
    {
        // ������� ���������
        *increment = increments[*s];

        --* s;

        // ���������� ���������
        for (*i = *increment; *i < *size; ++*i)
        {
            // �������� �������� ��������
            *temp = *(arr + *i);

            // ��������� ��������� � ������� ������
            for (*k = *i - *increment; *k >= 0 && *(arr + *k) > *temp; *k -= *increment)
            {
                // ����������� ��������
                *(arr + *k + *increment) = *(arr + *k);
            }

            // ������� �������� �� ���������� �����
            *(arr + *k + *increment) = *temp;
        }
    }

    // ����� ���������
    data->stop = clock();

    // ����� ����������
    data->time = data->stop - data->start;
}*/
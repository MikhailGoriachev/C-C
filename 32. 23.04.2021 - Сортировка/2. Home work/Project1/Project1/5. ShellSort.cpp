#include <iostream>

#include "head.h"

using namespace std;

// 5. SORT BY SHELL
int increm(long* inc, long size, data_arr* data) 
{
    // inc[] массив, в который заносятся инкременты
    // size размерность этого массива
    int p1, p2, p3, s;

    p1 = p2 = p3 = 1;
    s = -1;
    do {// заполняем массив элементов по формуле Роберта Седжвика
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
        // заполняем массив, пока текущая инкремента хотя бы в 3 раза меньше количества элементов в массиве

        // увеличение счётчика сравнений
        data->comp++;

    } while (3 * inc[s] < size);

    // увеличение счётчика сравнений
    data->comp++;

    return s > 0 ? --s : 0;// возвращаем количество элементов в массиве
}

void ShellSort(long* a, data_arr* data) 
{
    data->start = clock();

    long size = data->sizeArray;

    // inc инкремент, расстояние между элементами сравнения
    // i и j стандартные переменные цикла
    // seq[40] массив, в котором хранятся инкременты
    long inc, i, j, seq[40], temp;
    int s;//количество элементов в массиве seq[40]

    // вычисление последовательности приращений
    s = increm(seq, size, data);

    while (s >= 0) 
    {
        //извлекаем из массива очередную инкременту
        inc = seq[s--];
        // сортировка вставками с инкрементами inc
        for (i = inc; i < size; i++) 
        {
            temp = a[i];

            // увеличение счётчика сравнений
            data->comp++;

            // сдвигаем элементы до тех пор, пока не дойдем до конца или не упорядочим в нужном порядке
            for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc)
            {
                // увеличение счётчика сравнений
                data->comp++;

                // увеличение счётчика перемещений
                data->moving++;

                a[j + inc] = a[j];
            }
            // после всех сдвигов ставим на место j+inc элемент, который находился на i месте
            a[j + inc] = temp;
        }
    }

    data->stop = clock();

    data->time = data->stop - data->start;
}

// вычисление инкрементов; алгоритм Роберта Седжвика
/*long searchIncrement(long* inc, long* size, long* s)
{
    //// переменные
    //long* p1 = new long;
    //long* p2 = new long;
    //long* p3 = new long;

    long point1, point2, point3;

    long* p1 = &point1;
    long* p2 = &point2;
    long* p3 = &point3;


    *p1 = *p2 = *p3 = 1;

    *s = -1;

    // пока инкремент как минимум в три раза меньше длины массива
    do
    {
        // если текущий номер элемента массива инкрементов не чётный
        if (++*s % 2)
        {
            inc[*s] = 8 * *p1 - 6 * *p2 + 1;
        }

        // если чётный
        else
        {
            inc[*s] = 9 * *p1 - 9 * *p3 + 1;

            // умножение на два переменных
            *p2 *= 2;
            *p3 *= 2;
        }

        // умножение на два переменной
        *p1 *= 2;

    } while (inc[*s] * 3 < *size);

    // отчистка памяти
    //delete p1, p2, p3;

    // если елементов в в массиве инкрементов больше нуля
    if (*s > 0)
        return -- * s;

    return 0;
}

void ShellSort(long* arr, data_arr* data)
{

   // // текущий инкремент
   // long* increment = new long;

   // // i-ая
   // long* i = new long;

   // // k-ая
   // long* k = new long;

   // // указатель на длину
   // long* size = &data->sizeArray;

   // // значение элемента
   // long* temp = new long;

   // // переменная для функции поиска инкрементов
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

    // массив для инкрементов
    long* increments = new long[40];

    // время начала 
    data->start = clock();


    // запуск функции поиска инкрементов для сортировки
    *s = searchIncrement(increments, &data->sizeArray, s);

    // сортировка до тех пор пока номер элемента в массиве инкрементов
    // не будет меньше нуля
    while (*s >= 0)
    {
        // текущий инкремент
        *increment = increments[*s];

        --* s;

        // сортировка вставками
        for (*i = *increment; *i < *size; ++*i)
        {
            // значение текущего элемента
            *temp = *(arr + *i);

            // сравнение элементов в текущей группе
            for (*k = *i - *increment; *k >= 0 && *(arr + *k) > *temp; *k -= *increment)
            {
                // перемещение элемента
                *(arr + *k + *increment) = *(arr + *k);
            }

            // вставка значения на выделенное место
            *(arr + *k + *increment) = *temp;
        }
    }

    // время окончания
    data->stop = clock();

    // время выполнения
    data->time = data->stop - data->start;
}*/
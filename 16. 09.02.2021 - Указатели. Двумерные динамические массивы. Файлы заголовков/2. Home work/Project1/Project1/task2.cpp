#include <iostream>

using namespace std;

// вывод двумерного динамического массива
void out2DArrayTask2(int** a, size_t rows);

void task2()
{
    srand(time(0));

	// 2. Пользователь вводит количество строк двумерного динамического массива, программа выводит массив такой формы:
    //  5
    //  5 5
    //  5 5 5
    //  5 5 5 5
    //  5 5	5 5 5

    //  Заполнить случайными числами

    size_t rows;

    cout << "Enter rows: ";
    cin >> rows;

    cout << endl;

    // содание массива указателей двумерного массива 
    int** a = new int* [rows];

    // создание одномерных массивов 
    for (size_t i = 0; i < rows; i++)
    {
        a[i] = new int[i+1];
        for (size_t k = 0; k < i+1; k++)
        {
            a[i][k] = rand() % 10;
        }
    }
    
    // вывод двумернорного динамического массива
    out2DArrayTask2(a, rows);

    delete[] a;
}

// вывод двумерного динамического массива
void out2DArrayTask2(int** a, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t k = 0; k < i+1; k++)
        {
            cout << a[i][k] << " ";
        }
        cout << endl;
    }
}
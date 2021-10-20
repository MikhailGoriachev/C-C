#include <iostream>

using namespace std;

// ����� ���������� ������������� �������
void out2DArrayTask2(int** a, size_t rows);

void task2()
{
    srand(time(0));

	// 2. ������������ ������ ���������� ����� ���������� ������������� �������, ��������� ������� ������ ����� �����:
    //  5
    //  5 5
    //  5 5 5
    //  5 5 5 5
    //  5 5	5 5 5

    //  ��������� ���������� �������

    size_t rows;

    cout << "Enter rows: ";
    cin >> rows;

    cout << endl;

    // ������� ������� ���������� ���������� ������� 
    int** a = new int* [rows];

    // �������� ���������� �������� 
    for (size_t i = 0; i < rows; i++)
    {
        a[i] = new int[i+1];
        for (size_t k = 0; k < i+1; k++)
        {
            a[i][k] = rand() % 10;
        }
    }
    
    // ����� ������������� ������������� �������
    out2DArrayTask2(a, rows);

    delete[] a;
}

// ����� ���������� ������������� �������
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
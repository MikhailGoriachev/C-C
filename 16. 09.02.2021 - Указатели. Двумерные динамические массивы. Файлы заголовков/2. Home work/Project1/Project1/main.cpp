#include <iostream>
#include <conio.h>
#include "Header.h"

using namespace std;

int* enterTask();

void main()
{
	for (size_t task = *enterTask(); task != 0; task = *enterTask())
	{
        if (task == 1)
        {
            task1();
        }

        if (task == 2)
        {
            task2();
        }

        if (task == 3)
        {
            task3();
        }

        if (task == 4)
        {
            task4();
        }

        if (task == 5)
        {
            task5();
        }
	}
}

int* enterTask()
{
    int num;
    char m[1];

    int* n = &num;

    while (true)
    {
        cout << endl << "--------------------------------------------" << endl << endl;
        cout << "Enter the task number (0 = exit): ";
        do
        {
            m[0] = _getch();
        } while (m[0] < '0' || m[0] > '9');
        num = atoi(m);
        cout << num << endl;
        cout << endl << "--------------------------------------------" << endl << endl;
        // ---------------------- parameters for entering the task number
        if (num == 0)
            break;
        if (num < 1)
        {
            cout << "Error! Pleace, enter the correct number." << endl << endl;
            continue;
        }
        // --------------------------------------------------------------
        break;
    }

    return n;

}

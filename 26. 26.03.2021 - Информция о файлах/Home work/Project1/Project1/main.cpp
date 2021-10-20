#include <iostream>
#include "head.h"

using namespace std;

int* enterTask(int* task);

void main()
{
	for (int task = *enterTask(&task); task != 0; enterTask(&task))
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
	}
}

int* enterTask(int* task)
{
	cout << "-----------------------------------------------" << endl << endl;
	cout << "Enter task number: ";
	cin >> *task;

	while (*task < 0)
	{
		cout << "Error! Number rask < 0. Enter again:";
		cin >> *task;
	}

	cout << endl;
	cout << "-----------------------------------------------" << endl << endl;

	return task;
}

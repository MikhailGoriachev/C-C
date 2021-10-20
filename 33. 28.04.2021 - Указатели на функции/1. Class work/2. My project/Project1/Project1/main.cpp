#include <iostream>

#include "head.h"

using namespace std;

void main()
{
	int n;

	while (true)
	{
		system("cls");

		cout << "Enter number task: ";
		cin >> n;

		system("cls");

		if (n == 1)
		{
			task1();
		}
		
		if (n == 2)
		{
			task2();
		}
		
		if (n == 3)
		{
			task3();
		}
		
		if (n == 4)
		{
			task4();
		}
	}
}
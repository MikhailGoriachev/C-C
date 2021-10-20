#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;

void pressAnyKey()
{
	cout << "\n\n\n\nPRESS ANY KEY..." << endl;

	_getch();
}

void main()
{
	int i;

	while (true)
	{
		system("cls");

		cout << "Enter number task: ";
		cin >> i;

		system("cls");

		if (i == 1)
		{
			task1();
		}

		if (i == 2)
		{
			task2();
		}
	}

}
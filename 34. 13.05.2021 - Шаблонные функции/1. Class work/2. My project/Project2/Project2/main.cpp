#include <iostream>
#include <conio.h>

#include "head.h"
using namespace std;

// ��������� �������
template <typename T, typename T2>
T add(T a, T2 b)
{
	return a + b;
}

// ��������� ������ � ������� ��� ������������ �����

void main()
{
	int n;

	while (true)
	{
		system("cls");

		cout << "Enter task: ";
		cin >> n;

		system("cls");

		if (n == 1)
		{
			task1();
		}
	}


}
#include <iostream>
#include <conio.h>

#include "head.h"
using namespace std;

// шаблонная функция
template <typename T, typename T2>
T add(T a, T2 b)
{
	return a + b;
}

// принимает массив и находит два максимальных числа

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
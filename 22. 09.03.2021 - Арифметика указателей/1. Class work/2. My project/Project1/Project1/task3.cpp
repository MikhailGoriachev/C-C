#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

void task3()
{
	// пользователь вводит строку, программа удал€ет все повтор€ющиес€ сиволы

	char* str = (char*)malloc(sizeof(char) * 40);

	cout << "Enter str: ";
	cin.ignore();
	cin.getline(str, 40);

	char* p = str + 1;

	for (char temp = *str; *p; p++)
	{
		if (*p == temp)
		{
			for (char* n = p; *(n-1); n++)
			{
				swap(*n, *(n + 1));
			}
			p--;
		}
		temp = *p;
	}

	cout << str << endl;

	free(str);
}

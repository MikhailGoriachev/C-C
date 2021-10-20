#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

void task2()
{
	// пользователь вводит строку программа заменяет все цифры на '!'

	char* a = (char*)malloc(sizeof(char) * 40);

	cout << "Enter string: ";
	cin.ignore();
	cin.getline(a, 40);

	for (char* p = a; *p ; p++)
	{
		if (*p >= '0' && *p <= '9')
			*p = '!';
	}

	cout << a << endl;

	free(a);
}

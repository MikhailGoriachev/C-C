#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

void task1()
{
	// арифметика указателей

	// вользователь вводит строку, программа считает количество букв 'a'

	char s[40];

	cin >> s;

	size_t a_count = 0;

	/*for (size_t i = 0; s[i] != 0; i++)
	{
		if (s[i] == 'a')
			a_count++;
	}*/

	/*cout << s << endl;

	cout << *(s + 1) << endl; // s[i] = *(s + i)

	// указатель на любой тип данных
	void* p = s + 1;
	cout << p << endl;

	cout << &p << endl;
	*/

	// перебор всех символов строки s
	for (char* p = s; *p; p++) // *p это *p != 0
	{
		if (*p == 'a')
			a_count++;
	}
	cout << "Number of 'a' = " << a_count << endl;
}

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

void task5()
{
	// пользователь вводит 2 строки, программа подсчитывает, 
	// сколько раз вторая строка входит в первую

	// первая строка
	char* a = (char*)malloc(sizeof(char) * 40);

	// ввод первой строки
	cout << "Enter firts string: ";
	cin.ignore();
	cin.getline(a, 40);

	// вторая строка 
	char* b = (char*)malloc(sizeof(char) * 40);

	// ввод второй строки
	cout << "Enter second string: ";
	cin.getline(b, 40);

	size_t len_b = strlen(b);

	// если первая строка короче, чем вторая 
	if (strlen(a) < len_b)
	{
		cout << "ERROR! First line is too short!" << endl;
		return;
	}

	size_t count = 0;

	// сканирование строк
	for (char* P_a = a; *(P_a + len_b - 1); P_a++)
	{
		// флаг равности строк по умолчанию true
		bool flag = true;

		// сравнение второй строки с первой 
		for (char* P_ta = P_a, *P_b = b; *P_b; P_b++, P_ta++)
		{
			// если элементы первой строки и второй не равны
			if (*P_ta != *P_b)
			{
				flag = false;
				break;
			}
		}

		// если строки равны 
		if (flag)
			count++;
	}

	cout << "Count: " << count << endl;
}

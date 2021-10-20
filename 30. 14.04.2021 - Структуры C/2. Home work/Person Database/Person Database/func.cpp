#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;

// вывод линии
void outLine()
{
	cout << "\n----------------------------------------------------------------\n\n";
}

// ожидание нажати€ любой клавиши 
void pressAnyKey()
{
	cout << "\n\n\nPRESS ANY KEY [..]" << endl;

	_getch();
}

// генераци€ случайных символов
void GenerationRandomCymbols(char* str, size_t size)
{
	// сторка символов
	char* randomCymb = new char[63];

	strcpy(randomCymb, "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890");

	// заполнение строки случайными символами
	for (char* str_p = str; str_p < str + size; str_p++)
	{
		*str_p = *(randomCymb + (rand() % 62));
	}
}
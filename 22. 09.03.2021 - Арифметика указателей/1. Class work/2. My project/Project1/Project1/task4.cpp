#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

void task4()
{
	// пользователь вводит строку, программа копирует её в другую
	// но наоборот

	// исходная строка
	char* source = (char*)malloc(sizeof(char) * 40);

	// ввод исходной строки
	cout << "Enter string: ";
	cin.ignore();
	cin.getline(source, 40);
	
	// длина исходной строки
	size_t len = strlen(source);

	// строка для копии по длине исходной строки
	char* copy = (char*)malloc(sizeof(char) * len + 1);

	// переворот строки
	for (char* P_source = source + len - 1, * P_copy = copy; *P_source; P_source--, P_copy++)
	{
		*P_copy = *P_source;
	}

	*(copy + len) = 0;

	cout << copy << endl;

	free(copy);
	free(source);
}

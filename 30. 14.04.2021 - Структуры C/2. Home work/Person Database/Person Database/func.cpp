#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;

// ����� �����
void outLine()
{
	cout << "\n----------------------------------------------------------------\n\n";
}

// �������� ������� ����� ������� 
void pressAnyKey()
{
	cout << "\n\n\nPRESS ANY KEY [..]" << endl;

	_getch();
}

// ��������� ��������� ��������
void GenerationRandomCymbols(char* str, size_t size)
{
	// ������ ��������
	char* randomCymb = new char[63];

	strcpy(randomCymb, "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890");

	// ���������� ������ ���������� ���������
	for (char* str_p = str; str_p < str + size; str_p++)
	{
		*str_p = *(randomCymb + (rand() % 62));
	}
}
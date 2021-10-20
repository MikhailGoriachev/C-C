#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

void task4()
{
	// ������������ ������ ������, ��������� �������� � � ������
	// �� ��������

	// �������� ������
	char* source = (char*)malloc(sizeof(char) * 40);

	// ���� �������� ������
	cout << "Enter string: ";
	cin.ignore();
	cin.getline(source, 40);
	
	// ����� �������� ������
	size_t len = strlen(source);

	// ������ ��� ����� �� ����� �������� ������
	char* copy = (char*)malloc(sizeof(char) * len + 1);

	// ��������� ������
	for (char* P_source = source + len - 1, * P_copy = copy; *P_source; P_source--, P_copy++)
	{
		*P_copy = *P_source;
	}

	*(copy + len) = 0;

	cout << copy << endl;

	free(copy);
	free(source);
}

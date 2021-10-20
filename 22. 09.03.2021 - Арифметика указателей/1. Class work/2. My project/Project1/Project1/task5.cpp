#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "head.h"

using namespace std;

void task5()
{
	// ������������ ������ 2 ������, ��������� ������������, 
	// ������� ��� ������ ������ ������ � ������

	// ������ ������
	char* a = (char*)malloc(sizeof(char) * 40);

	// ���� ������ ������
	cout << "Enter firts string: ";
	cin.ignore();
	cin.getline(a, 40);

	// ������ ������ 
	char* b = (char*)malloc(sizeof(char) * 40);

	// ���� ������ ������
	cout << "Enter second string: ";
	cin.getline(b, 40);

	size_t len_b = strlen(b);

	// ���� ������ ������ ������, ��� ������ 
	if (strlen(a) < len_b)
	{
		cout << "ERROR! First line is too short!" << endl;
		return;
	}

	size_t count = 0;

	// ������������ �����
	for (char* P_a = a; *(P_a + len_b - 1); P_a++)
	{
		// ���� �������� ����� �� ��������� true
		bool flag = true;

		// ��������� ������ ������ � ������ 
		for (char* P_ta = P_a, *P_b = b; *P_b; P_b++, P_ta++)
		{
			// ���� �������� ������ ������ � ������ �� �����
			if (*P_ta != *P_b)
			{
				flag = false;
				break;
			}
		}

		// ���� ������ ����� 
		if (flag)
			count++;
	}

	cout << "Count: " << count << endl;
}

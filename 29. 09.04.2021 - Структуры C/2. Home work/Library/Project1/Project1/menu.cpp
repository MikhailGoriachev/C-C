#include <iostream>
#include <conio.h>
#include "head.h"

using namespace std;

// ����
void menu(int* mode)
{
	// ����� ������� ����
	while (true)
	{
		system("cls");

		outline();

		cout << "MENU" << endl;

		outline();

		// ������ ����

		// 1. �������� ���� ����
		cout << "* 1. ALL BOOKS *" << endl;

		// 2. ����� �����
		cout << "* 2. SEARCH BOOK *" << endl;

		// 3. ������� ����� 
		cout << "* 3. DOWNLOAD BOOK *" << endl;

		// 4. �������� �����(������ ���������������)
		cout << "* 4. ADD BOOK(ADMIN GROUP) *" << endl;

		// 5. ������� �����(������ ���������������)
		cout << "* 5. DELETE BOOK(ADMIN GROUP) *" << endl;

		// 6. ���������� ����������
		cout << "* 6. ACCOUNT MANAGEMENT(ADMIN GROUP)" << endl;

		// ����� �� ���������
		cout << "* EXIT[ESC] *" << endl;

		// ���� 
		*mode = (int)_getch();

		// ���� ���� ������ ����� �� 1 �� 6
		if ((char)*mode > '0' && (char)*mode < '7')
			return;

		// ���� ���� ������ ������� esc
		if (*mode == 27)
		{
			*mode = 0;
		}
	}
}
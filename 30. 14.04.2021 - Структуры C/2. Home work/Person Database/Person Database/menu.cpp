#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;

// ����
void menu(char* c)
{
	while (true)
	{
		system("cls");

		outLine();

		cout << "MENU" << endl;

		outLine();

		// ������ ����
		// 1. ��� ����
		// 2. ����� ��������
		// 3. �������� ��������(admin group)
		// 4. ������� ��������(admin group)
		// 5. ���������� ����������(admin group)
		// 6. ������������� ������(admin group)

		// 1. ��� ����
		cout << "1. LIST PERSON" << endl;
		// 2. ����� ��������
		cout << "2. SEARCH PERSON" << endl;
		// 3. �������� ��������(admin group)
		cout << "3. ADD PERSON (ADMIN GROUP)" << endl;
		// 4. ������� ��������(admin group)
		cout << "4. DELETE PERSON (ADMIN GROUP)" << endl;
		// 5. ���������� ����������(admin group)
		cout << "5. ACCOUNT MANAGEMENT (ADMIN GROUP)" << endl;
		// 6. ������������� ������(admin group)
		cout << "6. DATA ENCRYPTION (ADMIN GROUP)" << endl;
		// ����� �� ���������
		cout << "\n\n\n\n\n[ESC] EXIT" << endl;
		// ���� 
		while (true)
		{
			*c = _getch();

			if ((*c >= '0' && *c <= '9') || *c == (char)27)
			{
				return;
			}
		}
	}
}
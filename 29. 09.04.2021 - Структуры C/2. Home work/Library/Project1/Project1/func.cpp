#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

using namespace std;

// �������� ������� ����� �������
void pressAnyKey()
{
	cout << "\n\n\n\nPRESS ANY KEY TO CONTINUE" << endl;

	_getch();
}

// ����� �����
void outline()
{
	cout << "\n--------------------------------------------------------------" << endl << endl;
}
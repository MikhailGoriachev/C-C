#include <iostream>
#include <conio.h>

using namespace std;

void task1()
{
	// ������ � union 
	// ������ �������� � ����� ����� � ������������� ���� �� �����
	union 
	{
		unsigned int color;
		char components[4];
	} cl;

	cout << sizeof(cl) << endl;

	cl.color = 0;
	cl.components[0] = 255;
	cl.components[1] = 255;
	cl.components[2] = 255;
	cl.components[3] = 255;

	cout << cl.color << endl;

	// ������ � �������� ������
	struct {
		unsigned a : 28; // 28 - ���������� ��� ���������� ��� ���� 
		unsigned b : 2;
		unsigned c : 1;
	} test;

	cout << sizeof(test) << endl;

	test.b = 5;


	cout << test.b << endl;

	_getch();
}
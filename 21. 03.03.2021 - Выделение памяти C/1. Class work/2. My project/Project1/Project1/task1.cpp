#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task1()
{	
	// ��������� ������ ���������� ����� C++
	/*int* p = nullptr;
	p = new int;
	*p = 3;
	cout << *p << endl;
	delete p;*/

	// malloc(4)- �������� ������ 4 �����
	/*int* p = (int*)malloc(sizeof(int));
	*p = 3;
	cout << *p << endl;
	// free - ���������� ������
	free(p);*/

	// C++
	/*int* p = nullptr;
	p = new int[5];

	for (size_t i = 0; i < 5; i++)
	{
		cin >> p[i];
	}

	for (size_t i = 0; i < 5; i++)
	{
		cout << p[i] <<  " ";
	}

	cout << *p << endl;

	delete[] p;*/

	// C
	// ��������� ������ ��� ������� ���� int
	/*int* p = (int*)malloc(sizeof(int) * 5);
	
	// ���� ��������� ������� 
	for (size_t i = 0; i < 5; i++)
	{
		cin >> p[i];
	}

	// ����� ��������� �������
	for (size_t i = 0; i < 5; i++)
	{
		cout << p[i] << " ";
	}

	cout << endl;

	// �������� ������� �� ������
	free(p);*/

	// ��������� ������ ��� ������� char
	/*
	char* s = (char*)malloc(200 * sizeof(char));

	cout << "Enter string: ";

	cin >> s;

	cout << s << endl;

	free(s);*/
}
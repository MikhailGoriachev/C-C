#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	// �����
	char login[40];

	// ������
	char password[40];

	// ���� ������
	cout << "Login: ";
	cin.getline(login, 40);

	cout << endl;

	// ���� ������
	cout << "Password: ";
	cin.getline(password, 40);

	cout << endl;

	// ���� �������� ����� � ������ ��������� � �����������
	if ((!strcmp(login, "Mikhail") && !strcmp(password, "Goriachev")) || (!strcmp(login, "admin") && !strcmp(password, "Qwerty12")))
	{
		// �������� ����� exe � ������ ������
		FILE* file = fopen("Project2.exe", "rb");

		// ������� ��������� � ����� � �����
		fseek(file, 0, SEEK_END);

		// ����� ����� exe
		long size = ftell(file);

		// ������ cpp �����
		long start = 53760;

		// �����
		char* buffer = new char[size - start];

		// ��������� � exe ����� ��������� �� ������ cpp ����� � ���
		fseek(file, start, SEEK_SET);

		// ���������� cpp ����� � �����
		fread(buffer, sizeof(char), size - start, file);

		// �������� ����� main.cpp
		FILE* cpp = fopen("main.cpp", "wb");

		// ���������� cpp ����� ��� ���������� ������
		fwrite(buffer, sizeof(char), size - start, cpp);

		// �������� exe ����� 
		fclose(file);

		// �������� cpp �����
		fclose(cpp);

		cout << "Complete" << endl;

		// �������� ������� ����� �������
		_getch();
	}

	// ���� ����� �/��� ������ �������
	else cout << "Error login or password!" << endl;

	// �������� ������� ����� �������
	_getch();
}
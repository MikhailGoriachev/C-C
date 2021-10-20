#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>
#include <direct.h>

#include "struct.h"
#include "head.h"

using namespace std;

extern cypher* sec;

account_data* user;

int* count_acc;

bool admin = false;

// �������������� ���� ������ ����� ����� ����������� ����� ������ ���,
// �� ���� ���� � ���������� ���� ������ ����� �����

// �������� �����; ����������: 0 - ������; 1 - ���� ��������; 2 - ������ ����� �����������
// ����� 10 ���;
int login()
{

	// ���� �������������� 
	char* path = new char[_MAX_PATH];

	// ���� 
	strcpy(path, ".\\Authentication\\login.auth");

	// �������� ����� �������������� � ������ ������� ������
	FILE* file = fopen(path, "rb");

	// ���� ����� �� ���������� ��������� ������ ���� 
	// ��������� ��� ������� ������� ������ root �� ���������
	// � ���������� �������������������
	if (file == nullptr)
	{
		// �������� �� ��, ���������� �� ����� Authentication
		
		// ������ 
		_finddata_t list;

		// ��������� �� ������ � �������� ���
		long point = _findfirst(".\\Authentication", &list);

		// ���� �� ������� ����� �����
		if (point == -1)
		{
			// �������� ����� "Authentication"
			if (_mkdir(".\\Authentication") == -1)
			{
				cout << "ERROR CREATE FOLDER \"Authentication\"" << endl;
				return 0;
			}
		}

		// �������� ����� login.auth � �������� � ������ ��������� ������
		file = fopen(".\\Authentication\\login.auth", "wb");

		// ���� ����� ��������� ������
		if (file == nullptr)
		{
			cout << "ERROR OPEN FILE \"login.auth\"" << endl;
			return 0;
		}

		// ����� ������� ������ admin
		char* login = new char[20];
		strcpy(login, "admin\0");

		// ������ ������� ������ admin
		char* password = new char[20];
		strcpy(password, "123456\0");

		// ������ ������� ����� �����������
		if (!createAccount(login, password))
		{
			return 0;
		}

		// �������� ����� 
		fclose(file);

		// �������� ����� � ������ ��������� ������
		file = fopen(".\\Authentication\\login.auth", "rb");

		// �������� ������
		delete[] login, password;
	}

	// ��������� ��������� � ����� � �����
	fseek(file, 0, SEEK_END);

	// ������ ����� 
	size_t* size = new size_t;

	*size = ftell(file);

	// ��������� ��������� � ����� �����
	fseek(file, 0, SEEK_SET);

	// �������� ������ ��� �����
	char* buffer = new char[*size];

	// ���������� ����� � �����
	fread(buffer, sizeof(char), *size, file);

	// �������� ����� 
	fclose(file);

	// ����� ������ ��� ������ � ������ �����: 40
	// login - 20 ��������; �������� ��� ����� - 18
	// password - 20 ��������; �������� ��� ����� - 18

	// ����������� � ��������� � ��������� ���� ��������

	// ���������� �������������
	count_acc = new int;
	*count_acc = *size / 40;
	
	// �������� ������
	delete size;

	// ������ �������� �� ���������� �������������
	user = new account_data[*count_acc];

	// ��������� �� �����
	char* buf = buffer;


	// ���������� ���������
	for (account_data* us = user; us < user + *count_acc; us++, buf++)
	{
		// ����������� � ����������� ����� � ���������
		strncpy((*us).login, buf, 20);
		
		// ��������������� 
		decryption(*sec, (*us).login, 19);

		// �������� ��������� � ������
		buf += 19;

		// ����������� � ����������� ������ � ���������
		strncpy((*us).password, buf, 20);

		// ��������������� 
		decryption(*sec, (*us).password, 19);

		// �������� ��������� � ������
		buf += 20;
	}

	// �������� ������
	delete[] buffer;

	// ����� ��� �����
	char* log = new char[20];

	// ������ ��� �����
	char* password = new char[20];

	// ������� 
	size_t* i = new size_t;


	for (*i = 0; *i < 10; ++*i)
	{
		// ���� ������ 
		cout << "Enter login: ";
		cin.getline(log, 19);

		// ���� ������
		cout << "Enter password: ";
		cin.getline(password, 19);

		cout << endl;

		// ���������� ���� ���������� �����
		bool* detect = new bool;
		*detect = false;

		// ����� ������ � ������ � ���� ������� �������
		for (account_data* us = user; us < user + *count_acc; us++)
		{
			// ��������� ������ 
			if (!strcmp(log, (*us).login))
			{
				// ��������� ������
				if (!strcmp(password, (*us).password))
				{
					// ���� ������ �������
					*detect = true;

					// ���� ��� �����
					if (!strcmp(log, "admin"))
					{
						admin = true;
					}

					// �������� ������
					delete[] path, user;

					return 1;
				}
			}
		}

		// ���� ������ �� �������
		cout << "\n\n\n\n\nIncorrect login or password!" << endl;

		cout << "\n\n\nPRESS [ENTER] TO RE-LOGIN OR PRESS [ESC] TO EXIT" << endl;

		// ���������� ������� 
		char* n = new char;

		// ������ esc 
		char* esc = new char;
		*esc = (char)27;

		// ���� ������ ��� ��� ����� ������ "Enter", ���� ����� "Esc"
		while (true)
		{
			*n = _getch();

			if (strcmp(n, "\n"))
			{
				system("cls");

				line();

				break;
			}



			if (strcmp(n, esc))
			{
				system("cls");

				return 0;
			}
		}
	}
	
	system("cls");

	// ���� ������ �� ������� ������ ��� 
	return 2;
}
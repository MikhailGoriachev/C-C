#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

#include "head.h"
#include "struct.h"

using namespace std;

extern cypher* sec;
extern bool admin;

// ���������� ���������; 


// ��������� ����� � ������; ����������: 0 - ������������ ������� �������; 1 - ����� �����;
int createAccount()
{
	int* n = new int;

	while (true)
	{
		cout << "-----------------------------------------------" << endl << endl;

		cout << "-----------------Create Account----------------" << endl << endl;

		// ����� 
		char* login = new char[20];

		// ���� ������ 
		cout << "Enter login: ";
		cin.getline(login, 18);

		cout << endl;

		// ������ 
		char* password = new char[20];

		// ���� ������
		cout << "Enter password: ";
		cin.getline(password, 18);

		cout << endl;

		// ����� ������� ����� �����������
		*n = createAccount(login, password);

		// ���� ����� �� ��������
		if (*n == 3)
		{
			cout << "LOGIN IS NOT UNIQUE!" << endl;
			
			// �������� �������
			system("cls");
			continue;
		}

		// ���� �� ������� ������� ���� ������� ������ �������������
		if (*n == 0)
		{
			return 0;
		}

		cout << "\n\n\n\n\nSUCCESSFULLY REGISTRATION!" << endl;
		
		// �������� ������� ����� �������
		cout << "\n\n\nPRESS ANT KEY TO CONTINUE" << endl;

		// ������� ����� �������
		_getch();

		break;
	}

	// �������� �������
	system("cls");

	return 1;
}


// ����� �����������
int createAccount(char* login, char* password)
{
	// �������� ����� ���� ������ ������������� � ������ ��������� ����������
	FILE* file = fopen(".\\Authentication\\login.auth", "ab+");

	// ���� ���� ����� ���������
	if (file == nullptr)
	{
		cout << "ERROR OPEN FILE \"login.auth\"" << endl;

		return 0;
	}

	// �������� ������ �� ���� ������
	// ������ ����� 
	size_t* size = new size_t;

	*size = ftell(file);

	// ��������� ��������� � ����� �����
	fseek(file, 0, SEEK_SET);

	// �������� ������ ��� �����
	char* buffer = new char[*size];

	// ���������� ����� � �����
	fread(buffer, sizeof(char), *size, file);

	// ����� ������ ��� ������ � ������ �����: 40
	// login - 20 ��������; �������� ��� ����� - 18
	// password - 20 ��������; �������� ��� ����� - 18

	// ����������� � ��������� � ��������� ���� ��������

	// ���������� �������������
	int* count_acc = new int;

	*count_acc = *size / 40;

	// �������� ������
	delete size;

	// ������ �������� �� ���������� �������������
	account_data* user = new account_data[*count_acc];

	// ��������� �� �����
	char* buf = buffer;


	// ���������� ���������
	for (account_data* us = user; us < user + *count_acc; us++)
	{
		// ����������� � ����������� ����� � ���������
		strncpy((*us).login, buf, 19);

		// ��������������� 
		decryption(*sec, (*us).login, 20);

		// �������� ��������� � ������
		buf += 20;

		// ����������� � ����������� ������ � ���������
		strncpy((*us).login, buf, 19);

		// �������� ��������� � ������
		buf += 20;
	}

	// �������� ������
	delete[] buffer;

	// ���������� ���� ��� ����� ��������
	bool* detect = new bool;
	*detect = false;

	// ����� ������ � ������ � ���� ������� �������
	for (account_data* us = user; us < user + *count_acc; us++)
	{
		// ��������� ������ 
		if (!strcmp(login, (*us).login))
		{
			// ���� ������ �������
			*detect = true;

			// �������� ������
			delete[] user;
			delete count_acc;

		}
	}

	// ���� ���� ����������
	if (*detect)
	{
		// �������� �����
		fclose(file);

		return 3;
	}

	// ���������� ������ 
	encryption(*sec, login, 20);
	encryption(*sec, password, 20);

	// ����� 
	char* buff = new char[41];

	// ���������� ������
	for (char* i = login, * k = password, * b = buff; i < login + 19; i++, k++, b++)
	{
		*b = *i;
		*(b + 19) = *k;
	}

	// ������ � ����� ����� �� ������
	fwrite(buff, sizeof(char), 40, file);

	// �������� �����
	fclose(file);

	return 1;
}
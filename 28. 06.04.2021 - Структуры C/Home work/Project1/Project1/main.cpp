#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>
#include <direct.h>

#include "head.h"
#include "struct.h"
using namespace std;

// ��������� �������
cypher* sec = new cypher;

void main()
{
	// 1. ����������� ��������� - ���� ������ �� �����������. � ������ ������ ����� ������� ��������� ����������:
	//  - ����� ������(�� - 2345� ��� 1)
	//	- ����� ������(BMW)
	//	- ������(m5)
	//	- ��� ���������
	//	- ��� �������
	//	- ����
	//
	//	��������� ����� ��������� ������� :
	//  - ������ ������� � ������������ ������� ��������
	//	- ���������������� ����
	//	- ���������� �����������
	//	- �������� ����������
	//	- �������� ���� �����������
	//	- �������������� ����������
	//	- ����� �� ����
	//	- ���� / ���� � ���� ���� ������
	//	- ����� �� ���������

	// �������������� ���� ������ ����� ����� ����������� ����� ������ ���,
	// �� ���� ���� � ���������� ���� ������ ����� ��������� ����� ������������
	// ����������(7 ���)

	line();

	cout << "CAR DATABASE 1.0" << endl;



	strcpy((*sec).cyp, "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890");
	strcpy((*sec).decyp, "qazwsxedcrfvtgbyhnujmikolpQAZWSXEDCRFVTGBYHNUJMIKOLP!@#$%^&*()");

	// �������������� ���� ������ ����� ����� ����������� ����� ������ ���,
	// �� ���� ���� � ���������� ���� ������ ����� �����

	int* n = new int;

	// ����� �������
	*n = login();

	// ���� ���� �� ��������
	if (*n == 0)
	{
		cout << "Exit" << endl;
		return;
	}

	// ������ ��� ����� ����� ������ ��� �������
	if (*n == 2)
	{
		// �������� ����� ���� ������
		deleteFile(".\\Database\\save.base");

		return;
	}

	// ���� ���� �������� �������

	// ���� ����� ���� ������ �� ���������
	char* path_data = new char[_MAX_PATH];

	// ���� � ����� ���� ������ �� ���������
	strcpy(path_data, ".\\Database\\save.base");

	// ��������� �� ���� ���� ������
	FILE* database = nullptr;

	// ������������ ��������: ������� ���� ������ �� ��������� ��� 
	// ������ ���� � ����� 
	cout << "Load new database? (Y/N): ";

	// ���������� ����� ������ �������
	char* key = new char[2];

	*(key + 1) = 0;

	// �������� ����� 
	while (true)
	{
		// ���� �������
		*key = _getch();

		if (!strcmp(key, "Y") || !strcmp(key, "y"))
		{
			// �������� �������
			system("cls");

			// ����� ������
			line();

			cout << "----------------LOADING DATABASE---------------" << endl << endl;

			// ���� ���� � ����� ���� ������
			cout << "Enter path database: ";
			cin.getline(path_data, _MAX_PATH);

			cout << endl;

			// �������� ����� ���� ������ � ������ ��������� ������
			database = fopen(path_data, "rb");

			// ���� ���� ������ �������
			if (database != nullptr)
			{
				cout << "File uploaded complite!" << endl;

				// ������� ����� ������� ��� �����������
				pressAnyKey();

				// �������� �������
				system("cls");

				break;
			}
		}

		if (!strcmp(key, "N") || !strcmp(key, "n"))
		{
			break;
		}
	}

	// �������� �������
	system("cls");

	// ����� ������
	line();

	// ��������� �� ������ ��������
	car_t* car = nullptr;

	// ���������� ����� � ����
	unsigned int* count_car = nullptr;

	// �������� ���� ������
	loadData(path_data);


}
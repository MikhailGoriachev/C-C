#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>
#include <direct.h>

using namespace std;

// ��������� 

// ��������� ����� � ������
//	.\Library\
//	.\Library\list.data
//	.\Library\Books\
//	.\Library\Books\[numberBook]
//	.\Users
//  .\Users\user.data
//	.\Security
//	.\Security\key.data
//	
//

void line()
{
	cout << "\n--------------------------------------------------------------\n\n";
}

void pressAnyKey()
{
	cout << "\n\n\n\nPRESS ANY KEY TO CONTINUE" << endl;

	_getch();
}


// ��������� �������
void randomCymb(char* str, size_t size)
{


	char* a = new char[53];

	strcpy(a, "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm");

	// ���������� ������ ���������� ��������
	for (char* s = str; s < str + size; s++)
	{
		*s = a[rand() % 53];
	}
}

// ������������� ������
void mixStr(char* str, size_t size)
{
	srand(time(0));

	for (char* s = str; s < str + size; s++)
	{
		swap(s[rand() % size], s[rand() % size]);
	}
}

// ����������
void Crypt(char* str, unsigned long size, char* a, char* b)
{

	for (char* str_p = str; str_p < str + size; str_p++)
	{
		for (char* key_a = a, *key_b = b; key_a < a + 52; key_a++, key_b++)
		{
			if (*key_b == *str_p)
			{
				*str_p = *key_a;

				break;
			}
		}
	}
}


void main()
{
	srand(time(0));

	line();

	cout << "LIBRARY 1.1 INSTALLER" << endl;

	line();

	// ��������� �� ����
	FILE* file = nullptr;

	// ���� ��������� 
	char* pathInstall = new char[_MAX_PATH];

	// ��������� � ������� ����� ��� ���� ���� ��� ���������
	cout << "Install in the current folder or enter the installation path? (Y/N): ";
	
	// ������ 
	char* c = new char;

	// ��������� �� ������ ����� ����������
	char* nameDir;
		
	// ���� ����������
	char* a = new char[251];

	// ���������� ���������� ���������
	randomCymb(a, 250);

	strcpy(a, "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm");

	// ������������� ������
	mixStr(a, 51);

	// ���� ����������
	char* b = new char[251];

	// ���������� ���������� ���������
	randomCymb(b, 250);

	strcpy(b, "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm");

	// ������������� ������
	mixStr(b, 51);


	// ���� 
	while (true)
	{
		*c = _getch();

		// 'Y' ��������� �� �������� ����
		if (*c == 'Y' || *c == 'y')
		{
			strcpy(pathInstall, ".\\");

			// ��������� �� ������ ����� ����������
			nameDir = &pathInstall[strlen(pathInstall)];

			break;
		}

		// 'N' ���� ���� ��� ���������
		if (*c == 'N' || *c == 'n')
		{
			system("cls");

			// ���� ���� 
			line();

			cout << "LIBRARY 1.1 INSTALLER" << endl;

			line();

			// ���� ���� 
			cout << "Enter path install: ";
			cin.getline(pathInstall, _MAX_PATH);

			strcat(pathInstall, "\\");

			// ��������� �� ������ ����� ����������
			nameDir = &pathInstall[strlen(pathInstall)];

			break;
		}
	}

	line();

	cout << "LIBRARY 1.1 INSTALLER" << endl;

	line();
	
	// .\Library

	strcpy(nameDir, "Library");

	cout << "> Library" << endl;

	// ���� ������
	if (_mkdir(pathInstall) != -1)
	{
		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}


	// .\Library\list.data

	strcpy(nameDir, "Library\\list.data");

	cout << "> Library\\list.data" << endl;

	file = fopen(nameDir, "w");

	// ���� ������
	if (file != nullptr)
	{
		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}


	// .\Library\Books

	strcpy(nameDir, "Library\\Books");

	cout << "> Library" << endl;

	// ���� ������
	if (_mkdir(pathInstall) != -1)
	{
		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}

	//	.\Users
	strcpy(nameDir, "Users");

	cout << "> Users" << endl;

	// ���� ������
	if (_mkdir(pathInstall) != -1)
	{
		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}

	//  .\Users\user.data

	strcpy(nameDir, "Users\\user.data");

	cout << "> Users\\user.data" << endl;

	file = fopen(nameDir, "wb");

	// ���� ������
	if (file != nullptr)
	{
		// �������� ������ � ������ �������������� �� ���������
		
		// �����
		char* buffer = new char[20];

		// ���������� ������ ���������� ���������
		randomCymb(buffer, 20);

		// ���������� ������
		strcpy(buffer, "admin");

		// ���������� ������
		Crypt(buffer, strlen(buffer), a, b);

		// ������ � ����
		fwrite(buffer, sizeof(char), 20, file);

		// ���������� ������ ���������� ���������
		randomCymb(buffer, 20);

		// ���������� ������
		strcpy(buffer, "123456");

		// ���������� ������
		Crypt(buffer, strlen(buffer), a, b);

		// ������ � ����
		fwrite(buffer, sizeof(char), 20, file);

		// ���������� ������ ���������� ���������
		randomCymb(buffer, 20);

		// ���������� ������
		strcpy(buffer, "Goriachev");

		// ���������� ������
		Crypt(buffer, strlen(buffer), a, b);

		// ������ � ����
		fwrite(buffer, sizeof(char), 20, file);

		// ���������� ������ ���������� ���������
		randomCymb(buffer, 20);

		// ���������� ������
		strcpy(buffer, "Mikhail");

		// ���������� ������
		Crypt(buffer, strlen(buffer), a, b);

		// ������ � ����
		fwrite(buffer, sizeof(char), 20, file);

		int n = 1;

		// ������ � ����
		fwrite(&n, sizeof(int), 1, file);

		// �������� �����
		fclose(file);

		delete[] buffer;

		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}

	//	.\Security
	strcpy(nameDir, "Security");

	cout << "> Security" << endl;

	// ���� ������
	if (_mkdir(pathInstall) != -1)
	{
		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}

	//	.\Security\key.data

	strcpy(nameDir, "Security\\key.data");

	cout << "> Security\\key.data" << endl;

	file = fopen(nameDir, "wb");

	// ���� ������
	if (file != nullptr)
	{
		// �������� ������ � ������ �������������� �� ���������

		// ������ � ����
		fwrite(a, sizeof(char), 250, file);

		// ������ � ����
		fwrite(b, sizeof(char), 250, file);

		// �������� �����
		fclose(file);

		cout << "     SAVE" << endl;
	}
	else
	{
		cout << "     ERROR CREATE" << endl;

		pressAnyKey();

		return;
	}

	cout << "INSTALL COMPLETE" << endl;

	delete[] a, b, nameDir;
	delete c;
}
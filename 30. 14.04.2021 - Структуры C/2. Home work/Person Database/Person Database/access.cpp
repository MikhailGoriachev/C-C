#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;


// �������� ����� ./Person Database 1.0/Security/access.list - ������� ������
bool LoadingAccess(account_t** users, int* countUsers, key_t* key)
{
	// �������� ����� access.list � ������ ��������� ������
	FILE* file = fopen("./Security/access.list", "rb");

	// ���� ���� ������ �������
	if (file != nullptr)
	{
		// ���������� ���� ������ ������ ������������ 
		int* sizeUser = new int;

		*sizeUser = 41;

		// ��������� ��������� � ����� �����
		fseek(file, 0, SEEK_END);

		// ����� �����
		size_t* sizeFile = new size_t;

		*sizeFile = ftell(file);

		// ���������� �������������
		*countUsers = *sizeFile / *sizeUser;

		// ��������� ��������� � ������ �����
		fseek(file, 0, SEEK_SET);

		// ���� ����� ����� ��� ������� ������� �� ���������� �������������
		if (*sizeFile % *countUsers == 0)
		{
			// ������ �������� ������ �������������
			*users = new account_t[*countUsers];

			// ���������� ����� � ��������
			for (account_t* user = *users; user < *users + *countUsers; user++)
			{
				fread(user, sizeof(char), *sizeUser, file);

				// ������������ ������ 
				CryptOrDecrypt(user->login, 20, key, 2, 63);
				
				// ������������ ������
				CryptOrDecrypt(user->password, 20, key, 2, 63);

				// ������������ ������ �������
				CryptOrDecrypt(user->accessLevel, 1, key, 2, 63);
			}

			// �������� �����
			fclose(file);

			// �������� ������
			delete sizeUser, sizeFile;

			return true;
		}
		
		cout << "ERROR! BROKEN FILE \"access.list\"";

		// �������� ������
		delete sizeUser, sizeFile;

		return false;		
	}
	cout << "ERROR OPENING FILE \"access.list\"" << endl;

	pressAnyKey();

	return false;
}

// ���� � ������� ������; 
bool Login(account_t** users, int* countUsers, key_t* key, bool* adminFlag)
{
	system("cls");

	outLine();

	cout << "LOGIN" << endl;

	outLine();

	// �������� ������� ������ ������������� �� ����� access.list
	if (!LoadingAccess(users, countUsers, key))
	{
		return false;
	}

	// �����
	char* login = new char[20];

	// ������
	char* password = new char[20];

	// ���� ������ � ������
	while (true)
	{
		system("cls");

		outLine();

		cout << "LOGIN" << endl;

		outLine();

		// ���� ������ 
		cout << "Login: ";
		cin.getline(login, 20);

		// ���� ������
		cout << "Password: "; 
		cin.getline(password, 20);

		// �������� ������ � ������ �� ���� ������� �������
		for (account_t* user = *users; user < *users + *countUsers; user++)
		{
			// ���� ����� ���������
			if (!strcmp(user->login, login))
			{
				// ���� ������ ���������
				if (!strcmp(user->password, password))
				{
					// ���� ������������ ����������� � ������ �������������
					if (user->accessLevel[0] == 'a')
						*adminFlag = true;

					return true;
				}
			}
		}

		// ���� ������ ������� �����������
		cout << "\nINCORRECT LOGIN OR PASSWORD" << endl;

		pressAnyKey();
	}
}

// 5. ACCOUNT MANAGEMENT (ADMIN GROUP)
int AccontManagement(account_t** users, int* countUsers, key_t* key, int* sizeKey)
{
	// ���� ���� ������ ������
	if (*countUsers == 0)
	{
		system("cls");

		outLine();

		cout << "ACCOUNT MANAGEMENT" << endl;

		outLine();

		cout << "THE DATABASE IS EMPTY" << endl;

		pressAnyKey();

		return 0;
	}

	char* c = new char;

	int* n = new int;

	*n = 1;

	for (account_t* user = *users;; )
	{
		system("cls");

		outLine();

		cout << "ACCOUNT MANAGEMENT" << endl;

		outLine();

		// ������� ������������/����� �������������
		cout << "			" << *n << "/" << *countUsers << endl;

		// �����
		cout << "Login: " << user->login << endl;

		// ������
		cout << "Password: " << user->password << endl;

		// ������� �������
		cout << "Access level: ";

		// ����� 
		if (user->accessLevel[0] == 'a')
		{
			cout << "Admin group" << endl;
		}
		else cout << "User group" << endl;

		// ���� ������� ������� admin
		if (!strcmp(user->login, "admin"))
			cout << "\n\n\n\n\nPRESS: LAST[1] NEXT[2] QUIT[ESC] NEW USER[N]" << endl;
		else
			cout << "\n\n\n\n\nPRESS: LAST[1] NEXT[2] QUIT[ESC] DELETE[D] NEW USER[N]" << endl;

		// ���� 
		while (true)
		{
			*c = _getch();

			// LAST[1]
			if (*c == '1')
			{
				// ���� ��� ������ ������
				if (user == *users)
				{
					break;
				}

				user--;

				--* n;
				break;
			}

			// NEXT[2]
			if (*c == '2')
			{
				// ���� ��� ��������� ������
				if (user == *users + *countUsers - 1)
				{
					break;
				}

				user++;

				++* n;
				break;
			}

			// QUIT[ESC]
			if (*c == (char)27)
			{
				delete n, c;

				return 0;
			}

			// DELETE[D]
			if (*c == 'D' || *c == 'd' && strcmp(user->login, "admin"))
			{
				DeleteUser(*user, 41, key, sizeKey);
				
				return 1;
			}

			// NEW USER[N]
			if (*c == 'n' || *c == 'N')
			{
				if (CreateUser(users, countUsers, key, sizeKey))
				{
					return 1;
				}
			}
		}
	}
}

// �������� ������������; 0 - ������������ �� ������, 1 - ������������ ������;
int CreateUser(account_t** users, int* countUsers, key_t* key, int* sizeKey)
{
	// ������ ������ ������������
	account_t* newUser = new account_t;

	// ���������� ����� ��������� ���������� ���������
	GenerationRandomCymbols((char*)newUser, sizeof(account_t));

	// ������ �����
	char* c = new char;

	// ���� ������ �� �����
	bool* flag = new bool;

	*flag = false;

	while (true)
	{
		system("cls");

		outLine();

		cout << "NEW USER" << endl;

		outLine();

		// ���� �����
		cout << "Login: ";
		cin.getline(newUser->login, 20);

		// �������� ���� ������ �� ���������� ������
		for (account_t* user = *users; user < *users + *countUsers; user++)
		{
			// ���� ����� ������
			if (!strcmp(newUser->login, user->login))
			{
				cout << "LOGIN IS ALREADY REGISTERED!" << endl;

				cout << "PRESS: RE-ENTER[R] QUIT[ESC]" << endl;

				// ���� 
				while (true)
				{
					*c = _getch();

					// RE-ENTER[R]
					if (*c == 'r' || *c == 'R')
					{
						*flag = true;
						break;
					}

					// QUIT[ESC]
					if (*c == 27)
					{
						delete flag, c, newUser;

						return 0;
					}
				}

				if (*flag)
				{
					break;
				}
			}
		}

		if (*flag)
		{
			*flag = false;
			continue;
		}

		// ���� ������
		cout << "Password: ";
		cin.getline(newUser->password, 20);

		// ������� �������
		cout << "Access level((A)dmin group/(U)ser group): ";

		// ���� 
		while (true)
		{
			*c = _getch();

			// admin group 
			if (*c == 'a' || *c == 'A')
			{
				newUser->accessLevel[0] = 'a';

				cout << "A" << endl;

				break;
			}

			// user group
			if (*c == 'u' || *c == 'U')
			{
				newUser->accessLevel[0] = 'u';

				cout << "U" << endl;

				break;
			}
		}

		cout << "PRESS: SAVE[ENTER] CANCEL[ESC]" << endl;

		// ���� 
		while (true)
		{
			*c = _getch();

			// SAVE[ENTER]
			if (*c == 13)
			{
				// �������� ����� ������� ������� � ������ ��������� ������/������
				FILE* file = fopen("./Security/access.list", "rb+");

				// ��������� ��������� � ����� �����
				fseek(file, 0, SEEK_END);

				// ���������� ������
				CryptOrDecrypt((char*)newUser, sizeof(account_t), key, 1, *sizeKey);

				// ������ � ����� ����� �� ��������� 
				fwrite(newUser, sizeof(account_t), 1, file);

				// �������� �����
				fclose(file);

				cout << "SAVE" << endl;

				pressAnyKey();

				delete c, newUser, flag;

				return 1;
			}

			// CANCEL[ESC]
			if (*c == 27)
			{
				delete c, newUser, flag;

				return 0;
			}
		}
	}
	
}

// �������� ������������
void DeleteUser(account_t user, int sizeUser, key_t* key, int* sizeKey)
{
	account_t* us = &user;

	// ���������� ������ ������������
	CryptOrDecrypt((char*)us, sizeUser, key, 1, *sizeKey);

	// �������� ����� ������� ������� � ������ ��������� ������/������
	FILE* file = fopen("./Security/access.list", "rb");

	// ��������� ��������� � ����� �����
	fseek(file, 0, SEEK_END);

	// ����� �����
	size_t* sizeFile = new size_t;

	*sizeFile = ftell(file);

	// ��������� ��������� � ������ �����
	fseek(file, 0, SEEK_SET);

	// ����� ��� �����
	char* buffer = new char[*sizeFile];
	
	// ���������� ����� � �����
	fread(buffer, sizeof(char), *sizeFile, file);

	// �������� ����� 
	fclose(file);

	// ����� ������ ������������ � �����
	for (char* buf = buffer; buf < buffer + *sizeFile; buf++)
	{
		// ���� ������ �������
		if (!strncmp(buf, (char*)us, sizeUser))
		{
			// ������� ��������
			int* i = new int;

			*i = 0;

			// �������� ��������� ������ �����
			for (; *i < sizeUser; ++*i)
			{
				for (char* b = buf; b < buffer + *sizeFile - 1; b++)
				{
					swap(*b, *(b + 1));
				}
			}

			delete i;

			// ���������� ����� �����
			*sizeFile -= sizeUser;

			// �������� ����� � ������ �������� ������
			file = fopen("./Security/access.list", "wb");

			// ������ � ����
			fwrite(buffer, sizeof(char), *sizeFile, file);

			// �������� ����� 
			fclose(file);

			delete sizeFile;
			delete[] buffer;

			return;
		}
	}
}
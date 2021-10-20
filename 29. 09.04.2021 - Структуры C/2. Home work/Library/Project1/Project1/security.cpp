#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

#include "head.h"

using namespace std;

// ���� � �������; mode == 0 - ���� � �������, mode == 1 - ���������� ��������������, mode == 2 - �����;
UserData* login(int* mode)
{
	// ��������� �� ���� ����������
	CryptKey** key = new CryptKey*;

	// ���������� �������������
	int* count_users = new int;

	/// �������� ������� ������ ������������
	UserData* users = loadingUserData(count_users, key);

	// ���� ������ �� ���������� ���������
	if (users == nullptr)
		return nullptr;

	// ���� ����� �������� ������ (�������������)
	if (*mode == 1)
	{
		char* c = new char;

		for (UserData* user = users;; )
		{
			outline();

			// ����� ������ ������������
			cout << "USERS LIST" << endl;

			outline();

			// ����� ������������
			cout << "Count all users: " << *count_users << endl;

			// �������
			cout << "Surname: " << (*user).surname << endl;
			// ��� 
			cout << "Name: " << (*user).name << endl;
			// �����
			cout << "Login: " << (*user).login << endl;
			// ������
			cout << "Password: " << (*user).password << endl;
			// ������� �������
			cout << "Acces level: ";
			// ���� ������� ������� �����������������
			if ((*user).accessLevel == 1)
				cout << "admin group" << endl;
			else cout << "prime user" << endl;

			// ���������� 
			cout << "\n\n\nPRESS: LAST[1] NEXT[2] NEW USER[4] DELETE[3] QUIT[ESC]" << endl;

			// ���� 
			while (true)
			{
				*c = _getch();

				// LAST[1]
				if (!strcmp(c, "1"))
				{
					// ���� ������ �������� ������
					if (user == users + *count_users - 1)
					{
						continue;
					}

					user++;

					break;
				}

				// NEXT[2]
				if (!strcmp(c, "2"))
				{
					// ���� ���������
					if (user == users)
					{
						continue;
					}

					user--;

					break;
				}

				// �������� ������ ������������
				if (!strcmp(c, "3"))
				{
					createUser(users, count_users, key);

					delete c, count_users;

					delete[] users;

					return nullptr;
				}

				// �������� ������������
				if (!strcmp(c, "4"))
				{
					deleteToFile((*user).login, "Users\\user.data", 84);

					cout << "DELETE USER COMPLETE!" << endl;

					delete c, count_users;

					delete[] users;

					return nullptr;
				}

				// ����� �� ���������� ����������
				if (*c == (char)27)
				{
					// ������������ ������ �� �����
					*mode = 2;

					delete c, count_users;

					delete[] users;

					return nullptr;
				}
			}
		}
	}

	// �����
	char* login = new char[20];

	// ������
	char* password = new char[20];

	// ���� ������� ������
	while (true)
	{
		system("cls");

		outline();

		cout << "LOGIN" << endl;

		outline();

		// ���� ������ 
		cout << "Enter login: ";
		cin.getline(login, 20);

		// ���� ������
		cout << "Enter password: ";
		cin.getline(password, 20);

		// �������� �� ���� ������
		for (UserData* user = users; user < users + *count_users; user++)
		{
			// ���� �������� ����� ��������� � ������� � ���� ������
			if (!strcmp((*user).login, login))
			{
				// ���� �������� ������ ��������� � ������� � ���� ������
				if (!strcmp((*user).login, login))
				{
					// �������� UserData ��� �������� ������������
					UserData* us = new UserData;

					// ����������� ������ ����� �������� ������������ �� ���� ������ �������������
					// � ��������� UserData �� ������ ������������
					// �����
					strcpy((*us).login, (*user).login);
					strcpy((*us).password, (*user).password);
					strcpy((*us).surname, (*user).surname);
					strcpy((*us).name, (*user).name);
					(*us).accessLevel = (*user).accessLevel;

					// �������� ������
					delete[] users, login, password;

					// ������������ ������ �� �����
					*mode = 2;

					// ����������� ������ �������� ������������ � ������� �������
					return us;
				}
			}
		}

		cout << endl;

		cout << "USERNAME OR PASSWORD ENTERED INCORRECTLY! RE-ENTER!" << endl;

		// ������� ����� �������
		pressAnyKey();
	}
}

// �������� ����� ����������
CryptKey* loadingKey()
{
	// �������� ��������� ����������
	CryptKey *key = new CryptKey;

	/// ���������� ����� �� ����� � ����� Security/sec.data

	// �������� ����� ����� ������������ � ������ ��������� ������
	FILE* file = fopen("Security\\key.data", "rb");

	// ���� ���� ������ �������
	if (file != nullptr)
	{
		// ��������� ��������� � ����� ����� 
		fseek(file, 0, SEEK_END);

		// ����� ����� 
		int* size_key = new int;

		*size_key = ftell(file);

		// ��������� ��������� � ����� �����
		fseek(file, 0, SEEK_END);

		// ����������� �������� ����� � ��������� � ������ "a"
		fread((*key).a, sizeof(char), *size_key / 2, file);

		// ����������� �������� ����� � ��������� � ������ "b"
		fread((*key).b, sizeof(char), *size_key / 2, file);

		// �������� �����
		fclose(file);

		return key;
	}
	// ���� ���� ������������ �� ������� �������
	else
	{
		cout << "ERROR OPENING FILE \"key.data\"!" << endl;

		// ������� ������
		delete key;

		pressAnyKey();

		return nullptr;
	}
}

// �������� ������� ������ �������������
UserData* loadingUserData(int* count_users, CryptKey** key)
{
	// �������� ����� ����������
	*key = loadingKey();

	// ���� ���� �������� ������
	if (key != nullptr)
	{
		// �������� ����� Users/users.data � ������ ��������� ������
		FILE* file = fopen("Users\\user.data", "rb");

		// ���� ���� ������� ������
		if (file != nullptr)
		{
			// ��������� ��������� � ����� �����
			fseek(file, 0, SEEK_END);

			// ����� �����
			size_t* size = new size_t;

			*size = ftell(file);

			// ��������� ��������� � ������ �����
			fseek(file, 0, SEEK_SET);

			// ���������� �������������
			*count_users = *size / 84;

			// ������ �������������
			UserData* users = new UserData[*count_users];

			// ���������� ����� � ���������
			for (UserData* us = users; us < users + *count_users; us++)
			{
				// ����� 
				fread((*us).login, sizeof(char), 20, file);

				// �����������
				deCrypt((*us).login, 20);

				// ������ 
				fread((*us).password, sizeof(char), 20, file);

				// �����������
				deCrypt((*us).password, 20);
				
				// ������� ������������
				fread((*us).surname, sizeof(char), 20, file);

				// �����������
				deCrypt((*us).surname, 20);

				// ��� ������������
				fread((*us).name, sizeof(char), 20, file);

				// �����������
				deCrypt((*us).name, 20);

				// ������� �������
				fread(&(*us).accessLevel, sizeof(int), 1, file);
			}

			// �������� �����
			fclose(file);

			// �������� ������
			delete size;

			return users;
		}

		cout << "ERROR OPENING FILE \"user.data\"" << endl;

		pressAnyKey();

		// ���� ��������
		return nullptr;
	}

	// ���� ��������
	return nullptr;
}

// ������������ �����������
void deCrypt(char* str, unsigned long size)
{
	// �������� ����� ����������
	CryptKey* key = loadingKey();

	for (char* str_p = str; str_p < str + size; str_p++)
	{
		for (char* key_a = (*key).a, * key_b = (*key).b; key_a < (*key).a + 255; key_a++, key_b++)
		{
			if (*key_a == *str_p)
			{
				*str_p = *key_b;

				break;
			}
		}
	}
}

// ���������� �����������
void Crypt(char* str, unsigned long size)
{
	// �������� ����� ����������
	CryptKey* key = loadingKey();

	for (char* str_p = str; str_p < str + size; str_p++)
	{
		for (char* key_a = (*key).a, *key_b = (*key).b; key_a < (*key).a + 255; key_a++, key_b++)
		{
			if (*key_b == *str_p)
			{
				*str_p = *key_a;

				break;
			}
		}
	}
}

// ����������� � ����
int writingToFile(void* buffer, const char nameFile[], unsigned int countByte)
{
	// �������� ����� � ������ ��������� ������/������
	FILE* file = fopen(nameFile, "rb+");

	// ���� ���� ������ ������
	if (file != nullptr)
	{
		// ��������� ��������� � ����� �����
		fseek(file, 0, SEEK_END);

		// ������ � ����
		fwrite(buffer, 1, countByte, file);

		// �������� ����� 
		fclose(file);

		return 1;
	}

	// ���� ���� ������ ��������
	else return 0;
}

// �������� �� �����
int deleteToFile(char* buffer, const char nameFile[], unsigned int countByte)
{
	// �������� ����� � ������ ��������� ������/������
	FILE* file = fopen(nameFile, "rb+");

	// ���� ���� ������ ������
	if (file != nullptr)
	{
		// ��������� ��������� � ����� �����
		fseek(file, 0, SEEK_END);

		// ����� �����
		size_t* size = new size_t;

		*size = ftell(file);

		// ����� ��� �����
		char* buf = new char[*size];

		// ���������� ����� � �����
		fread(buf, sizeof(char), *size, file);

		// �������� �����
		fclose(file);

		// ������������ ������
		for (char* point_a = buf; point_a < buf + *size; point_a++)
		{
			if (!strncmp(point_a, buffer, countByte))
			{
				// �������� ������� �����
				for (char* a = point_a; a < point_a + *size; a++)
				{
					swap(*a, *(a + 1));
				}

				break;
			}
		}

		// ���������� ����� ����� 
		*size -= countByte;

		// �������� ����� � ������ ��������� ������
		FILE* file = fopen(nameFile, "wb");

		// ���������� ����� ���������� �� ������
		fwrite(buffer, sizeof(char), *size, file);

		// �������� ������
		delete[] buf;
		delete size;

		// �������� ����� 
		fclose(file);

		return 1;
	}

	// ���� ���� ������ ��������
	else return 0;

}

// �������� ������������
void createUser(UserData* users, int* count_user, CryptKey** key)
{
	// ���� ������������ ������
	bool* flag = new bool;

	*flag = false;

	while (true)
	{
		system("cls");

		outline();

		cout << "CREATE NEW USER" << endl;

		outline();

		// ��������� ��� ������ ������������
		UserData* newUser = new UserData;

		// �������
		cout << "Enter surname: ";
		cin.getline((*newUser).surname, 20);

		// ��� 
		cout << "Enter name: ";
		cin.getline((*newUser).name, 20);

		// �����
		cout << "Enter login: ";
		cin.getline((*newUser).login, 20);
		// ������
		cout << "Enter password: ";
		cin.getline((*newUser).password, 20);
		// ������� �������
		cout << "Enter acces level(admin[1]/user[0]): ";
		cin >> (*newUser).accessLevel;

		// �������� �� ������ � ���� ������� �������
		for (UserData* user = users; user < users + *count_user; user++)
		{
			// ���� ����� ������ � ���� ������
			if (!strcmp((*newUser).login, (*user).login))
			{
				cout << "LOGIN IS BUSSY! PLEASE, RE_ENTER DATA.\nPRESS ANY KEY TO RE-ENTER OR ESC TO EXIT" << endl;

				// ������
				char* c = new char;

				// ���� ������ esc
				if (*c == (char)27)
				{
					delete c;

					return;
				}

				*flag = true;

				break;
			}
		}

		if (!*flag)
		{
			// ���������� ������ 
			Crypt((*newUser).login, 20);

			// ������ � ���� ������ 
			writingToFile((*newUser).login, "Users\\user.data", 20);

			// ���������� ������
			Crypt((*newUser).password, 20);

			// ������ � ���� ������
			writingToFile((*newUser).password, "Users\\user.data", 20);
			
			// ���������� �������
			Crypt((*newUser).surname, 20);

			// ������ � ���� �������
			writingToFile((*newUser).surname, "Users\\user.data", 20);

			// ���������� ���������� �����
			Crypt((*newUser).name, 20);

			// ������ � ���� ����� 
			writingToFile((*newUser).name, "Users\\user.data", 20);

			// ������ � ���� ������ �������
			writingToFile(&(*newUser).accessLevel, "Users\\user.data", 4);

			cout << "CREATE NEW USER COMPLETE!" << endl;

			delete flag;

			pressAnyKey();

			return;
		}	
	}
}
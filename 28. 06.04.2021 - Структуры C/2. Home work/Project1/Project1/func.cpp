#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <io.h>
#include <direct.h>

#include "head.h"

using namespace std;

extern cypher* sec;
extern account_data* user;
extern int* count_acc;
extern bool admin;

// ������� ������� ��������� �������
void pressAnyKey()
{
	cout << "\n\n\nPRESS ANY KEY" << endl;

	_getch();
}

// ����� ������
void line()
{
	cout << "-----------------------------------------------" << endl << endl;
}

// ����
int menu(FILE* file)
{
	// �����
	line();

	// ���� 
	cout << "MENU" << endl;

	// �����
	line();

	// ����� ������ �����������
	cout << "> 1. Auto list" << endl;
	// ����� ���������� �� �������� 
	cout << "> 2. Search auto" << endl;
	// ����������� ����������
	cout << "> 3. Registration car" << endl;
	// �������� ���������� �� ���� ������ (�������� ������ � ������� ������ admin)
	cout << "> 4. Delete auto (admin)" << endl;
	// ����������� ������������ (�������� ������ � ������� ������ admin)
	cout << "> 5. Registration user (admin)" << endl;
	// ������ ������������� 
	cout << "> 6. User list (admin)" << endl;
	// ����� �� ���������
	cout << "\n\n\n> 0. Exit" << endl;

	// ������������ �������� ����� � ������������ � ������� ������ � ����
	cout << "\n\n\n\n\nPESS KEY [1-6]";

	// ��������� ��� ������ �������
	char* ch = new char[2];
	*(ch + 1) = 0;

	// ������� �������
	while (true)
	{
		// ������� �������
		*ch = _getch();

		if (!strcmp(ch, "0"))
		{
			// �������� �������
			system("cls");

			return 0;
		}

		if (!strcmp(ch, "1"))
		{
			// �������� �������
			system("cls");

			return 1;
		}

		else if (!strcmp(ch, "2"))
		{
			// �������� �������
			system("cls");

			return 2;
		}
		
		else if (!strcmp(ch, "3"))
		{
			// �������� �������
			system("cls");

			return 3;
		}
		
		else if (!strcmp(ch, "4"))
		{
			// �������� �������
			system("cls");

			return 4;
		}
		
		else if (!strcmp(ch, "5"))
		{
			// �������� �������
			system("cls");

			return 5;
		}
		
		else if (!strcmp(ch, "6"))
		{
			// �������� �������
			system("cls");

			return 6;
		}
	}

	// �������� �������
	system("cls");

	return 0;
}

// ������� ���������� � ���� ������ ������
int newAuto(FILE* file, car_t* database, unsigned long count_car)
{
	// �������� ��������� ��� ����� ������
	car_t* new_car = new car_t;

	// ��������� ��������� � ����� �����
	fseek(file, 0, SEEK_END);

	// ���������� ������������ ������
	bool* detect = new bool;

	*detect = true;

	// ���������� ��������� �������������
	while (true)
	{
		// �����
		line();

		cout << "REGISTRATION AUTO" << endl;

		line();

		// ����� ������
		cout << "Enter number auto: ";
		cin.getline((*new_car).number, 19);

		// ����� ������
		cout << "Enter mark auto: ";
		cin.getline((*new_car).mark, 19);

		// ������ 
		cout << "Enter model auto: ";
		cin.getline((*new_car).model, 19);

		// �������
		cout << "Enter owner`s surname: ";
		cin.getline((*new_car).surname, 19);

		// ��� 
		cout << "Enter owner`s name: ";
		cin.getline((*new_car).name, 19);

		// ��������
		cout << "Enter patronymic: ";
		cin.getline((*new_car).patronymic, 19);

		// ��� �������
		cout << "Enter year of crearion auto: ";
		cin.getline((*new_car).date, 10);

		// ���� 
		cout << "Enter price: ";
		cin >> (*new_car).price;

		// �������� ��������� �� ���������� ������
		for (car_t* base_car = database; base_car < database + count_car; base_car++)
		{
			// ���� ����� ���������
			if (!strcmp((*new_car).number, (*base_car).number))
			{
				cout << "AUTO NUMBER IS NOT UNIQUE! RE-ENTER THE DATA" << endl;

				*detect = false;

				cin.ignore();

				system("cls");

				break;
			}
		}

		// ���� ����� ��������
		if (*detect)
			break;
		
	}

	system("cls");

	cin.ignore();

	unsigned long df = 12;

	// ������ ������ � ����
	// ����� ������
	fwrite((*new_car).number, sizeof(char), 20, file);
	// �����
	fwrite((*new_car).mark, sizeof(char), 20, file);
	// ������
	fwrite((*new_car).model, sizeof(char), 20, file);
	// �������
	fwrite((*new_car).surname, sizeof(char), 20, file);
	// ���
	fwrite((*new_car).name, sizeof(char), 20, file);
	// ��������
	fwrite((*new_car).patronymic, sizeof(char), 20, file);
	// ��� �������
	fwrite((*new_car).date, sizeof(char), 10, file);
	// ����
	fwrite(&(*new_car).price, sizeof(long), 1, file);

	

	return 1;
}

// �������� ���� ������
void loadData(char* path_data)
{
	// ���������� �����
	unsigned int* count_car;

	// ��������� �� ���������
	car_t* car;

	// ��������� �� ����

	FILE* database;
	// �������� ���� ������ � ������ ��������� ������ + ������
	database = fopen(path_data, "rb+");

	// ���� ���� ������ ������� ���������
	if (database == nullptr)
	{
		cout << "DATABASE NOT FOUND" << endl;

		cout << endl;

		// �������� �� �� ���������� �� ����� "Database"

		// ������� 
		_finddata_t list;

		// �������� ������ ������ �������� �������� � ������ 
		long point = _findfirst(".\\Database", &list);

		// ���� ������ ������ �������� 
		if (point == -1)
		{
			// �������� ����� Databese
			if (_mkdir(".\\Database") == -1)
			{
				cout << "ERROR CREATE FOLDER \"Database\"" << endl;

				return;
			}
		}

		// �������� ������
		_findclose(point);

		// �������� ����� save.base � �������� ��� � ������ ������ ������
		database = fopen(path_data, "wb");

		// ���� ���� ������ ���������
		if (database == nullptr)
		{
			cout << "ERROR CREATE FILE \"save.base\"" << endl;

			return;
		}

		cout << "FILE CREATE COMPLITE!" << endl;

		// �������� �������
		system("cls");

		// ����� ����� 
		line();
	}

	// ��������� ��������� � ����� �����
	fseek(database, 0, SEEK_END);

	// ������ �����
	size_t* size = new size_t;

	*size = ftell(database);

	// ��������� ��������� � ������ �����
	fseek(database, 0, SEEK_SET);

	// �����
	/*char* n = new char[*size];

	// ���������� ����� ����� � ����� 
	fread(n, sizeof(char), *size, database);

	// ���������� ������
	decryption(*sec, n, *size);

	// ��������� ��������� � ������ �����
	fseek(database, 0, SEEK_SET);

	// ������ � ���� ��������������� ������
	fwrite(n, sizeof(char), *size, database);

	// ��������� ��������� � ������ �����
	fseek(database, 0, SEEK_SET);

	delete[] n;
	*/
	// � ������ ������ ����� ������� ��������� ���������� :
	//  - ����� ������(�� - 2345� ��� 1) - 20 ��������� - 20 ����
	//	- ����� ������(BMW) - 20 ��������� - 20 ����
	//	- ������(m5) - 20 ��������� - 20 ����
	//	- ��� ��������� - 60 ���������(20 - �������, 20 - ���, 20 - ��������) - 60 ����
	//	- ��� ������� - 10 ��������� - 10 ����
	//	- ���� - unsigned long - 4 ����� 
	// ����� ����: 134 �����

	// ���������� �����������
	count_car = new unsigned int;

	*count_car = *size / 134;

	// ���� ������ ������ �� ������� ��� ������� �� ����� ������ �� ����� ������
	if (*count_car != 0)
	{
		if (*size % *count_car != 0)
		{
			cout << "ERROR! THE DATABASE IS CORRUPTED" << endl;

			return;
		}
	}

	// �������� ������� �������� �� ���������� �����
	car = new car_t[*count_car];

	// ����������� ����� � ���������
	for (car_t* p_car = car; p_car < car + *count_car; p_car++)
	{
		// ����� ������
		fread((*p_car).number, sizeof(char), 20, database);
		// ����� ������
		fread((*p_car).mark, sizeof(char), 20, database);
		// ������
		fread((*p_car).model, sizeof(char), 20, database);
		// �������
		fread((*p_car).surname, sizeof(char), 20, database);
		// ��� 
		fread((*p_car).name, sizeof(char), 20, database);
		// ��������
		fread((*p_car).patronymic, sizeof(char), 20, database);
		// ��� �������
		fread((*p_car).date, sizeof(char), 10, database);
		// ����
		fread(&(*p_car).price, sizeof(unsigned long), 1, database);
	}

	cout << "FILE LOADING COMPLETE" << endl << endl;

	// ������� ����� ������� ��� �����������
	pressAnyKey();

	// �������� �������
	system("cls");

	// ���������� ���� 
	int* m = new int;

	*m = 0;

	// ������ ����
	while (true)
	{
		*m = menu(database);

		// ����� �� ���������
		if (*m == 0)
		{
			return;
		}

		// ����� ������ �����������
		if (*m == 1)
		{
			outList(car, count_car);
		}

		// ����� ���������� �� ������
		if (*m == 2)
		{
			searchAuto(car, count_car);
		}

		// ����������� ����������
		if (*m == 3)
		{
			// ������ ������� �����������
			newAuto(database, car, *count_car);

			// �������� �����
			fclose(database);

			// �������� ���� ������
			loadData(path_data);
		}

		// �������� ���������� �� ���� ������ (�������� ������ � ������� ������ admin)
		if (*m == 4)
		{
			
			// ���� �����
			if (admin)
			{
				// ������ �������
				deleteCar(database, car, count_car, path_data);
			}

			// ���� ������� ������������
			else
			{
				system("cls");

				// ����� �����
				line();

				cout << "Delete auto (admin)" << endl;

				// ����� �����
				line();


				cout << "LOCK! ADMIN REQUIRED" << endl;

				// ����� �������
				pressAnyKey();

				system("cls");

				continue;
			}
		}

		// ����������� ������������ (�������� ������ � ������� ������ admin)
		if (*m == 5)
		{
			
			// ���� �����
			if (admin)
			{
				// ������ �������
				regUser(user, count_acc);
			}

			// ���� ������� ������������
			else
			{
				system("cls");

				// ����� �����
				line();

				cout << "Delete auto (admin)" << endl;

				// ����� �����
				line();


				cout << "LOCK! ADMIN REQUIRED" << endl;

				// ����� �������
				pressAnyKey();

				system("cls");

				continue;
			}
		}

		// ������ ������������� (�������� ������ � ������� ������ admin)
		if (*m == 6)
		{
			// ���� �����
			if (admin)
			{
				// ������ �������
				listUser(user, count_acc);
			}

			// ���� ������� ������������
			else
			{
				system("cls");

				// ����� �����
				line();

				cout << "Delete auto (admin)" << endl;

				// ����� �����
				line();


				cout << "LOCK! ADMIN REQUIRED" << endl;

				// ����� �������
				pressAnyKey();

				system("cls");

				continue;
			}

		}
		
	}

	/*// ��������� ��������� � ����� �����
	fseek(database, 0, SEEK_END);

	// ������ �����
	size = new size_t;

	*size = ftell(database);

	// ��������� ��������� � ������ �����
	fseek(database, 0, SEEK_SET);

	// �����
	n = new char[*size];

	// ���������� ����� ����� � ����� 
	fread(n, sizeof(char), *size, database);

	// ���������� ������
	encryption(*sec, n, *size);

	// ��������� ��������� � ������ �����
	fseek(database, 0, SEEK_SET);

	// ������ � ���� ��������������� ������
	fwrite(n, sizeof(char), *size, database);

	// ��������� ��������� � ������ �����
	fseek(database, 0, SEEK_SET);

	fclose(database);

	delete[] n;*/
}

// ����� ������ �����������
void outList(car_t* car, unsigned int* count_car)
{
	// ���������� ��� �����
	int* i = new int;

	// ������ �������
	char* ch = new char[2];

	*(ch + 1) = 0;

	// ����� �� ��� ������ �� ��������
	for (car_t* car_p = car; car_p < car + *count_car; )
	{
		// ����� �����
		line();

		cout << "AUTO LIST" << endl << endl;

		line();

		// ����� ������
		cout << "> Number auto: " << (*car_p).number << endl;

		// ����� ������
		cout << "> Mark auto: " << (*car_p).mark << endl;

		// ������ 
		cout << "> Model auto: " << (*car_p).model << endl;

		// �������
		cout << "> Owner`s surname: " << (*car_p).surname << endl;

		// ��� 
		cout << "> Owner`s name: " << (*car_p).name << endl;

		// ��������
		cout << "> Patronymic: " << (*car_p).patronymic << endl;

		// ��� �������
		cout << "> Year of crearion auto: " << (*car_p).date << endl;

		// ���� 
		cout << "> Price: " << (*car_p).price << endl;

		cout << endl;

		cout << "\n\n\n\nPRESS: [1] - left, [2] - right, [ESC] - exit";

		// ������� �������
		*ch = _getch();
		
		// ���� ������������ �������� esc �� �����
		if ((int)*ch == 27)
		{
			// �������� �������
			system("cls");

			return;
		}

		// ���� ������������ �������� ������� �����, �� ���������� ������
		if (!strcmp(ch, "1"))
		{
			// ���� ��� �� ������ ������ 
			if (car_p != car)
			{
				car_p--;

				system("cls");

				continue;
			}
		}
		
		// ���� ������������ �������� ������� ������, �� ��������� ������
		if (!strcmp(ch, "2"))
		{
			// ���� ��� �� ��������� ������ 
			if (car_p < (car + *count_car - 1))
			{
				car_p++;

				system("cls");

				continue;
			}
		}

		system("cls");
	}
}

// �������� ������
void deleteCar(FILE* file, car_t* list, unsigned int* count_car, char* path)
{
	while (true)
	{
		// ����� �����
		line();

		cout << "Delete auto (admin)" << endl;

		// ����� �����
		line();

		// ������ ��� ������ 
		char* number = new char[19];

		// ���� ������ 
		cout << "Enter number car: ";
		cin.getline(number, 19);

		cout << endl;

		// ���������� �� ������������� ������ � ���� ������
		bool* flag = new bool;

		*flag = false;

		// ����� ������ �� ���� ������
		for (car_t* car = list; car < list + *count_car; car++)
		{
			// ���� ����� ������
			if (!strcmp(number, (*car).number))
			{
				*flag = true;

				size_t len = strlen(number);

				// ���������� ������ 
				//encryption(*sec, number, len);

				// ����� ����� ������ � ����� 
				if (scanFileDelete(number, len, 134, path))
				{
					loadData(path);

					return;
				}


				break;
			}
		}

		// ������ �����
		char* ch = new char[2];

		*(ch + 1) = 0;

		// ���� ������ �� ����������
		if (!(*flag))
		{
			cout << "ERROR! NUMBER NOT FOUND! RE-ENTER NUMBER(ESC - exit, ANY KEY - re-enter)" << endl;

			// ���� �������
			while (true)
			{
				*ch = _getch();

				// ���� ESC
				if (*ch == (char)27)
				{
					return;
				}

				break;
			}

			continue;
		}

		break;
	}

	system("cls");
}

// ���������� � ����� � �������� ��������� ������ ������
// � ����� �� � ��������� �� ����
int scanFileDelete(char* str, size_t s_size, unsigned long size, char* path)
{
	// �������� ����� � ������ ������� ������
	FILE* file = fopen(path, "rb");

	// ���� ���� ������� ������
	if (file != nullptr)
	{
		// ��������� ��������� � ����� ����� 
		fseek(file, 0, SEEK_END);

		// ����� �����
		unsigned long* f_size = new unsigned long;

		*f_size = ftell(file);

		// ��������� ��������� � ����� � ������
		fseek(file, 0, SEEK_SET);

		// �����
		char* buffer = new char[*f_size + 1];

		// ���������� ����� � �����
		fread(buffer, sizeof(char), *f_size, file);

		// �������� �����
		fclose(file);
		
		// ���������� ��������
		bool* flag = new bool;

		// ������������ ������
		for (char* buf = buffer; buf < buffer + *f_size; buf += 134)
		{
			// �� ��������� ���������� �������� ����������
			*flag = true;

			// ���� ������ ��������� � ������� �������
			for (char* s = str, * b = buf; s < str + s_size; s++, b++)
			{
				// ���� �� ��������� �������
				if (*s != *b)
				{
					*flag = false;

					break;
				}
			}

			// ���� ������ �������
			if (*flag)
			{
				unsigned long* j = new unsigned long;

				*j = 1;

				// �������� ������ �������� �� ������
				for (char* b = buf; *j < size + 1; ++*j)
				{
					// ���������� ��������� �����
					for (char* n = b; n <= buffer + *f_size; n++)
					{
						swap(*n, *(n + 1));
					}
				}

				delete j, flag;

				// �������� ����� � ������ �������� ������
				file = fopen(path, "wb");

				// ������ � ���� �� ������
				fwrite(buffer, sizeof(char), *f_size - size, file);

				// �������� �����
				fclose(file);

				return 1;
			}
		}

	}
	// ���� ���� �� ������
	else
	{
		cout << "ERROR OPEN FILE" << endl;

		return 0;
	}
}

// ����� ����
void searchAuto(car_t* list, unsigned int* count_user)
{
	while (true)
	{
		// ����� �����
		line();

		cout << "Search auto" << endl;

		line();

		// �����
		char* number = new char[20];

		// ���� ������
		cout << "Enter number: ";
		cin.getline(number, 20);

		// �������� �������
		system("cls");

		// ����� �����
		line();

		cout << "RESULT:" << endl;

		line();

		// ����� ������ �� ���� ������
		for (car_t* car_p = list; car_p < list + *count_user; car_p++)
		{
			// ���� ����� ������
			if (!strcmp(number, (*car_p).number))
			{	
				// ����� ���������� �� ����
						// ����� ������
				cout << "> Number auto: " << (*car_p).number << endl;

				// ����� ������
				cout << "> Mark auto: " << (*car_p).mark << endl;

				// ������ 
				cout << "> Model auto: " << (*car_p).model << endl;

				// �������
				cout << "> Owner`s surname: " << (*car_p).surname << endl;

				// ��� 
				cout << "> Owner`s name: " << (*car_p).name << endl;

				// ��������
				cout << "> Patronymic: " << (*car_p).patronymic << endl;

				// ��� �������
				cout << "> Year of crearion auto: " << (*car_p).date << endl;

				// ���� 
				cout << "> Price: " << (*car_p).price << endl;

				// ������� ����� �������
				pressAnyKey();

				// �������� �������
				system("cls");

				delete[] number;

				return;
			}
		}

		// ���� ���� �� ������� � ���� 
		cout << "NO CAR FOUND! PRESS ANY KEY TO RE-ENTER NUMBER OR EXIT[ESC]" << endl;
		
		// ������ 
		char* ch = new char[2];

		*(ch + 1) = 0;

		// ���������
		while (true)
		{
			*ch = _getch();

			if (*ch == (char)27)
			{
				delete[] number;

				system("cls");

				return;
			}

			break;
		}

		system("cls");

		continue;
	}
}

// ����������� ������������
void regUser(account_data* user, int* count_acc)
{
	// ��������� ��� ����� ������
	account_data* new_user = new account_data;

	// �������� �� �������������
	bool* flag = new bool;

	*flag = true;

	while (true)
	{
		system("cls");

		// ����� �����
		line();

		cout << "Registration user" << endl;

		// ����� �����
		line();

		// ���� ������ 
		cout << "> Enter new login: ";
		cin.getline((*new_user).login, 19);

		// ���� ������
		cout << "Enter new password: ";
		cin.getline((*new_user).password, 19);

		// �������� �� ������� ������ �� ������ � ����
		for (account_data* us = user; us < user + *count_acc; us++)
		{
			// ���� ����� ���������
			if (!strcmp((*new_user).login, (*us).login))
			{
				cout << "ERROR! LOGIN IS NOT UNIQUE!" << endl;

				*flag = false;

				break;
			}
		}

		// ���� �� ���������� 
		if (!*flag)
		{
			system("cls");

			continue;
		}

		// ����� �����������
		createAccount((*new_user).login, (*new_user).password);

		system("cls");

		break;
	}
}

// ������ �������������
void listUser(account_data* user, int* count_acc)
{
	// ������ �������
	char* ch = new char[2];

	*(ch + 1) = 0;

	for (account_data* us = user; us < user + *count_acc;)
	{
		// ����� �����
		line();

		cout << "User list (admin)" << endl;

		// ����� �����
		line();

		cout << "> Login: " << (*us).login << endl;
		cout << "> Password: " << (*us).password << endl;

		cout << "\n\n\n\n\n\n\nPRESS: [1] - left, [2] - right, [ESC] - exit";

		// ������� �������
		*ch = _getch();

		// ���� ������������ �������� esc �� �����
		if ((int)*ch == 27)
		{
			// �������� �������
			system("cls");

			return;
		}

		// ���� ������������ �������� ������� �����, �� ���������� ������
		if (!strcmp(ch, "1"))
		{
			// ���� ��� �� ������ ������ 
			if (us != user)
			{
				us--;

				system("cls");

				continue;
			}
		}

		// ���� ������������ �������� ������� ������, �� ��������� ������
		if (!strcmp(ch, "2"))
		{
			// ���� ��� �� ��������� ������ 
			if (us < (user + *count_acc - 1))
			{
				us++;

				system("cls");

				continue;
			}
		}

		system("cls");
	}
}
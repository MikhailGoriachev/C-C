#include <iostream>
#include <conio.h>

#include "head.h"
using namespace std;

//  1. ����������� ��������� - ���� ������ � �����. � ������ �������� ����� ������� ��������� ����������:
//		- ����� ��������
//		- ���
//		- ���������
//		- ��� ��������
//		- �����
//		- ��������

//	��������� ����� ��������� ������� :
//		- ������ ������� � ������������ ������� ��������
//		- ���������������� ����
//		- ���������� ��������
//		- �������� �������� �� ��
//		- �������� ���� �����
//		- �������������� ������
//		- ����� �� ������, ��
//		- ���� / ���� � ���� ���� ������
//		- ����� �� ���������
//

/////////////////////////////////////////////////////////////////////////
// ��������� ������ � ����� ���������
/// <summary>
/// ./Person Database 1.0/ - �������� �����
/// ./Person Database 1.0/Security/ - ����� ������������
/// ./Person Database 1.0/Security/access.list - ������� ������
/// ./Person Database 1.0/Security/key.data - ���� ����������
/// ./Person Database 1.0/Data/ - ����� �������� ���� ������
/// ./Person Database 1.0/Data/person.data - ���� ������ �����
/// </summary>


void main()
{
	// ����� �����
	int* sizeKey = new int;
	*sizeKey = 63;

	// ���� ����������
	key_t* key = new key_t;

	// ���� ����������
	key->crypt = new char[*sizeKey];
	key->decrypt = new char[*sizeKey];

	// �������� ����� ����������
	if (LoadingKey(key, *sizeKey));

	// ��������� �� ��������� ������� ������
	account_t** users = new account_t*;

	// ���������� ���������
	int* countUsers = new int;

	// ���������� �������������� � ������ �������������
	bool* adminFlag = new bool;

	*adminFlag = false;

	// ���� � �������
	if (!Login(users, countUsers, key, adminFlag))
		return;

	system("cls");

	// ���� ������ �����
	person_t** persons = new person_t*;

	// ���������� ����� � ���� ������
	int* countPersons = new int;

	// ����� ������ ������� ��������
	int* sizePerson = new int;

	*sizePerson = sizeof(person_t);

	// �������� ���� ������ �����
	LoadingPersons(persons, countPersons, sizePerson, key, sizeKey);

	// ������ ����
	char* c = new char;

	// ����
	while (true)
	{
		menu(c);

		// 1. LIST PERSON
		if (*c == '1')
		{
			ListPerson(persons, countPersons, sizePerson, key, sizeKey);
		}

		// 2. SEARCH PERSON
		else if (*c == '2')
		{
			SearchPerson(persons, countPersons, sizePerson, key, sizeKey);
		}

		// 3. ADD PERSON (ADMIN GROUP)
		else if (*c == '3')
		{
			// ���� ������������ �� ������ � ������ ���������������
			if (!*adminFlag)
			{				
				system("cls");

				outLine();

				cout << "ADD PERSON" << endl;

				outLine();

				cout << "ACCESS IS DENIED! FOR ADMIN GROUP" << endl;

				pressAnyKey();

				continue;
			}
			AddPerson(persons, countPersons, sizePerson, key, sizeKey);
		}

		// 4. DELETE PERSON (ADMIN GROUP)
		else if (*c == '4')
		{
			// ���� ������������ �� ������ � ������ ���������������
			if (!*adminFlag)
			{
				system("cls");

				outLine();

				cout << "ADD PERSON" << endl;

				outLine();

				cout << "ACCESS IS DENIED! FOR ADMIN GROUP" << endl;

				pressAnyKey();

				continue;
			}

			DeletePerson(persons, countPersons, sizePerson, key, sizeKey);
		}
		
		// 5. ACCOUNT MANAGEMENT (ADMIN GROUP)
		else if (*c == '5')
		{
			// ���� ������������ �� ������ � ������ ���������������
			if (!*adminFlag)
			{
				system("cls");

				outLine();

				cout << "ADD PERSON" << endl;

				outLine();

				cout << "ACCESS IS DENIED! FOR ADMIN GROUP" << endl;

				pressAnyKey();

				continue;
			}

			// ���� ��� ������ ��� ����� ������������
			while (AccontManagement(users, countUsers, key, sizeKey))
			{
				LoadingAccess(users, countUsers, key);
			}
			


		}

		// 6. DATA ENCRYPTION (ADMIN GROUP)
		else if (*c == '6')
		{
			// ���� ������������ �� ������ � ������ ���������������
			if (!*adminFlag)
			{
				system("cls");

				outLine();

				cout << "ADD PERSON" << endl;

				outLine();

				cout << "ACCESS IS DENIED! FOR ADMIN GROUP" << endl;

				pressAnyKey();

				continue;
			}


		}

		// [ESC] EXIT
		else if (*c == (char)27)
		{
			return;
		}
	}



}
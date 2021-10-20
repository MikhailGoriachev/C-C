#pragma once

// �������� ����� ����������
struct key_t 
{
	char* crypt;
	char* decrypt;
};

// ��������� ��������; access = a - admin; access = b - users;
struct account_t 
{
	char login[20];
	char password[20];
	char accessLevel[1];
};

// ��������� ������ ��������
struct person_t
{
	// �������� 
	int salary;

	// ����� �������� 
	char passport[20];

	// ��� 
	char name[20];

	// �������
	char surname[20];

	// ��������
	char patron[20];

	// ����������������� ���
	char id[20];

	// ����� ��������
	char adress[40];

	// ����� ������
	char job[40];
};

// ����� �����
void outLine();

// �������� ������� ����� ������� 
void pressAnyKey();

// �������� ����� ���������� �� ���� ./Person Database 1.0/Security/key.data
bool LoadingKey(key_t* key, int sizeKey);

// ���������� � ������������; mode = 1 - ����������, mode = 2 - ������������ 
void CryptOrDecrypt(char* str, int len, key_t* key, int mode, int sizeKey);

// ���� � ������� ������; 
bool Login(account_t** users, int* countUsers, key_t* key, bool* adminFlag);

// �������� ����� ./Person Database 1.0/Security/access.list - ������� ������
bool LoadingAccess(account_t** users, int* countUsers, key_t* key);

// 1. LIST PERSON
void ListPerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey);

// ����
void menu(char* c);

// �������� ���� ������ ����� �� ���� ./Person Database 1.0/Data/person.data
bool LoadingPersons(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey);

// 2. SEARCH PERSON
void SearchPerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey);

// 3. ADD PERSON (ADMIN GROUP)
void AddPerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey);

// 4. DELETE PERSON (ADMIN GROUP)
void DeletePerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey);

// ��������� ��������� ��������
void GenerationRandomCymbols(char* str, size_t size);

// ����� � ����� ��������� �����; 1 - �������, 0 - ���������;
int OutSearchPerson(person_t** persons, int* countPersons, person_t* searchPerson, int* sizePerson, key_t* key, int* sizeKey);

// 5. ACCOUNT MANAGEMENT (ADMIN GROUP)
int AccontManagement(account_t** users, int* countUsers, key_t* key, int* sizeKey);

// �������� ������������
void DeleteUser(account_t user, int sizeUser, key_t* key, int* sizeKey);

// �������� ������������; 0 - ������������ �� ������, 1 - ������������ ������;
int CreateUser(account_t** users, int* countUsers, key_t* key, int* sizeKey);
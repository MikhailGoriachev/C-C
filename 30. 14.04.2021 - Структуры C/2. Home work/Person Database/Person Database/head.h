#pragma once

// сруктура ключа шифрования
struct key_t 
{
	char* crypt;
	char* decrypt;
};

// структура аккаунта; access = a - admin; access = b - users;
struct account_t 
{
	char login[20];
	char password[20];
	char accessLevel[1];
};

// структура данных человека
struct person_t
{
	// зарплата 
	int salary;

	// номер паспорта 
	char passport[20];

	// имя 
	char name[20];

	// фамилия
	char surname[20];

	// отчество
	char patron[20];

	// идентификационный код
	char id[20];

	// адрес прописки
	char adress[40];

	// место работы
	char job[40];
};

// вывод линии
void outLine();

// ожидание нажатия любой клавиши 
void pressAnyKey();

// загрузка ключа шифрования по пути ./Person Database 1.0/Security/key.data
bool LoadingKey(key_t* key, int sizeKey);

// шифрование и дешифрование; mode = 1 - шифрование, mode = 2 - дешифрование 
void CryptOrDecrypt(char* str, int len, key_t* key, int mode, int sizeKey);

// вход в учётную запись; 
bool Login(account_t** users, int* countUsers, key_t* key, bool* adminFlag);

// загрузка файла ./Person Database 1.0/Security/access.list - учётные записи
bool LoadingAccess(account_t** users, int* countUsers, key_t* key);

// 1. LIST PERSON
void ListPerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey);

// меню
void menu(char* c);

// загрузка базы данных людей по пути ./Person Database 1.0/Data/person.data
bool LoadingPersons(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey);

// 2. SEARCH PERSON
void SearchPerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey);

// 3. ADD PERSON (ADMIN GROUP)
void AddPerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey);

// 4. DELETE PERSON (ADMIN GROUP)
void DeletePerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey);

// генерация случайных символов
void GenerationRandomCymbols(char* str, size_t size);

// поиск и вывод найденных людей; 1 - успешно, 0 - неуспешно;
int OutSearchPerson(person_t** persons, int* countPersons, person_t* searchPerson, int* sizePerson, key_t* key, int* sizeKey);

// 5. ACCOUNT MANAGEMENT (ADMIN GROUP)
int AccontManagement(account_t** users, int* countUsers, key_t* key, int* sizeKey);

// удаление пользователя
void DeleteUser(account_t user, int sizeUser, key_t* key, int* sizeKey);

// создание пользователя; 0 - пользователь не создан, 1 - пользователь создан;
int CreateUser(account_t** users, int* countUsers, key_t* key, int* sizeKey);
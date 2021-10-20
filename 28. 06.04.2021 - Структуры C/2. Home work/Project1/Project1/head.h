#pragma once

// структура аккаунта
struct account_data
{
	// логин
	char login[20];

	// пароль
	char password[20];
};

// структура словаря шифрования
struct cypher
{
	// строка дешифрования
	char cyp[128];

	// строка шифрования
	char decyp[128];
};

// структура базы данных автомобилей	
struct car_t
{
	char number[20];		//  - номер машины(кл - 2345т или 1)
	char mark[20];			//	- марка машины(BMW)
	char model[20];			//	- модель(m5)
	char surname[20];		//	- фамилия
	char name[20];			//  - имя
	char patronymic[20];	//  - отчество
	char date[11];			//	- год выпуска
	unsigned long price;	//	- цена
};

int login();
void deleteFile(const char path[]);
int createAccount(char* login, char* password);
int createAccount();
void encryption(cypher vocab, char* string, unsigned long size);
void decryption(cypher vocab, char* string, unsigned long size);
void pressAnyKey();
void line();
int menu(FILE* file);
int newAuto(FILE* file, car_t* database, unsigned long count_car);
void loadData(char* path_data);
void outList(car_t* car, unsigned int* count_car);
int scanFileDelete(char* str, size_t s_size, unsigned long size, char* path);
void deleteCar(FILE* file, car_t* list, unsigned int* count_car, char* path);
void searchAuto(car_t* list, unsigned int* count_user);
void regUser(account_data* user, int* count_acc);
void listUser(account_data* user, int* count_acc);

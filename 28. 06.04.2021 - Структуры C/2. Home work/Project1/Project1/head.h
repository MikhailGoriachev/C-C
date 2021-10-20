#pragma once

// ��������� ��������
struct account_data
{
	// �����
	char login[20];

	// ������
	char password[20];
};

// ��������� ������� ����������
struct cypher
{
	// ������ ������������
	char cyp[128];

	// ������ ����������
	char decyp[128];
};

// ��������� ���� ������ �����������	
struct car_t
{
	char number[20];		//  - ����� ������(�� - 2345� ��� 1)
	char mark[20];			//	- ����� ������(BMW)
	char model[20];			//	- ������(m5)
	char surname[20];		//	- �������
	char name[20];			//  - ���
	char patronymic[20];	//  - ��������
	char date[11];			//	- ��� �������
	unsigned long price;	//	- ����
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

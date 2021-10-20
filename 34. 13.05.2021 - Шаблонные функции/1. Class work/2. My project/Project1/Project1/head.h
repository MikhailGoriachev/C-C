#pragma once

void task1();
void task2();

void pressAnyKey();

// ��������� ������ � ��������
struct person_t
{
	/*�	���(���)
		�	�����
		�	���� ��������
		�	�����
		�	�������
		�	���������
		�	�������� ������
		�	�����
		�	���� ���������� �� ������*/

	char name[20];			// 0 - 19
	char surname[20];		// 20 - 39
	char patron[20];		// 40 - 59
	char number[20];		// 60 - 79
	char position[20];		// 80 - 99
	char nameDep[20];		// 100 - 119
	char salary[20];		// 120 - 139
	char date[20];			// 140 - 159
	char id[20];			// 160 - 179
};

void line();

void AllPersons(int* count, person_t** persons, int sizePerson);

int SearchPerson(int* count, person_t** persons, int sizePerson);

int DeletePerson(int* count, person_t** persons, int sizePerson, char* id);

int AddPerson(int* count, person_t** persons, int sizePerson);

int LoadingData(int* count, person_t** persons, int sizePerson);

void EditPerson(int* count, person_t** persons, int sizePerson);
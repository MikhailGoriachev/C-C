#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task1()
{
	// �������� ���������� ����� ��� ������, ���� ����� ��� �� �� ���������
	// FILE* ��������� �� ����, ������� fopen ���������� ����� ��������� �����
	// FILE* file = fopen("mytext.txt", "w");

	/*// ����� �� ����� ������
	puts("Hello world");
	// %s - ������� ������, %d - ������� �����. \� - ������� �� ��������� ������
	printf("My name is %s, I`m %d yars old.", "Dima", 43);*/

	// ����� � ����
	/*fputs("Hello world\n", file);
	fprintf(file, "My name is %s, I`m %d years old.\nend.", "Dima", 43);

	// �������� �����
	fclose(file);*/

	// ������������ ������ ��� ����� �����, ���� �� ����� 0.
	// ��� �����, ����� 0, ����������� � ���� � �������

	char name[40];
	int num = 1;

	cout << "Enter name file: ";
	cin.getline(name, 40);

	int len = strlen(name);

	name[len++] = '.';
	name[len++] = 't';
	name[len++] = 'x';
	name[len++] = 't';
	name[len++] = 0;
	

	FILE* file = fopen(name, "w");

	for (;;)
	{
		cout << "Enter number: ";
		cin >> num;
		if (num == 0)
			break;
		fprintf(file, "%d \n", num);
	}
	
	// �������� �����
	fclose(file);

	cin.ignore();
}


#define _CRT_SECURE_NO_WARNINGS


#include <iostream>

using namespace std;

void task2()
{
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

	// ������ ���������� ����� 
	FILE* file = fopen(name, "r");

	/*// ���� ���� ������� �������
	if (file != nullptr)
	{
		char buffer[200];
		// ���� �� ��������� ����� ����� 
		// feof - ����� �����
		while (!feof(file))
		{
			// ������ ����� ������ �� �����
			strcpy(buffer, "");
			fgets(buffer, 200, file);
			cout << buffer;
		}
		fclose(file);
	}
	else cout << "Error" << endl;*/

	// ���� ���� ������� �������
	if (file != nullptr)
	{
		int buffer;
		// ���� �� ��������� ����� ����� 
		// feof - ����� �����
		while (!feof(file))
		{
			// ������ ����� ������ ���������������� ���� �� �����
			fscanf(file, "%d", &buffer);
			cout << buffer << endl;
		}
		fclose(file);
	}
	else cout << "Error" << endl;
}
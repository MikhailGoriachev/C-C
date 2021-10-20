#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// ������� ������ ����� ����� 
int creatPart(char buff[], long size, int num, int len, char name[]);

void task1()
{
	// ������������ ��������� ���������� ������ �� ������� ����� ��������� ����

	// ��� ��������� �����
	char name[40];

	// ���� ����� �����
	cout << "Enter name file: ";
	cin.ignore();
	cin.getline(name, 40);

	cout << endl;

	int count = 0;

	// ���� ���������� ������
	cout << "Enter the number of part: ";
	cin >> count;

	cout << endl;

	// ����� ������ 
	char exp[40];
	// �������� ��������� ����� � ������ ��������� ������ 
	FILE* file = fopen(name, "rb");

	// ��������� ����� ����� �� ����������
	for (int i = strlen(name) - 1; i >= 0; i--)
	{
		if (name[i] == '.')
		{
			name[i + 1] = 'p';
			name[i + 2] = 'a';
			name[i + 3] = 'r';
			name[i + 4] = 't';
			name[i + 5] = ' ';
			name[i + 6] = 0;
			break;
		}
	}


	// ���� ���� ������� ������
	if (file != nullptr)
	{
		// ��������� ��������� � �����
		fseek(file, 0, SEEK_END);

		// ����� ��������� �����
		long size = ftell(file);

		if (size < count)
		{
			cout << "The file is too small" << endl;
			cout << "Exit" << endl;
			fclose(file);
			return;
		}

		// ����������� ��������� � ������ �����
		fseek(file, 0, SEEK_SET);

		// ����� ����� �����
		long sizePart = size / count;

		// ����� �����
		int len = strlen(name);

		// ���� ���������� ������
		for (size_t i = 0, num = 1; i < count; i++, num++)
		{
			if (i < count - 1)
			{
				size -= sizePart;
			}
			else sizePart = size;

			// ����� ��� ����� �����
			char* buffer = new char[sizePart];
			
			fread(buffer, sizeof(char), sizePart, file);

			int flag = creatPart(buffer, sizePart, num, len, name);

			if (!flag)
			{
				cout << "Exit" << endl;
				return;
			}

			delete[] buffer;
		}

		// �������� ��������� �����
		fclose(file);
	}
	// ���� ���� �� ������
	else cout << "NOT found file" << endl;
}

int creatPart(char buff[], long size, int num, int len, char name[])
{
	// �������� ����� �����
	char* Pnum = &name[len-1];

	char temp[40];

	_itoa(num, temp, 10);

	int len_temp = strlen(temp);

	Pnum[len_temp] = 0;

	strcpy(Pnum, temp);

	// �������� ����� �����
	FILE* file = fopen(name, "w");

	if (file != nullptr)
	{
		fwrite(buff, sizeof(char), size, file);

		fclose(file);

		return 1;
	}
	else
	{
		cout << "File NOT found" << endl;
		return 0;
	}
}
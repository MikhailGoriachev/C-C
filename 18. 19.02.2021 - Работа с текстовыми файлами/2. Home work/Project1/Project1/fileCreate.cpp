#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int answerCorrect(char answer[]);


// ������� �������� ����� � ���������� ����� 

// ����� � �������� - 0, ���� ������ - 1, ���� ���������� - 2
int fileCreate(char name[])
{
	// ��������� ������� ������� ���� � ������ ������ ��� ��������
	FILE* file = fopen(name, "r");

	// ���� ���� �� ������� �������
	if (file == nullptr)
	{
		cout << "File not found! Create file? (Yes/No): ";
		char answer[40];
		cin >> answer;
		
		cout << endl;

		if (!answerCorrect(answer))		
			return 0;

		file = fopen(name, "w");

		if (file != nullptr)
		{
			cout << "File " << name << " create complete!" << endl;
			cout << endl;
			fclose(file);
			return 1;
		}
		else
		{
			while (true)
			{
				cout << "Error create file! Return create file? (Yes/No)";
				cin >> answer;

				cout << endl;

				if (!answerCorrect(answer))
					return 0;

				if (answerCorrect(answer))
				{
					file = fopen(name, "w");
					if (file != nullptr)
					{
						cout << "File create complete!" << endl;
						cout << endl;
						return 1;
					}
				}

				cout << "Error create file! Change the name and re-create the file? (Yes/No): ";
				cin >> answer;

				cout << endl;

				if (!answerCorrect(answer))
					return 0;
				if (answerCorrect(answer))
				{
					cout << endl;
					cout << "Enter name file: ";
					cin >> name;

					cout << endl;

					file = fopen(name, "w");
					if (file != nullptr)
					{
						cout << "File create complete!" << endl;
						cout << endl;
						return 1;
					}
				}
			}
		}
	}

	// ���� ���� ������� ������ 
	cout << "Open file complete!" << endl;
	cout << endl;
	return 3;
}

// �������� ������ �� Yes/No
int answerCorrect(char answer[])
{
	while (true)
	{
		if (!strcmp(answer, "Yes"))
			return 1;
		if (!strcmp(answer, "No"))
			return 0;
		cout << "Error! Enter correct answer (Yes/No): ";
		cin >> answer;
		cout << endl;
	}
}

// �������� �� ������� "\n" � ����� ������
void detectBackN(char a[])
{
	int len = strlen(a);

	char* p = &a[len - 1];

	if (strcmp(p, "\n"))
	{
		p = &a[len];

		p[0] = '\n';
		p[1] = 0;
	}
}
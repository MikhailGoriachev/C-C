#include <iostream>

using namespace std;

void randMix(char* str, int len, int n)
{
	// ���� ��� �� ����� ������
	if (*(str + n))
	{
		int i = rand() % len;

		swap(*(str + n), *(str + i));

		randMix(str, len, n + 1);
	}
}

void task5()
{
	// 5. ����������� ������� ��������� ������ � �������� 
	// ������������ ������� ������ ������

	srand(time(0));

	// ������ 
	char* str = new char[40];

	// ���� ������
	cout << "Enter string:" << endl;
	cout << "> ";
	cin.ignore();
	cin.getline(str, 40);
	
	cout << endl;

	// ����� ������
	int len = strlen(str);

	// ������������� ������
	randMix(str, len, 0);

	// ����� ����������
	cout << "Result" << endl;
	cout << "> " << str << endl;

	delete[] str;
}
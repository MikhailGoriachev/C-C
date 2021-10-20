#include <iostream>

using namespace std;

long sumNumber(char* str)
{
	// ���� ����� �� �������� ������ ������
	if (*str)
	{
		// ������ ������ � ���� ������� ��� �������� 
		char c[1];

		// �� ��������� ������ ��������� ������ ������
		c[0] = *str;

		// ������� ������� � �����
		long sum = atoi(c);

		// ����������� ������������ ���������� ��������� �������� � ����������� ����
		return sum += sumNumber(str + 1);
	}

	return 0;
}

void task4()
{
	// 4. ����������� ������� ��������� ������ � ���������
	// ����� ����� � ���� ������

	// ������
	char* str = new char[40];

	// ���� ������
	cout << "Enter string: " << endl;
	cout << "> ";
	cin.ignore();
	cin.getline(str, 40);

	// ������������ ����� � ������
	cout << "Summer number: " << sumNumber(str) << endl;

	delete[] str;
}
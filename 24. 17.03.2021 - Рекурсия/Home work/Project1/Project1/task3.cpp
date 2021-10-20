#include <iostream>

using namespace std;

// ���������� ������� � ������
long vowelsStr(char* str)
{
	// ��� �������
	char a[] = "EeYyUuOoAa";

	// ���������� �������
	long count = 0;
	
	// �������� �� �������
	for (char* c = a; *c; c++)
	{
		if (*str == *c)
		{
			count++;
		}
	}

	// �� ��� ��� ���� ����� �� �������� ����
	if (*(str + 1))
	{
		count += vowelsStr(str + 1);
	}

	// �����������
	return count;

}

// ��������� ���������� ������� � �������
bool cmpVowelsCount(char** str, int rows, long count)
{
	// ����� ������� ������
	count = vowelsStr(*str);

	long count_n = vowelsStr(*(str + 1));

	// ���� ���������� ������� � ������� ������ �� ��������� � ����������� � ������� ������
	if (rows > 1 && (count < count_n || count > count_n))
	{
		return false;
	}

	if (rows > 2)
	{
		if (!cmpVowelsCount(str + 1, rows - 1, 0))
			return false;
	}

	return true;
}

void task3()
{
	// 3. ����������� ������� ��������� 2 ������ � ��������,
	// ���������� �� � ��� ��������� ������� ����.
	
	// ���������� �����
	int* rows = new int;

	// ���� ���������� �����
	cout << "Enter number rows: ";
	cin >> *rows;

	cin.ignore();

	// ��������� ������ ��� ���������� �����
	char** str = new char*[*rows];

	// ��������� �� ��������� ������
	char** rows_s = str;

	// ���� �����
	for (int num = 1, *n = &num; rows_s < str + *rows; rows_s++, ++*n)
	{
		// �������� ������
		*rows_s = new char[40];

		// ���� ������
		cout << "Enter " << *n << " string" << endl;
		cout << "> ";
		cin.getline(*rows_s, 40);
	}

	// ������� �������� ������ �� ���������� ������� ���� � �������
	if (!cmpVowelsCount(str, *rows, 0))
		cout << "No!" << endl;
	else cout << "Yes!" << endl;

	rows_s = str;

	// �������� ������ �� ����� ���������� �������
	for (; rows_s < str + *rows; rows_s++)
	{
		delete[] rows_s;
	}

	delete[] str;
	delete rows;

}
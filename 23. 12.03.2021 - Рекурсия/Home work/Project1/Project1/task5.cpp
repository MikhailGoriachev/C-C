#include <iostream>

using namespace std;

// ����������� �����
bool stringCmp(char a[], char b[])
{
	if (*a == *b)
	{
		if (*a == 0)
			return true;
		bool res = stringCmp(a + 1, b + 1);
	}
	else return false;
}

void task5()
{
	// 5. ����������� ������� ��������� 2 ������ � 
	// ��������, ����� �� ��� ���� �����.

	// ��� ������
	char* a = (char*)malloc(sizeof(char) * 40);
	char* b = (char*)malloc(sizeof(char) * 40);

	// ���� ������ ������
	cout << "Enter first string: ";
	cin.ignore();
	cin.getline(a, 40);

	// ���� ������ ������
	cout << "Enter second string: ";
	cin.getline(b, 40);

	// ������ �������
	if (stringCmp(a, b))
		cout << "Yes" << endl;
	else cout << "No" << endl;

	free(a);
	free(b);
}
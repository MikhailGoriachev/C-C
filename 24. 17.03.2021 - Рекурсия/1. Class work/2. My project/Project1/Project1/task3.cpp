#include <iostream>

using namespace std;

// ��������� �����: ������ � ������ �����������
bool cmpString(char* a, char* b, size_t len)
{
	if (*a == *(b + len - 1) && *a != 0)
	{
		if (cmpString(a + 1, b, len - 1))
		{
			return true;
		}
		else return false;
	}
	if (*a == 0)
		return true;

	return false;

}

void task3()
{
	// ������� ��������� ��� ������ � ���������� ������ � ����������� ������

	// ������ ������
	char* a = (char*)malloc(sizeof(char) * 40);

	// ������ ������
	char* b = (char*)malloc(sizeof(char) * 40);

	// ���� ������ ������
	cout << "Enter first string: ";
	cin.ignore();
	cin.getline(a, 40);

	// ���� ������ ������
	cout << "Enter secong string: ";
	cin.getline(b, 40);

	// ����� ������ ������
	size_t len = strlen(b);

	// ��������� �����: ������ � ������ �����������
	if (cmpString(a, b, len))
	{
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
}
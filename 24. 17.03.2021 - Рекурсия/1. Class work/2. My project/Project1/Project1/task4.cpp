#include <iostream>

using namespace std;

void swapSymb(char* str, char* a, char* b)
{
	if (*str != 0)
	{
		if (*str == *a)
		{
			*str = *b;
		}
		swapSymb(str + 1, a, b);
	}
}

void task4()
{
	// ����������� ������� ��������� ������ � 2 ������� 
	// � ������ ��� ��������� ������� ������� � ������ �� ������

	// ������ 
	char* str = (char*)malloc(sizeof(char) * 40);

	// ���� ������
	cout << "Enter string: ";
	cin.ignore();
	cin.getline(str, 40);

	cout << endl;

	// ������ ������
	char* a = (char*)malloc(sizeof(char));

	// ������ ������
	char* b = (char*)malloc(sizeof(char));

	// ���� ������� �������
	cout << "Enter first symbol: ";
	cin >> a;

	// ���� ������� ������� 
	cout << "Enter second symbol: ";
	cin >> b;

	// ����� ������� ������
	swapSymb(str, a, b);

	// ����� ������
	cout << str << endl;
}
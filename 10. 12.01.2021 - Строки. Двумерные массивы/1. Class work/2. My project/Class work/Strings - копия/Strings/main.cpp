#include <iostream>

using namespace std;

void main()
{
	// ������ ������
	/*char str[40];
	str[0] = 'H';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = 0;*/ // ����� ������ ��������� ������� ����� 0

	// ������ ������
	// char str[40] = {'H', 'e' , 'l', 'l', 'o'};

	// ������ ������
	char str[40] = "Hello";
	char str2[40];

	// ���������� ������ str � str2
	strcpy_s(str2, str);

	cin >> str;
	cin >> str2;

	// ��������� ����� 
	// strcmp -  ���� ������� ����� = 0, ���� ������ ������ ���� ������ ������ 
	// � ���������� ������� = -1, ���� ������ ������ ���� ����� ������ � 
	// ���������� ������� = 1
	if (strcmp(str, str2) == 0)
		cout << "String are qual" << endl;

	else cout << "not equal";
	// ������� ����� ������ 
	// cout << strlen(str) << endl;

	cout << endl;
	cout << str << endl;
	cout << str2 << endl;
}
#include <iostream>
// ��� ����� ������
#include <conio.h>
using namespace std;

void main()
{
	// ��������� ��� ������� ������ � ������� �� �� �����
	/*char s[40];

	cin >> s;


	// ����� ������
	size_t len = 0;
	for (size_t i = 0; s[i] != 0; i++)
	{
		cout << s[i] << endl;
		len++;
	}

	cout << "String size = " << len << endl;*/

	// ������������ ������ ������ ��������� �������� 
	// ��� ������� ����� �� !

	/*char s[40];

	// ���� ������
	cin >> s;

	// ����� ������
	for (size_t i = 0; s[i] != 0; i++)
	{
		cout << s[i] << " ";
	}

	// �������� �������� ������
	for (size_t i = 0; s[i] != 0; i++)
	{
		switch (s[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'y':
				s[i] = '!';
		} 

	}

	cout << endl;

	// ����� ������
	for (size_t i = 0; s[i] != 0 ; i++)
	{
		cout << s[i] << " ";
	}*/

	// ������������ ���������� ���� ��������
	/*while (true)
	{
		char ch = _getch(); //_getch ���������� �������� ������� �������
		cout << ch << " code: " << (int)ch << endl; // (int) - ���������� � ���� int 
	}*/

	// ��������� ������ ���� �������� � ������� ���� ������� (����� �� ESC)
	/*while (true)
	{
		int code;
		cin >> code;
		cout << "Code: " << code << " Symbol: " << (char)code << endl;

		// ����� �� ESC
		if (code == 27)
			break;
	}*/

	// ������������ ������ ������, ���� � ������ ��� ������� ����������
	// ��������� ������� YES, ����� ��� ������� '0'
	/*char s[40];

	cin >> s;

	bool flag = true;
	for (size_t i = 1; s[i] != 0; i++)
	{
		if (s[i] != s[0])
		{
			cout << "Letters are not equal" << endl;
			flag = false;
			break;
		}
	}

	if (flag)
		cout << "All letters are equal" << endl;*/

	// ������������ ������ ������, ��������� ������ ������� ������ � ��������� 
	// ������� ������
	/*char str[40];

	cin >> str;

	for (size_t i = 0; str[i] != 0; i++)
	{
		cout << str[i] << " ";
	}

	cout << endl;

	int len = 0;
	for (size_t i = 0; str[i] != 0; i++)
	{
		len++;
	}

	int temp = str[0];
	str[0] = str[len - 1];
	str[len - 1] = temp;
	
	for (size_t i = 0; str[i] != 0; i++)
	{
		cout << str[i] << " ";
	}*/

	// ������������ ������ ������, ��������� "��������������" � � 
	// ������� �� �����
	/*char str[40];

	cin >> str;

	// ���������� ������ ������ � ������� strlen()
	size_t len = strlen(str);

	// ������ �������
	// int len = 0;
	// for (size_t i = 0; str[i] != 0; i++)
	// {
	// 	len++;
	// }

	for (size_t i = 0, k = len - 1; i < len / 2; i++, k--)
	{
		char temp = str[i];
		str[i] = str[k];
		str[k] = temp;
	}

	// ����� ������
	cout << str << endl;*/

	// ������������ ������ 2 ������, ��������� ����������, ����� �� ���
	// �����������
	/*char str1[40], str2[40];

	cin >> str1 >> str2;

	bool flag = true;

	for (size_t i = 0; str1[i] != 0 || str2[i] != 0; i++)
	{
		if (str1[i] != str2[i])
		{
			flag = false;
			break;
		}
	}


	if (flag)
		cout << "YES" << endl;
	else cout << "NO"; */




}
#include <iostream>

using namespace std;

void outNumber(int a, int b)
{
	if (a < b)
	{
		cout << a << endl;

		outNumber(++a, b);
	}

	if (a > b)
	{
		cout << b << endl;
		outNumber(a, ++b);
	}
}

void task2()
{
	// 2. ����������� ������� ��������� 2 ����� [a, b] 
	// � ������� �������� ����� �� [a; b]

	int a, b;

	// ���� a
	cout << "Enter a: ";
	cin >> a;

	// ���� b 
	cout << "Enter b: ";
	cin >> b;

	cout << endl;

	// ����� �������
	outNumber(a, b);

	cout << endl;

	cout << "End." << endl;
}
#include <iostream>

using namespace std;

void outOdd(int num)
{
	// ���� ����� ������ ����
	if (num > 0)
	{
		// ���� ����� �������� 
		if (num % 2 != 0)
			cout << num << endl;
		// �� ����� ���������� ���� � ���������� ������� 
		outOdd(--num);
	}
}

void task1()
{
	// 1. ����������� ������� ��������� ����� � ������� 
	// ��� �������� ����� �� 1 � �� ����� �����
	
	int num;

	// ���� �����
	cout << "Enter number: ";
	cin >> num;

	cout << endl;

	// ����� �������
	outOdd(num);

	cout << endl;

	cout << "End." << endl;
}
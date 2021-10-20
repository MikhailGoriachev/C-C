#include <iostream>

using namespace std;

bool primeNumber(int* num, int n)
{
	// ���� �������� ������ �������� �������� ����� � ��� ���� ����� ������ 1
	if (n > *num / 2 && *num > 1)
		return true;
	// ���� �������� ������ �������� � ������� �� ������� ����� �� �������� ������ 0 � ���������� ������� �� �������� �������� ������
	else if (n <= *num / 2 && *num % n > 0 && primeNumber(num, n + 1))
	{
		return true;
	}

	// ���� ��� �������� �� ������� ��� ����� ������ ����
	return false;
}

void task2()
{
	// 2. ����������� ������� ��������� ����� � ����������, 
	// �������� �� ��� ������� ������

	// �����
	int* num = new int;

	// ���� �����
	cout << "Enter number: ";
	cin >> *num;

	// �������� �� �� �������� �� ����� �������
	if (primeNumber(num, 2))
		cout << "Yes!" << endl;
	else cout << "No!" << endl;

	// �������� ������
	delete num;
}
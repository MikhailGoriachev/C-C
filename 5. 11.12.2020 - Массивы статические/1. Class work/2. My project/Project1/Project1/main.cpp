#include <iostream>

using namespace std;

int main()
{
	// ������������ ������ ������ �� 5 �����,
	// ��������� "��������������" ��� ����� � �������
	// � ������� ������ �� ����� 
	// 1 2 3 4 5 -> 5 4 3 2 1 

	/*const int size = 5;

	int arr[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter [" << i << "]:";
		cin >> arr[i];
	}

	// ����� ������� �� ����������
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	int temp;

	// ��������� �������
	for (size_t i = 0; i < size/2; i++)
	{	
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}

	// ����� �� �����
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}*/

	// ������������ ������ ��� �������
	// �� ������ �������� ������, ��������� 
	// ���������� �� � ���� ������ �� 8 ���������
	// � ������� ��� �� �����
	
	/*const int size1 = 4;
	const int size2 = 8;

	int arrMax[size2], arr1[size1], arr2[size1];

	// ���� ������� �������
	for (size_t i = 0; i < size1; i++)
	{
		cin >> arr1[i];
	}

	// ���� ������� �������
	for (size_t i = 0; i < size1; i++)
	{
		cin >> arr2[i];
	}

	// ���������� �������� �������
	for (size_t i = 0; i < size1; i++)
	{
		arrMax[i] = arr1[i];
		arrMax[i+size1] = arr2[i];
	}

	// ����� �������� ������� �� �����
	for (size_t i = 0; i < size2; i++)
	{
		cout << arrMax[i] << " ";
	}
	*/

	// ������������ ������ ������ �� 8
	// ���������, ��������� ��������� ��� �� ��� 
	// �� ������ �������� � ������� �� �� �����
	/*const int sizeMax = 8, sizeMin = 4;

	int aMax[sizeMax], a[sizeMin], b[sizeMin];

	for (size_t i = 0; i < sizeMax; i++)
	{
		cout << "Enter [" << i << "]:";
		cin >> aMax[i];
	}

	for (size_t i = 0; i < sizeMin; i++)
	{
		a[i] = aMax[i];
		b[i] = aMax[i + sizeMin];
	}

	for	(size_t i = 0; i < sizeMin; i++)
	{
		cout << a[i] << " ";
	}

	for	(size_t i = 0; i < sizeMin; i++)
	{
		cout << b[i] << " ";
	}*/
	

	// ������������ ������ 2 ������ �� �������
	// ��������� ������, ��������� ��������� �����
	// �� ��� ������� ���� ����� �����������

	const int size = 4;

	int a[size], b[size], n = 0;

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter [" << i << "]: ";
		cin >> a[i];
	}

	cout << endl;

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter [" << i << "]: ";
		cin >> b[i];
	}

	cout << endl;

	for (size_t i = 0; i < size; i++)
	{
		if (a[i] == b[i])
			n++;
	}

	if (n == size)
		cout << "YES";
	else
		cout << "NO";
}
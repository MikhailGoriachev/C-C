#include <iostream>
#include <Windows.h>
using namespace std;

int main() 
{

	//
	//
	//
	// ��������������� ������
	//
	//
	//

	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	// ���������� ������� � ���� ��� ������
	/*string students[10] = {
		"Ivanov", "Petrov", "Sidorov",
		"Ahmedov", "Eroshkin", "Vihin",
		"Andreev", "Vin Dizel", "Kartoshkin", "Chubajs"
	};
	// ����� ������� �������� "Ivanov"
	cout << students [0] << endl;*/

	// ����� ���� ��������� �������
	/*string students[10] = {
		"Ivanov", "Petrov", "Sidorov",
		"Ahmedov", "Eroshkin", "Vihin",
		"Andreev", "Vin Dizel", "Kartoshkin", "Chubajs"
	};

	for (int i = 0; i < 10; i++)
	{
	cout << students [i] << endl;
	}*/

	// ���������� ������� ��� �������������
	/*string students[10];
	// ���
	int n[12];*/

	// ��� �������� ������� ������� ����� �������������� ������ ��������� 

	// ���������� ������� � ���������� 
	/*int arr[10];

	for (int i = 0; i < 10; i++)
	{
		cout << "Arr " << i + 1 << ":";
		cin >> arr[i];
	}

	cout << "Arr: ";

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ", ";
	}*/

	//
	//
	// ������ � ������
	//
	//
	//

	// ���������� ������� (��� ��� � ������)
	/*int a[30];
	a[0] = 1;
	a[2] = 12;
	a[3] = 12;
	a[4] = 11;
	a[1] = 5;*/

	// ���������� ��������� 
	/*const int size = 3;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;*/

	/*const int size = 5;

	int a[size] = { 1, 2, 3, 4, 5 };

	// ������ ����� �������� ������
	//int a[size] = {0};

	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;*/

	// ������� ����� ��������� ������� 

	/*const int size = 5;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a[i];
	}

	int sum = 0;

	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
		sum += a[i];
	}

	cout << endl;

	cout << "Sum = " << sum << endl;*/

	// ������������ ������ 5 �����, ��������� ������� �� �����	
	/*const int size = 5;

	int a = 0, sum = 0;

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> a;
		sum += a;
	}

	cout << "Sum = " << sum << endl;*/

	// ������������ ������ ������ �� 5 �����, 
	// ��������� ������� ��� ����� ������� �� 
	// ����� � ������ � � �������� �������

	/*const int size = 5;

	int arr[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> arr[i];
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	for (int i = size - 1; i >= 0; i--)
	{
		cout << arr[i] << " ";
	}
	
	cout << endl;*/

	// ������������ ������ ������ �� 5 �����, 
	// ��������� �������� ��� ������ � �������
	// �� ���� � ������� ������ �� �����

	/*const int size = 5;

	int arr[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> arr[i];
		if (arr[i] == 3)
			arr[i] = 0;
	}
	
	cout << endl;

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;*/

	// ������������ ������ ������ �� 5 �����, 
	// ��������� ������ ������� ������� �������
	// ������� � ��������� ��������� � �������
	// ������ �� �����

	/*const int size = 5;

	int arr[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> arr[i];
	}

	int temp = arr[0];
	arr[0] = arr[size-1];
	arr[size-1] = temp;

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;*/

	// ������������ ������ ������ �� 6 �����, 
	// ���� ����� ��������� ������ �������� 
	// ������� ����� ����� ��������� ������ ��������
	// �������, ��������� ����� "YES", 
	// ����� ��������� ����� "NO"
	/*const int size = 6;

	int arr[size], sum1 = 0, sum2 = 0;

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter " << i << " element: ";
		cin >> arr[i];
	}

	for (size_t i = 0; i < size / 2; i++)
	{
		sum1 += arr[i];
		cout << arr[i] << " ";
	}

	for (size_t i = size / 2; i < size; i++)
	{
		sum2 += arr[i];
		cout << arr[i] << " ";
	}

	cout << endl;

	if (sum1 == sum2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;*/
}





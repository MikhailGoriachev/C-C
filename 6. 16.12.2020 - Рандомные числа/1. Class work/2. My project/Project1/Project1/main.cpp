#include <iostream>

	// ���������� �������
#include <time.h>
using namespace std;

void main()
{
	// ��������� �����
	// ��������� ����� 

	// �����, ���������������� ������ ���� ���, ����� ���������������� 
	// �� ��������� �����
	/*srand(time(0));


	int a, b;

	cout << "Enter min random number: ";
	cin >> a;

	cout << "Enter max random number: ";
	cin >> b;

	// ������� ��������� "���������" ����� 

	for (size_t i = 0; i < 20; i++)
	{
		cout << rand() % (a - b + 1) + a << endl;
	}
	*/

	// ������������ ������ ���������� ��������� ����� � ��
	// ��������. ��������� ����� �� ����� ���� ����� � ���������
	// �� ������� ��������������� 

	/*srand(time(0));

	int col, max, min, avg, temp; 
	float sum = 0;

	cout << "Col: ";
	cin >> col;

	cout << "Max: ";
	cin >> max; 

	cout << "Min: ";
	cin >> min;

	for (size_t i = 0; i < col; i++)
	{
		temp = rand() % (max - min + 1) + min;
		cout << temp << endl;
		sum += temp;
	}

	cout << "Result: " <<  sum / col << endl;*/

	// ������������ ������ �������� ���������� �����, ���������
	// ��������� ������ �� 10 ����� ��������� ����������� �������
	// �� ��������� ��������� � �������� ������������� ��������
	// ������� �� ����

	/*int max, min;

	srand(time(0));

	cout << "Enter max:";
	cin >> max;

	cout << "Enter min:";
	cin >> min;

	const int size = 10;

	int arr[size];

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
		if (arr[i] < 0)
			arr[i] = 0;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}*/

	// ������������ ������ ������ �� 5 �����, ��������� ������ ������� 2 ���������
	// �������� ����� ������� � ������� �� �����

	srand(time(0));

	const int size = 5;

	int arr[size], ranPoz_1, ranPoz_2;

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter [" << i << "]: ";
		cin >> arr[i];
	}

	cout << endl;

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	ranPoz_1 = rand() % 5;

	ranPoz_2 = rand() % 5;

	int temp; 
	temp = arr[ranPoz_1];
	arr[ranPoz_1] = arr[ranPoz_2];
	arr[ranPoz_2] = temp;


	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

}
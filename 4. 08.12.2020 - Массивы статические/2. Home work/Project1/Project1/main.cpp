#include <iostream>

using namespace std;

void main()
{
	int num;
	cout << "--------------------------------------------" << endl << endl;
	cout << "Enter the task number : ";
	cin >> num;
	cout << endl << "--------------------------------------------" << endl << endl;

	// 1. ������������ ������ ������ �� 5 �����.
	// ��������� �������� � ������� ��� ������ �� ������,
	// � ��� ������ �� ������.
	if (num == 1)
	{
		cout << "                 The task 1                 " << endl << endl;
		const int size = 5;

		int arr[size];

		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> arr[i];

			if (arr[i] == 3)
				arr[i] = 5;
			else if (arr[i] == 5)
				arr[i] = 3;
		}

		cout << endl << "Arr: ";

		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl;
	}

	// 2. ������������ ������ ������ �� 5 �����. 
	// ��������� ������� ����������� � ������������ 
	// �������� � �������� ��

	if (num == 2)
	{
		cout << "                 The task 2                 " << endl << endl;

		const int size = 5;

		int arr[size];

		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> arr[i];
		}

		int max = arr[0], min = arr[0];

		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] > max)
				max = arr[i];
			if (arr[i] < min)
				min = arr[i];
		}	

		cout << endl << "Array: ";

		for (size_t i = 0; i < size; i++)
		{		

			if (arr[i] == max)
				arr[i] = 0;
			if (arr[i] == min)
				arr[i] = 0;

			cout << arr[i] << " ";
		}

		cout << endl;

	}

	// 3. ������������ ������ ������ �� 5 �����.
	// ��������� ������� ����������� � ������������ 
	// �������� � ������ �� ������� � �������, ����� 
	// ���� ������� ������ �� �����

	if (num == 3)
	{
		cout << "                 The task 3                 " << endl << endl;
		const int size = 5;

		int arr[size], max, min;

		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> arr[i];

			if (i == 0 || arr[i] > max)
				max = arr[i];
			if (i == 0 || arr[i] < min)
				min = arr[i];
		}

		int temp;

		cout << endl << "Array: ";

		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] == max)
				arr[i] = min;
			else if (arr[i] == min)
				arr[i] = max;
			cout << arr[i] << " ";
		}

		cout << endl;
	}
		// 4. ������������ ������ ������ �� 6 �����. 
		// ��������� ���� ������������ �������� ������ 
		// �������� ������� ����� ����� ��������� ������ 
		// �������� �������,  ��������� ����� "YES!" ��� "NO!" �����.

	if (num == 4)
	{
		cout << "                 The task 4                 " << endl << endl;
		const int size = 6;

		int arr[size], mult = 0, sum = 0;

		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> arr[i];
		}

		for (size_t i = 0; i < size/2; i++)
		{
			mult += arr[i];

		}
		for (size_t i = size/2; i < size; i++)
		{
			sum += arr[i];
		}

		cout << endl;

		if (mult == sum)
			cout << "YES";
		else cout << "NO";

		cout << endl;
	}
	
}
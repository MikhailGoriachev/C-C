#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	int num;
	cout << "--------------------------------------------" << endl << endl;
	cout << "Enter the task number : ";
	cin >> num;
	cout << endl << "--------------------------------------------" << endl << endl;

	srand(time(0));

	if (num == 1)
	{
		cout << "                 The task 1                 " << endl << endl;

		// 1. ������������ ������ ������ �� 5 �����. 
		// ��������� ������������ ��� �������� ������� ��������� ������� ��
		// ������� ������ �� �����

		const int size = 5;

		int arr[size];

		// ���� ������� 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> arr[i];
		}

		cout << endl;

		// ����� ������� 
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}


		// ������ ��������� ��������� ����������
		for (size_t i = 0, temp, ran1, ran2; i < size; i++)
		{		
			// ��������� ����� ��� ������� ������� � ������� ���������
			ran1 = rand() % 5;
			ran2 = rand() % 5;

			// ������ ��������� ���������
			temp = arr[ran1];
			arr[ran1] = arr[ran2];
			arr[ran2] = temp;
		}
		
		cout << endl;

		// ����� �������
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl;
	}

	if (num == 2)
	{
		cout << "                 The task 2                 " << endl << endl;

		// 2. ������������ ����� �������� ��������� �����, 
		// ��������� ��������� ������ �������� ��������� 
		// ����� � ���� ���������.

		int size, max, min, val;

		cout << "Enter quantity: ";
		cin >> size;

		cout << "Max random number: ";
		cin >> max;

		cout << "Min random number: ";
		cin >> min;

		cout << endl;

		for (size_t i = 0; i < size; i++)
		{
			val = rand() % (max - min + 1) + min;
			if (val % 2 == 0)
				val++;
			cout << "Random (" << i + 1 << ") : " << val << endl;
		}
	}

	if (num == 3)
	{
		cout << "                 The task 3                 " << endl << endl;

		// 3. ��������� ��������� ������ �� 10 ��������� 
		// ���������� ������� � ��������� �� 10 �� 20, ����� ���� ������
		// ��������� �� �����, ������ ������� ������� ��������
		// ������� � ������������� � ������ ��� ��� ���������

		// ���������� ��������
		const int size = 10, min = 10, max = 20;

		// ���������� ������� 
		int arr[size], temp;

		// ����� ������� 
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % (max - min + 1) + min;
			cout << "Array [" << i << "] : " << arr[i] << endl;
		}

		cout << endl;

		// ������ ������� �������� � ������������� ��������� ������� 
		temp = arr[1];
		arr[1] = arr[size - 2];
		arr[size - 2] = temp;

		// ����� ������� 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Array [" << i << "] : " << arr[i] << endl;
		}
	}

	if (num == 4)
	{
		cout << "                 The task 4                 " << endl << endl;

		// 4. ��������� ��������� ������ �� 10 ��������� 
		// ���������� ������� � ��������� �� - 10 �� 20, 
		// ����� ���� ��������� ������ ������� 2 �����
		// ��������� ����� � ������� � ������� ������ �� �����

		// ���������� ��������
		const int size = 10, min_r = -10, max_r = 20;

		// ���������� �������
		int arr[size];

		// ���������� ������� ���������� �������
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % (max_r - min_r + 1) + min_r;
			cout << "arr[" << i << "]: " << arr[i] << endl;
		}

		cout << endl;

		int min1 = arr[0], min2 = arr[0], min1_poz, min2_poz;

		// ���������� ������� � ������� ������������ �������� ������� 

		min1 = arr[0];
		min2 = arr[1];

		for (size_t i = 2, temp; i < size; i++)
		{
			if (min2 < min1)
			{
				temp = min1;
				min1 = min2;
				min2 = temp;
			}

			if (arr[i] < min2)
				min2 = arr[i];
		}

		// �������� �� ��������
		if (min2 < min1)
		{
			int temp = min1;
			min1 = min2;
			min2 = temp;
		}

		// ������������ ������ ������� ������������ � ������� ������������ ���������
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] == min1)
				min1_poz = i;
			if (arr[i] == min2)
				min2_poz = i;
		}


		cout << "Min 1 (arr[" << min1_poz << "]): " << arr[min1_poz] << endl;
		cout << "Min 2 (arr[" << min2_poz << "]): " << arr[min2_poz] << endl;
		cout << endl;

		// ����� ������� ������������ �������� ������ �����������,
		// � ������� ������������ ������ �����������
		int temp = arr[min1_poz];		
		arr[min1_poz] = arr[min2_poz];
		arr[min2_poz] = temp;

		for (size_t i = 0; i < size; i++)
		{
			cout << "arr[" << i << "]: " << arr[i] << endl;
		}

		cout << endl;
	}

	if (num == 5)
	{
		cout << "                 The task 5                 " << endl << endl;

		// 5. ��������� ��������� ������ �� 7 ��������� 
		// ���������� ������� � ��������� �� - 20 �� 10, ����� ����
		// ��������� ������ ������� 2 ����� ������� ����� 
		// � ������� � ������� ������ �� �����

		const int size = 7, min_r = - 20, max_r = 10;

		int arr[size];


		// ���������� ������� ���������� ������� � ����� ���
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % (max_r - min_r + 1) + min_r;
			cout << "arr[" << i << "]: " << arr[i] << endl;
		}

		cout << endl;

		// ���������� ������� ������������� �������� �������
		// � ������� ������������� �������� 
		int max1 = arr[0], max2 = arr[1];

		for (size_t i = 2, temp; i < size; i++)
		{
			if (max2 > max1)
			{
				temp = max1;
				max1 = max2;
				max2 = temp;
			}
			if (arr[i] > max2)
				max2 = arr[i];
		}

		// �������� �� �������� 
		if (max2 > max1)
		{
			int temp = max1;
			max1 = max2;
			max2 = temp;
		}

		// ���������� ������� ������������ ���������
		int max1_poz, max2_poz;

		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] == max1)
				max1_poz = i;
			if (arr[i] == max2)
				max2_poz = i;
		}

		// ����� ������������ ��������� ������� 
		cout << "Max 1 (arr[" << max1_poz << "]): " << arr[max1_poz] << endl;
		cout << "Max 2 (arr[" << max2_poz << "]): " << arr[max2_poz] << endl;

		cout << endl;

		// ������ ������� ������������� �������� 
		// ������� ������ � ��������

		int temp = arr[max1_poz];
		arr[max1_poz] = arr[max2_poz];
		arr[max2_poz] = temp;

		for (size_t i = 0; i < size; i++)
		{
			cout << "arr[" << i << "]: " << arr[i] << endl;
		}

		cout << endl;
	}
}

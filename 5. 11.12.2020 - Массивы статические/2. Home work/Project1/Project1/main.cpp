#include <iostream>

using namespace std;

int main()
{
	int num;
	cout << "--------------------------------------------" << endl << endl;
	cout << "Enter the task number : ";
	cin >> num;
	cout << endl << "--------------------------------------------" << endl << endl;
	if (num == 1)
	{
		cout << "                 The task 1                 " << endl << endl;
		// 1. ������������ ������ ������ �� 5 �����.��������� ����������� ������������ ����� � ������� � 2 ���� �
		// ��������� ������������� ����� �� 3.

		const int size = 5;

		int arr[size];

		// ���� �������
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "] ";
			cin >> arr[i];
		}

		// �������
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] > 0 && arr [i] != 0)
				arr[i] *= 2;
			else if (arr[i] != 0) arr[i] -= 3;
		}

		// ������ ���� ��������� �������
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

	}

	if (num == 2)
	{
		cout << "                 The task 2                 " << endl << endl;
		// 2. ������������ ������ 2 ������� �� 4 ����� ������.��������� ��������, ����� �� 0 ������� ������� ������� �����
		// ��������� ������� �������.
		
		const int size = 4;

		int a[size], b[size], n;
		// ���� ������� ������� 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> a[i];
		} 

		cout << endl;

		// ���� ������� ������� 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> b[i];
		}

		// ��������� ������

		int sum = 0;

		for (size_t i = 0; i < size; i++)
		{
			sum += b[i];
		}

		// ����� ����������
		if (a[0] == sum)
			cout << "YES!" << endl;
		else cout << "NO!" << endl;
	}

	if (num == 3)
	{
		cout << "                 The task 3                 " << endl << endl;
		// 3. ������������ ������ 2 ������� �� 4 ����� ������. ��������� �������� �������� �� ��������� �������� � ������
		// ������ ����� ���� : 1 2 3 4, 5 6 7 8 -> 1 5 2 6 3 7 4 8
		const int sizeMax = 8, sizeMin = 4;
		
		int a[sizeMin], b[sizeMin], arr[sizeMax];

		// ���� ������� ������� 
		for (size_t i = 0; i < sizeMin; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> a[i];
		}

		cout << endl;

		for (size_t i = 0; i < sizeMin; i++)
		// ���� ������� ������� 
		{
			cout << "Enter [" << i << "]: ";
			cin >> b[i];
		}

		// ����� ������� �������

		for (size_t i = 0; i < sizeMin; i++)
		{
			cout << a[i] << " ";
		}

		cout << endl;

		// ����� ������� �������
		for (size_t i = 0; i < sizeMin; i++)
		{
			cout << b[i] << " ";
		}

		cout << endl;

		// ���������� ���� �������� � ����
		for (size_t i = 0, x = 0, r = 1; i < sizeMin; i++, x+=2, r+=2)
		{
			arr[x] = a[i];
			arr[r] = b[i];
		}

		// ����� �������� ������� 
		for (size_t i = 0; i < sizeMax; i++)
		{
			cout << arr[i] << " ";
		}
		
		cout << endl;
	}

	if (num == 4)
	{
		cout << "                 The task 4                 " << endl << endl;
		// 4. ������������ ������ 2 ������� �� 4 ����� ������. ��������� ������ ������� ����������� ������� ������� �������
		// � ������������ ������� ������� �������

		const int size = 4;

		int a[size], b[size];

		// ���� ������� ������� 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> a[i];
		}

		cout << endl;

		// ���� ������� ������� 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> b[i];
		}

		int pozMax_a = 0, pozMax_b = 0;

		// ���������� ������������� �������� ������� � ������ � ������� ��������
		for (size_t i = 0, max_a = 0, max_b = 0; i < size; i++)
		{
			if (a[i] > max_a)
			{ 
				max_a = a[i];
				pozMax_a = i;
			}
				
			if (b[i] > max_b)
			{
				max_b = b[i]; 
				pozMax_b = i;
			}
		}

		// ����� ������������ ��������� ������� � ������� ��������
		cout << endl << "Max a: " << a[pozMax_a] << endl;
		cout << "Max b: " << b[pozMax_b] << endl << endl;

		// ����� ������������� ���������� �������� ����� �����
		int temp;
		temp = a[pozMax_a];
		a[pozMax_a] = b[pozMax_b];
		b[pozMax_b] = temp;

		// ����� ������� ������� 
		for (size_t i = 0; i < size; i++)
		{
			cout << a[i] << " ";
		}

		cout << endl;

		// ����� ������� ������� 
		for (size_t i = 0; i < size; i++)
		{
			cout << b[i] << " ";
		}

		cout << endl;
	}

	if (num == 5)
	{
		cout << "                 The task 5                 " << endl << endl;
		// 5. ������������ ������ 2 ������� �� 4 ����� ������. ��������� ������ ������� ��� �������� ����� �������� ���,
		// ��� � ������ ������� ����� �������� ������� ������� � ��������.

		const int size = 4;

		int a[size], b[size];

		// ���� ������� ������� 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> a[i];
		}

		cout << endl;

		// ���� ������� ������� 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> b[i];
		}

		cout << endl;

		// ����� ������� �������
		for (size_t i = 0; i < size; i++)
		{
			cout << a[i] << " ";
		}

		cout << endl;

		// ����� ������� ������� 
		for (size_t i = 0; i < size; i++)
		{
			cout << b[i] << " ";
		}

		cout << endl << endl;
		// �������� ����������� ��� �������� ������������� ������
		int temp;

		// ����� ����������� ����� ���������
		for (size_t i = 0; i < size; i++)
		{
			temp = a[i];
			a[i] = b[i];
			b[i] = temp;
		}

		// ����� ������� ��������
		for (size_t i = 0; i < size; i++)
		{
			cout << a[i] << " ";
		}

		cout << endl;

		// ����� ������� �������
		for (size_t i = 0; i < size; i++)
		{
			cout << b[i] << " ";
		}

		cout << endl;

	}
	
}
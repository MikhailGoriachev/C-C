#include <iostream>

using namespace std;

void main()
{
	int num;
	cout << "--------------------------------------------" << endl << endl;
	cout << "Enter the task number : ";
	cin >> num;
	cout << endl << "--------------------------------------------" << endl << endl;

	if (num == 1)
	{
		cout << "                 The task 1                 " << endl << endl;

		// 1. ������������ ������ �����, ��������� ����������, �������� �� ��� �������
		// (������� ��� ������� ������ �� ���� � �� 1, �������: 2, 3, 5, 7, 11, 13, 17, 19)

		int n, res = 0, a;

		cout << "Enter num: ";
		cin >> n;

		if (n < 2)
		{
			res++;
		}
		else if (n > 2)
		{
			int i = 2;
			do
			{
				// ���������� ������� �����  
				if (n % i == 0)
				{
					res++;
					break;
				}

				i++;

			} while (i < n / 2);
		}

		cout << endl;

		if (res == 0)		
			cout << "Yes " << n << endl;
		else cout << "No " << n << endl;
	}
	
	if (num == 2)
	{
		cout << "                 The task 2                 " << endl << endl;

		// 2. ������������ ������ 5 �����, ��������� ������� ���������� ������� �����

		// ���������� �������� �����
		const int size = 5;

		int n, quan = 0, a = 0;

		for (size_t i = 0; i < size; i++)
		{
			// ������������ ������ �����
			cout << "Enter num: ";
			cin >> n;

			// ���� ����� ��������� ����, �� ��� ������� �����
			if (n == 2)
				quan++;

			// ���� ����� ������ ����, �� ���� �������� �� �������� ����� 
			if (n > 2)
			{
				int i = 2;

				do
				{
					// ���� ����� �������� ��� ������� �� ����� ����� ����������,
					// �� ��� �� ������� �����
					if (n % i == 0)
					{
						a++;
						break;
					}

					i++;

				} while (i < n / 2);

				if (a == 0)
					quan++;
				a = 0;
			}
		}

		cout << endl;

		cout << "Quantity prime number: " << quan << endl;
	}

	if (num == 3)
	{
		cout << "                 The task 3                 " << endl << endl;

		// 3. ������������ ������ �����, ���� �� ����� 0, 
		// ��������� ������� ���������� � ����� ������� 
		// �����(while, do..while, for, for + break)

		int n = 1, sum = 0, quan = 0;

		// while

		while (n != 0)
		{
			cout << "Enter num: ";
			cin >> n;

			if (n != 0) 
			{
				int a = 0;
				int i = 2;

				// ���� ��������� ����� ������ ����, �� ��� �� ������� 
				if (n < 2)
						a++;

				// ���� ��������� ����� ������ ����, �� ��� ����������� 
				// �� �������� 
				while (i < n)
				{
					if (n % i == 0)
						a++;
					i++;
				}
				
				// ���� ����� ��������� �������, �� ��������� �����
				// � ���������� ������� �����
				if (a == 0)
				{
					quan++;
					sum += n;
				}
			}
		}
		
		// do ... while

		/*do
		{
			cout << "Enter num: ";
			cin >> n;
			
			int a = 0, i = 2;

			if (n < 2)
				a++;

			else if (n > i)
			{
				do
				{
					if (n % i == 0)
						a++;
					i++;
				} while (i < n);
			}

			if (a == 0)
			{
				quan++;
				sum += n;
			}
		} while (n != 0);*/

		// for

		/*for (size_t i = 2; n != 0;)
		{
			cout << "Enter num: ";
			cin >> n;

			int a = 0;

			if (n < 2)
				a++;

			else if (n > i)
			{
				for (size_t i = 2; i < n; i++)
				{
				if (n % i == 0)
					a++;
				}
			}

			if (a == 0)
			{
				quan++;
				sum += n;
			}
		}*/

		// for + break

		/*for (;;)
		{
			cout << "Enter num: ";
			cin >> n;

			if (n == 0)
				break;
			int a = 0;

			if (n < 2)
			{
				a++;
			}

			if (n > 2)
			{
				for (size_t i = 2; i < n; i++)
				{
					if (n % i == 0)
					{
						a++;
					}
				}
			}

			if (a == 0)
			{
				quan++;
				sum += n;
			}

		}*/

		cout << endl << endl << "Sum prime number: " << sum << endl;
		cout << "Quantity prime number: " << quan << endl << endl;
	}

	if (num == 4)
	{
		cout << "                 The task 4                 " << endl << endl;

		// 4. ������������ ������ �����, ���� �� ����� 0, 
		// ��������� ������� ������������ ������������� ����� 
		// � ������� ��� �� �����(while, do..while, for, for + break)

		int n = 1, min = 0;
		

		// while
		while (n != 0)
		{
			cout << "Enter num: ";
			cin >> n;

			if (n < 0 && n < min)
				min = n;
		}

		// do ... while
		/*do
		{
			cout << "Enter num: ";
			cin >> n;

			if (n < 0 && n < min)
				min = n;

		} while (n != 0);
		*/

		// for	
		/*for (; n != 0;)
		{
			cout << "Enter num: ";
			cin >> n;

			if (n < 0 && n < min)
				min = n;
		}*/


		// for + break

		/*for (;;)
		{
			cout << "Enter num: ";
			cin >> n;

			if (n == 0)
				break;

			if (n < 0 && n < min)
				min = n;
		}*/

		cout << endl;

		if (min == 0)
			cout << "No negative numbers!" << endl;
		else
			cout << "Min negativ num: " << min;
	}
}
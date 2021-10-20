#include <iostream>
#include <time.h>

using namespace std;


void main()
{
	srand(time(0));

	while (true)
	{
		int num;
		cout << endl << "--------------------------------------------" << endl << endl;
		cout << "Enter the task number (0 = exit): ";
		cin >> num;
		cout << endl << "--------------------------------------------" << endl << endl;
		// ---------------------- parameters for entering the task number
		if (num == 0)
			break;
		if (num < 1)
		{
			cout << "Error! Pleace, enter the correct number." << endl << endl;
			continue;
		}
		// --------------------------------------------------------------

		if (num == 1)
		{
			// 1. ������������ ������ ������ 3�3, ��������� 
			// ������ ������� 1 ������ � ��������� ������� �������

			const int sizeY = 3, sizeX = 3;

			int a[sizeY][sizeX];
			
			// ���� �������
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << "Enter a[" << i << "][" << k << "]: ";
					cin >> a[i][k];
				}
				cout << endl;
			}

			cout << endl << endl;

			// ����� ������� 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl << endl;

			// ��������� ������ ������ ������ � ��������� ������� �������
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					int temp = a[0][k];
					a[0][k] = a[i][sizeX - 1];
					a[i][sizeX - 1] = temp;
				}
			}

			// ����� ������� 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}
		}

		if (num == 2)
		{
			// 2. ������������ ������ ������ 3�4, ��������� 
			// ������������ ���������� ������������� 
			// ������������� ���������

			const int sizeY = 3, sizeX = 4;

			int a[sizeY][sizeX];

			// ���� ������� 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << "Enter a[" << i << "][" << k << "]: ";
					cin >> a[i][k];
				}
				cout << endl;
			}

			// ����� ������� 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}

			int count = 0;

			// ��������� ������� ������������� �����
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					for (size_t m = 0; m < sizeY; m++)
					{
						for (size_t n = 0; n < sizeX; n++)
						{
							if (m == i && n == k)
								goto end;
							if (a[i][k] == a[m][n] && a[i][k] > 0)
							{
								count++;
								goto end;
							}
						}
					}
				end:;
				}
			}

			// ����� ���������� 
			cout << "Count = " << count << endl;
		}

		if (num == 3)
		{
			// 3. ������������ ������ ������ 3�4, ��������� 
			// ������ ��� ������� ����� � ������� �� ��������� 
			// �� ������� �����

			const int sizeY = 3, sizeX = 4;

			int a[sizeY][sizeX];

			// ���� ������� 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << "Enter a[" << i << "][" << k << "]: ";
					cin >> a[i][k];
				}
				cout << endl;
			}

			// ����� ������� 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}


			// ������ ������� ����� �� ���������
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					if (a[i][k] < 2)
						continue;

					bool flag = true;

					if (a[i][k] == 2)
					{
						a[i][k]--;
						continue;
					}

					for (size_t n = 2; n < (a[i][k] / 2 + 1); n++)
					{
						if (a[i][k] % n == 0)
							flag = false;
					}

					if (flag)
						a[i][k]++;
				}
			}

			cout << endl;

			// ����� ������� 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}
		}

		if (num == 4)
		{
			// 4. ������������ ������ 2 ������� 3�4, 
			// ��������� ��������� ����� �� ��� �����������

			const int sizeY = 3, sizeX = 4;

			int a[sizeY][sizeX], b[sizeY][sizeX];

			bool res = true;

			// ���� ������� ������� 
			cout << "Array A" << endl;
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << "Enter a[" << i << "][" << k << "]: ";
					cin >> a[i][k];
				}
			}

			cout << endl;

			// ���� ������� ������� 
			cout << "Array B" << endl;
			for (size_t i = 0, flag = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << "Enter b[" << i << "][" << k << "]: ";
					cin >> b[i][k];

					// �������� �� �������� ��������� 
					if (flag == 0 && a[i][k] != b[i][k])
					{
						res = false;
						flag++;
					}
				}
			}

			cout << endl;

			// ����� ������� ������� 
			cout << "Array A" << endl;
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl;

			// ����� ������� ������� 
			cout << "Array B" << endl;
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << b[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl << endl;

			// ����� ����������
			if (res == true)
				cout << "Yes!" << endl;
			else
				cout << "No!" << endl;
		}

		if (num == 5)
		{
			// 5. ������������ ������ �������� ��������� �����, ���������
			// ��������� ������ 5�4 ���������������� ���������� ������� 
			// � �������� �� 0 ��� ����� � �������, ������� ������ ��������
			// �������� ����� � ������� � ������� ������ �� �����.

			const int sizeY = 5, sizeX = 4;

			int a[sizeY][sizeX], max, min;

			// ���� ��������� ��������� �����
			do
			{
				cout << "Max number: ";
				cin >> max;

				cout << "Min number: ";
				cin >> min;

				// �������� �� ������������ ���������� ��������� 
				if (max <= min)
				{
					cout << endl << "Error, MAX < MIN! Enter agin!" << endl << endl;
				}
			} while (max <= min);


			// ���������� ������� ���������� ������� � ����������� �������� ��������� 
			int sum = 0;
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					a[i][k] = rand() % (max - min + 1) + min;
					sum += a[i][k];
				}
			}

			cout << endl;

			// ����� ������� 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl;

			// ��������� ��������� ������� �������������� �������� ��������� ������� 
			int avg = sum / (sizeY * sizeX);

			// ����� �������� ��������������� �������� 
			cout << "Average: " << avg;

			cout << endl;

			// ��������� �������� ��� �������� ��������� �������, ������� ������ 
			// �������� �������� �� 0 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					if (a[i][k] < avg)
						a[i][k] = 0;
				}
			}

			cout << endl;

			// ����� ������� 
			for (size_t i = 0; i < sizeY; i++)
			{
				for (size_t k = 0; k < sizeX; k++)
				{
					cout << a[i][k] << " ";
				}
				cout << endl;
			}

			cout << endl;
		}
	}
}
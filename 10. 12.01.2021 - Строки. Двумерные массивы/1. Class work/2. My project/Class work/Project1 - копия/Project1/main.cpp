#include <iostream>


using namespace std;

void main()
{
	/*int a[3][4], b[4][3];

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cin >> a[i][k];
		}
	}

	cout << endl;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	// n - ����� ������ � �������������� �������
	// m - ����� ������� � ������������� �������
	int m = 2;
	int n = 0;
	for (size_t i = 0; i < 3; i++, m--, n = 0)
	{
		for (size_t k = 0; k < 4; k++, n++)
		{
			b[n][m] = a[i][k];
		}
	}
	 
	cout << endl;

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t k = 0; k < 3; k++)
		{
			cout << b[i][k] << " ";
		}
		cout << endl;
	}*/

	// ������������ ������ ������� 3�4 � ���� �����, 
	// ��������� ��������, ������� ��� ��� ����� �����������
	// � �������

	/*const int sizeY = 3, sizeX = 4;

	int a[sizeY][sizeX], n;

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
		}
	}

	cout << endl;
	
	cout << "Enter num: ";
	cin >> n;

	cout << endl;

	int res = 0;
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			if (a[i][k] == n)
				res++;

			cout << a[i][k] << " ";
		}
		cout << endl;
	}

	cout << endl;

	cout << "Count = " << res << endl;*/


	// ������������ ������ ������� 3�4, ��������� �������� ��� ��������������
	// � ������� ����� �� ���� � ������� ������� �� �����

	/*const int sizeY = 3, sizeX = 4;

	int a[sizeY][sizeX];

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
		}
	}

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}

	cout << endl;

	// ����� �� ���� ��������� ���������� ������� 
	for (int i = 0; i < sizeY; i++)
	{
		for (int k = 0; k < sizeX; k++)
		{
			// ����� �� ����������� ��������� ���������� �������
			for (int n = 0; n < sizeY; n++)
			{
				for (int m = 0; m < sizeX; m++)
				{
					// ���� ��� �������� ��������� ������ ��������� �������,
					// � ������� ���������� ���������, �� ���������� �������� �
					// �������� ����������� �������
					if (i == n && k == m)
						// ������� �� �����
						goto end;

					cout << "-- " << a[n][m] << endl;
					if (a[i][k] == a[n][m])
						a[i][k] = 0;							
				}
			}

		end:	// �����
			cout << a[i][k] << endl;
		}
	}


	cout << endl;
	
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	*/
}
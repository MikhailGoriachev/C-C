#include <iostream>
#include <time.h>
using namespace std;


// ��������� ������
void main()
{
	srand(time(0));

	// const int sizeY = 2;
	// const int sizeX = 3;

	// ������������� �������� ������ �������
	// int a[sizeY][sizeX] = { {1, 2, 3}, {4, 5, 6} };

	// ������������� �������� ������ ������� 
	// int a[sizeY][sizeX] = { 1, 2, 3, 4, 5, 6 };

	// ���� � ����������
	/*for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
		}
	}*/

	/*const int sizeY = 3;
	const int sizeX = 5;

	int a[sizeY][sizeX];



	// ���������� ���������� �������
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			a[i][k] = rand() % 10;
		}
	}

	// �������������� �����
	int sum = 0;
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
			sum += a[i][k];
		}
		cout << endl;
	}

	cout << "Sum = " << sum << endl;*/

	// ������������ ������ ������ 3�3, ��������� 
	// ������������ ������������ ������� ���������

	/*const int sizeY = 3;
	const int sizeX = 3;

	int a[sizeY][sizeX];

	int pro = 0;

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
		}
	}

	pro = a[0][0] * a[0][sizeX - 1] * a[sizeY - 1][0] * a[sizeY - 1][sizeX - 1];

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}

	cout << "Pro = " << pro << endl;*/

	// ������������ ������ ������ 3�3, ��������� 
	// ������������ ������������ ����������
	// ������, ��������, ������������� � �������������

	/*const int sizeY = 3;
	const int sizeX = 3;

	int a[sizeY][sizeX];

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
		}
	}

	cout << endl;
	int odd = 0, even = 0, pos = 0, neg = 0;

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{

			
			if (a[i][k] < 0) neg++;
			if (a[i][k] > 0) pos++;
			if (a[i][k] % 2 == 0 && a[i][k] != 0) even++;
			if (a[i][k] % 2 == 1) odd++;
			
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
	cout << "Odd = " << odd << endl;
	cout << "Even = " << even << endl;
	cout << "Pos = " << pos << endl;
	cout << "Neg = " << neg << endl;
	*/

	// ������������ ������ ������ 3�3, ��������� 
	// ������������ ������������ ����������
	// �����, �������, �������

	/*const int sizeY = 3;
	const int sizeX = 3;

	int a[sizeY][sizeX];

	int three = 0, five = 0, seven = 0;

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
			
			switch (a[i][k])
			{
			case 3:
				three++;
				break;
			case 5:
				five++;
				break;
			case 7:
				seven++;
				break;
			default:
				break;
			}
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

	cout << "Three = " << three << endl;
	cout << "Five = " << five << endl;
	cout << "Seven = " << seven << endl;
	*/
	
	// ������������ ������ ������ 3�5, ��������� 
	// ������ ������ � ��������� ������ �������

	/*const int sizeY = 3, sizeX = 5;

	int a[sizeY][sizeX];

	// ���� �������
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
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
	cout << endl;

	// �������� ������� ��� ���������� �������� ������
	int temp[5];
	
	// ����� ��������
	for (size_t k = 0; k < sizeX; k++)
	{
		temp[k] = a[0][k];
		a[0][k] = a[sizeY - 1][k];
		a[sizeY - 1][k] = temp[k];

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
	*/

	// ������������ ������ ������ �� 9 ���������, 
	// ��������� �������� ��� �������� ����� ������� 
	// � ������ 3�3 � �������� ������� 
	/*const int sizeY = 3, sizeX = 3, size = 9;

	int a[size], b[sizeY][sizeX];

	// ���� ����������� ������� 
	for (size_t i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	// ����� ����������� ������� 
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// �����������
	int x = 8;
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			b[i][k] = a[x--];
		}
	}

	cout << endl;


	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cout << b[i][k] << " ";
		}
		cout << endl;
	}
	*/

	// ������������ ������ ��������� ������ �� 2�4 ���������, 
	// ��������� �������� ��� �������� ����� ������� 
	// � ���������� ������

	/*const int size = 8, sizeY = 2, sizeX = 4;

	int a[sizeY][sizeX], b[size];
	
	// ���� ��������� ������� 
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			cin >> a[i][k];
		}
	}
	
	// ����������� � ����� ���������� �������
	for (size_t i = 0, j = 0; i < sizeY; i++)
	{
		for (size_t k = 0; k < sizeX; k++)
		{
			b[j++] = a[i][k];
			cout << a[i][k] << " ";
		}
		cout << endl;
	}

	// ����� ����������� �������
	for (size_t i = 0; i < size; i++)
	{
		cout << b[i] << " ";
	}*/

	// ������������ ������ ��������� ������ �� 3�4 ���������, 
	// ��������� �������� ��� ������ �������� ����� ������� 
	// � ���������� ������ B, � �������� � ���������� ������ C

	const int sizeY = 3, sizeX = 4, size = 12;

	int a[sizeY][sizeX], even[size], odd[size], ceven = 0, codd = 0;

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
			if (a[i][k] % 2 == 0)
			{
				odd[codd] = a[i][k];
				codd++;
			}
			else if (a[i][k] != 0)
			{
				even[ceven] = a[i][k];
				ceven++;
			}
		}
	}
	cout << "Odd: ";
	for (size_t i = 0; i < codd; i++)
	{

		cout << odd[i] << " ";
	}
	cout << endl;
	cout << "Even: ";
	for (size_t i = 0; i < ceven; i++)
	{
		cout << even[i] << " ";
	}
	cout << endl;


}
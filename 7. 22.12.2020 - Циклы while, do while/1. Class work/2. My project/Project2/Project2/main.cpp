#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	srand(time(0));

	// ������� ����� � ��������� �� 0 �� 4
	/*int i = 0;
	while (i < 5)
	{
		cout << "i = " << i << endl;
		i++;
	} */

	// ������� �����, ���� �� ������ 0, ��������� ����� ��������� �����

	// � ������� while
	/*int sum = 0, a = 1;
	while (a != 0)
	{
		cin >> a;
		sum += a;
	}

	cout << "sum = " << sum << endl;*/

	// � ������� for

	/*int sum = 0, a;

	for (size_t a = 1; a != 0;)
	{
		cin >> a;
		sum += a;
	}

	cout << "sum = " << sum << endl;*/

	// ������������ ������ �����, ���� �� ������������ 
	// ������ 20 ��������� ������������ ������������ � ����� 
	// ������������� ����� �� ���������

	//int a, pro = 1, npro = 1, nsum = 0;

	/*while (pro < 20)
	{
		cin >> a;
		pro *= a;
		if (pro < 20 && a < 0)
		{
			nsum += a;
			npro *= a;
		}
	}

	cout << "Sum = " << nsum << endl;
	cout << "Pro = " << npro << endl;*/

	/*for  (; pro < 20;)
	{
		cin >> a;
		pro *= a;
		if (pro < 20 && a < 0)
		{
			nsum += a;
			npro *= a;
		}
	}*/	

	// �� �� ����� ����� do
	/*do {
		cin >> a;
		pro *= a;
		if (pro < 20 && a < 0)
		{
			nsum += a;
			npro *= a;
		}
	} while (pro < 20);

	cout << "Sum = " << nsum << endl;
	cout << "Pro = " << npro << endl;*/

	// ����������� ������ �����, ���� ���������� �������� �����
	// ������ 5. ��������� ������������ ������������ ������ �����
	// while, do..while, for 

	/*int nnum, num, a, pro = 1;

	while (nnum < 5)
	{
		cin >> a;
		if (a % 2 == 1)
			nnum++;
		if (a % 2 == 0)
			pro *= a;
	}

	do
	{
		cin >> a;
		if (a % 2 == 1)
			nnum++;
		if (a % 2 == 0)
			pro *= a;
	} while (nnum < 5);

	for (;nnum < 5;)
	{
		cin >> a;
		if (a % 2 == 1)
			nnum++;
		if (a % 2 == 0)
			pro *= a;
	}
	cout << "Prod even: " << pro << endl;*/

	// ������������� ��������� ����� break
	/*int odd = 0, pro = 1, a;
	for (;;)
	{
		cin >> a;
		if (a % 2 == 1)
			odd++;
		if (a % 2 == 0)
			pro *= a;
		if (odd > 5)
			break;
	}*/
	
	// ������������ ������ ����� ���� �� ������ 0
	// ��������� ������������ ������� ������������� 
	// � ������� �����, 0 �� ���������
	// while, do while, for, for + break
	
	/*int a, n = 0, avg = 0, min, sum = 0;

	cin >> a;
	sum += a;
	if (a != 0)
		min = a;

	while (a != 0)
	{
		cin >> a;
		n++;
		sum += a;
		if (a < min && a != 0)
			min = a;
	}

	do
	{
		cin >> a;
		n++;
		sum += a;
		if (a < min && a != 0)
			min = a;
	} while (a != 0);


	for (; a != 0;)
	{
		cin >> a;
		n++;
		sum += a;
		if (a < min && a != 0)
			min = a;
	}

	for (;;)
	{
		cin >> a;
		if (a == 0)
			break;
		n++;
		sum += a;
		if (a < min && a != 0)
			min = a;

	}
	avg = sum / n;



	cout << "Avg = " << avg << endl;
	cout << "Min = " << min << endl;*/
}
#include <iostream>
#include <Windows.h>//��� ���� ����� �������� � ������� ������
using namespace std;

void main() 
{
	SetConsoleCP(1251);//��� ���� ����� �������� � ������� ������
	SetConsoleOutputCP(1251);//��� ���� ����� �������� � ������� ������

	// ������������ ������ 5 �����, ��������� ������� 
	// ������������ ������������� �����

	/*int n, max = 0;

	for (int i = 0; i < 5; i++)
	{
		cout << "N: ";
		cin >> n;
		// ��� ���� ������
		if (n < 0 && (max < n || max == 0))
			max = n;

		// ����� ���������� ������
		if (max == 0 && n < 0 || n > max)
			max = n;
		
		// ���� � - ������������� ����� � �� ���� ������������� ����� �� �����
		if (max == 0 && n < 0) 
			max = n;
		// ���� � - ������������� ����� � �������� ������  �
		if (n > max) 
			max = n;
	}
	if (max == 0) 
		cout << "NO";
	else 
		cout << "Result: " << max;
	*/

	/* ������������ ������ 5 �����, ��������� ����� "YES",
	���� ������� �������������� ���� ����� ������ 10,
	����� ��������� ����� "NO"*/

	/*float n = 0, sum = 0;

	for (int i = 1; i <= 5; i++)
	{
		cin >> n;
		sum += n;
	}

	float avg = sum / 5;
	cout << "AVG = " << avg;

	if(avg < 10)
		cout << "YES";
	else 
		cout << "NO";
	*/

	// ������������ ������ 5 �����, ���� ��� ��� �������������
	// �� ��������� ����� "YES", ����� ����� "NO"

	/*int n, n1 = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		if (n < 0)
			n1++;
	}

	if (n1 == 5)
		cout << "YES";
	else
		cout << "NO";*/

	// ������������ ������ 5 �����, ���� ��� ��� ��������
	// �� ��������� ����� "YES", ����� ����� "NO"
	/*int n, over = 0;

	for (int i = 0; i < 5; i++) 
	{
		cin >> n;
		if (n % 2 == 1)
			over++;
	}

	if (over == 5)
		cout << "YES";
	else
		cout << "NO";*/
	 

	// ������������ ������ 5 �����, ���� ��� ��� ���� � ������� �����������,
	// �� ��������� ����� "YES", ����� ����� "NO"

	/*int a, prev, n = 0;

	cin >> prev;

	for (int i = 0; i < 4; i++) // � ������ ������� �������� i < 5
	{
		cin >> a;
		//if (i == 0)
		//{
		//	prev = a; // ������ �������
		//}
		if (a > prev)
		{
			prev = a;
			n++;
		}
	}
	if (n == 4)
		cout << "YES";
	else
		cout << "NO";*/

	// ������������ ������ 5 �����, ���� ��� ��� ���� � ������� �������� 
	// � �������� ������� ������� �� ��������� ����� "YES", ����� ����� "NO"

	/*int a, n = 0, prev = 0;


	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (i == 0 && a % 2 == 0)
			prev = a;
		if (prev > a && a % 2 == 0) {
			prev = a;
			n++;
		}
	}
	if (n == 4)
		cout << "YES";
	else
		cout << "NO";*/

	// ������������ ������ 5 �����, ��������� ������������ ������� �������������� ������������
	// � ������������� �����
	
	int a, max, min;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (i == 0)
		{
			max = a;
			min = a;
		}
		if (a > max)
			max = a;
		if (a < min)
			min = a;		
	}
	float over = (max + min) / 2;

	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	cout << "Result: " << over;
}
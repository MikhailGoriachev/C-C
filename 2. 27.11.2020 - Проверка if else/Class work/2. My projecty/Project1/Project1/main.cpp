#include <iostream>

using namespace std;

void main() 
{
	/*int a, b, c;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	// ���� a == b � b == c
	if (a == b && b == c)
	{
		cout << "YES!" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}*/


	// ������������ ������ ������ �����. ���� ������ ��������� ����� � 2 ���� ������ �����������, �� ��������� ����� "YES", ����� "NO"
	/*int a, b, c, d;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter d: ";
	cin >> d;

	if (b == a * 2 && c == b * 2 && d == c * 2)		
		cout << "YES";
	else
		cout << "NO";*/

		// ������������ ������ ������ �����. ���� ���� �� ����� ������ �������������, �� ��������� ����� "YES", ����� "NO"
	/*int a, b, c;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	if (a < 0 || b < 0 || c < 0)
		cout << "YES";
	else
		cout << "NO"; 
	*/

			//���� FOR

	//����������� ����
	/*for (;;)
	{
		cout << "YES";
	}*/

	// for  (�������� ���������� � ������������ �� ��������; ������� ����������; ��������) 
	/*for (int i = 0; i <= 5; i++)
	{
		cout << i << endl;
	}
	*/

	// ������� �������� ������������ a+=2 ��� a-=2
	// �������� 
	/*for ( int a = 1; a <= 9; a = a+=2)
	{
		cout << a << endl;
	}
	*/

	/*for (int a = 3; a >= -2; a--)
	{
		cout << a << endl;
	}*/

	/*for (int i = 0; i < 3; i++)
	{
		cout << 1 << endl;
		cout << 0 << endl;
	}*/

	/*for (int i = 0; i <=6; i++)
	{
		if (i==4){}
		else cout << i << endl;
	}*/

	// ������������ ������ 5 ����� � ������ �������� ����� ������������ � �����  

	/*int sum = 0, a = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		sum = sum + a;
	}

	cout << "Sum = " << sum << endl;*/


	// ������� ������������ ���� �����
	/*int pro =1, a = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		if (a > 0)
		pro = pro * a;
	}

	cout << "Pro = " << pro << endl;*/

	// ������������ ������ 5 �����, ��������� ������������, ������� �� ���� ����� 
	// ������ 3 � ������ 5 
	
	/*int a = 0, b = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter num: ";
		cin >> a;
		if (a >= 3 && a <= 5)
		{
			b++;
		}
	}
	cout << b;*/

	// ������������ ������ 5 �����, ��������� ������������, ���������� �����, �������
	// � ������� 

	/*int n = 0, a = 0, b = 0, c = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter num: ";
		cin >> n;
		if (n == 3)
			a++;
		if (n == 5)
			b++;
		if (n == 7)
			c++;
	}
	cout << "3: " << a << endl;
	cout << "5: " << b << endl;
	cout << "7: " << c << endl;*/
	
	// ������������ ������ 5 �����, ��������� ������� ���������� ������ 
	// � �������� �����

	/*int n = 0, even = 0, odd = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "N: ";
		cin >> n;
		if (n % 2 == 0 && a != 0)
		{
			even++;
		}
		if (n % 2 == 1)
		{
			odd++;
		}
	}
	cout << "Even: " << even << endl;
	cout << "Odd: " << odd << endl;*/
	
	
}
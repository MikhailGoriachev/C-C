#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int num;
	cout << "Number task: ";
	cin >> num;

	if (num == 1)
	{
		// ������������ ������ ��� ������, �������� ���������� ������ ����� � ����� ������
		// � ������� ������ �� �����
		char a[40], b[40];

		cout << "A: ";
		cin.ignore();	// �������� ����� 
		cin.getline(a, 40);

		cout << "B: ";
		cin.getline(b, 40);

		int n = strlen(a);

		for (size_t k = 0, i = n; !(b[k] == 0); i++, k++)
		{
			a[i] = b[k];
			if (b[k + 1] == 0)
				a[i + 1] = 0;
		}

		cout << a << endl;
	}

	if (num == 2)
	{
		// ������������ ������ ������, ��������� ������� 
		// ������ ������ ������ � ������� � �� �����

		char a[40];

		cout << "Enter: ";
		cin.ignore();
		cin.getline(a, 40);

		int len = strlen(a);

		for (size_t i = 0; a[i] != 0; i++)
		{
			a[i] = a[i + 1];
		}

		cout << a << endl;
	}

	if (num == 3)
	{
		// ������������ ������ ������, ��������� ������� ��� ������� �� ����� �� ������
		// � ������� � �� �����

		char a[40];

		cout << "Enter: ";
		cin.ignore();
		cin.getline(a, 40);

		char b[40] = "AaEeIiOoUuYy";

		for (size_t i = 0, flag = 0; a[i] != 0; i++)
		{
			if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'y')

			for (size_t k = i; a[k] != 0; k++)
			{
				a[k] = a[k + 1];
			}
		}

		cout << a << endl;
	}

	if (num == 4)
	{
		// ������������ ������ ������, ��������� ������� ������ �������� ������
		// � ������� � �� �����

		char s[40];

		cin.ignore();
		cin.getline(s, 40);

		size_t n = strlen(s) / 2;

		for (size_t i = 0, k = n; i < n; i++, k++)
		{
			s[i] = s[k];
			if (s[k + 1] == 0)
				s[i + 1] = 0;
		}

		cout << s << endl;

	}

	if (num == 5)
	{
		// ����������� ������ ������, ��������� ������������� �
		// � ������� �� �����

		char a[40];

		cin.ignore();
		cin.getline(a, 40);

		int len = strlen(a);

		for (size_t i = 0, k = len - 1; i < len / 2; i++, k--)
		{
			swap(a[i], a[k]);
		}

		cout << a << endl;
	}
}
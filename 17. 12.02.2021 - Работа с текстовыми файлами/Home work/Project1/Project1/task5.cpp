#include <iostream>

using namespace std;

// ����������� ��� ������ �� �����
int day_number(int year, int mounth, int number, int mounth_numb[]);

// ������� ����� �������
int cmp_string(char** mount, char use_mount[]);

// ����� ���
void out_name(char a[]);

void task5()
{
	// 4. ������������ ������ ���� � ��������� [1800; 2100]. 
	// ��������� ��� ��������� ���� ���������� ���� ������.

	int year, number;
	char mounth[40];

	// ���� ����
	cout << "Enter year (1800 - 2100): ";
	cin >> year;

	/*if (year > 2100 || year < 1800)
	{
		cout << "ERROR";
		return;
	}*/

	// ���� ������
	cout << "Enter mounth: ";
	cin.ignore();
	cin.getline(mounth, 40);

	// ���� ����� 
	cout << "Enter number: ";
	cin >> number;

	// ������ � �����		  1			2		  3			4		  5
	//			     012345678901234567890123456789012345678901234567890123456
	char days[58] = "Monday Tuesday Wednesday Thursday Friday Saturday Sundey ";

	// �������� ����

	char** days_name = new char* [7];
	// �����������
	days_name[0] = &days[0];
	// �������
	days_name[1] = &days[7];
	// ����� 
	days_name[2] = &days[15];
	// �������
	days_name[3] = &days[25];
	// �������
	days_name[4] = &days[34];
	// �������
	days_name[5] = &days[41];
	// �����������
	days_name[6] = &days[50];

	//				  0        1         2         3         4         5         6         7         8  
	// ������         012345678901234567890123456789012345678901234567890123456789012345678901234567890123456
	char month[87] = "Jenuary February March April May June July August September October November December ";

	// �������� �������

	char** mounth_name = new char* [12];
	// ������
	mounth_name[0] = &month[0];
	// �������
	mounth_name[1] = &month[8];
	// ����
	mounth_name[2] = &month[17];
	// ������
	mounth_name[3] = &month[23];
	// ���
	mounth_name[4] = &month[29];
	// ����
	mounth_name[5] = &month[33];
	// ����
	mounth_name[6] = &month[38];
	// ������
	mounth_name[7] = &month[43];
	// ��������
	mounth_name[8] = &month[50];
	// �������
	mounth_name[9] = &month[60];
	// ������
	mounth_name[10] = &month[68];
	// �������
	mounth_name[11] = &month[77];

	// �������� ���������� ������ � � ���������� �������
	int number_mounth = cmp_string(mounth_name, mounth);

	if (number_mounth == 0)
	{
		cout << "ERROR" << endl;
		return;
	}

	// ���������� ���� � �������
	//						1   2   3   4   5   6   7   8   9  10  11  12
	int mounth_numb[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// ����������� ��� ������
	int day = day_number(year, number_mounth, number, mounth_numb);
	if (day == 0)
	{
		cout << "ERROR" << endl;
		return;
	}

	// ����� ����������
	cout << "Result: ";
	out_name(days_name[day - 1]);
	cout << " " << number << " ";
	out_name(mounth_name[number_mounth - 1]);
	cout << " " << year << endl;

	delete[] days_name, mounth_name;
}

// ����������� ��� ������ �� �����
int day_number(int year, int mounth, int number, int mounth_numb[])
{
	// ��������� ����
	int num_day = 3;
	int num_mounth = 1;
	int num_year = 1800;

	// ���� ����������� ����
	bool leap = false;

	// �������� �� 29 �������
	if (number == 29 && mounth == 2 && year / 100 * 100 == year && year / 100 * 100 % 400 == 1)
		return 0;
	if (number == 29 && mounth == 2 && year % 4 == 1)
		return 0;

	// ����������� ��� ������ 
	for (; num_year <= year; num_year++, num_day++)
	{
		// ���� ���� ������ �������, �� �� ���������� ������
		if (num_day == 8)
			num_day = 1;

		// ���� ��� �������� ��������� � ��������� �����
		if (num_year == year)
		{
			// ���� ��� ������� �� 4 ��� �������, �� �� ����������
			if (num_year % 4 == 0)
				leap = true;
			// ���� ��� �������� �����, �� ���� �� �� ������� �� 400, �� �� �� ����������
			if (num_year / 100 * 100 == num_year && num_year / 100 * 100 % 400 != 0)
				leap = false;

			// �������� �� �������
			for (int i = 0; i < mounth; i++)
			{
				for (int k = 0; k < mounth_numb[i]; k++, ++num_day)
				{
					if (1 == i && !leap && k == 27)
					{
						if (num_day == 7)
							num_day = 0;
						num_day++;
						break;
					}
					if (mounth - 1 == i && number - 1 == k)
						break;
					if (num_day == 7)
						num_day = 0;
				}
			}

			break;
		}

		// ���� ��� �������� �����, �� ���� �� �� ������� �� 400, �� �� �� ����������
		if (num_year / 100 * 100 == num_year && num_year / 100 * 100 % 400 != 0)
		{
			continue;
		}
		// ���� ��� ������� �� 4 ��� �������, �� �� ����������
		if (num_year % 4 == 0)
			num_day++;
		// ���� ���� ������ �������, �� �� ���������� ������
		if (num_day == 8)
			num_day = 1;
	}

	return num_day;
}

// ������� ����� �������
int cmp_string(char** mounth, char use_mounth[])
{
	bool res = true;
	size_t i = 0;

	// �������� ��������
	for (size_t i = 0; i < use_mounth[i] != 0; i++)
	{
		if (use_mounth[i] == ' ')
		{
			for (size_t k = 0; use_mounth[i - 1] != 0; k++)
			{
				swap(use_mounth[i], use_mounth[i + 1]);
			}
		}
	}

	// ���� ������� �����
	for (size_t i = 0; use_mounth != 0; i++)
	{
		if (use_mounth[i] <= '0' && use_mounth[i] >= '9')
			break;
		else
			if (i > 1) break;
			else
			{
				if (i < 2 && use_mounth[i + 1] == 0)
					return atoi(use_mounth);
			}
	}

	// ���� ��� �������
	for (; i < 12; i++)
	{
		res = true;
		for (size_t k = 0; mounth[i][k] != ' '; k++)
		{
			if (use_mounth[k] != mounth[i][k])
			{
				res = false;
				break;
			}
		}
		if (res)
			return i + 1;
	}

	return 0;
}

// ����� ��������
void out_name(char a[])
{
	for (size_t i = 0; a[i] != ' '; i++)
	{
		cout << a[i];
	}
}

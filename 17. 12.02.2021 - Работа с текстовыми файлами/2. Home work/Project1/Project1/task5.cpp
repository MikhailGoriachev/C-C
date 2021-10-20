#include <iostream>

using namespace std;

// определение дня недели по числу
int day_number(int year, int mounth, int number, int mounth_numb[]);

// сравние строк месяцев
int cmp_string(char** mount, char use_mount[]);

// вывод дня
void out_name(char a[]);

void task5()
{
	// 4. Пользователь вводит дату в диапазоне [1800; 2100]. 
	// Программа для введенной даты определяет день недели.

	int year, number;
	char mounth[40];

	// ввод года
	cout << "Enter year (1800 - 2100): ";
	cin >> year;

	/*if (year > 2100 || year < 1800)
	{
		cout << "ERROR";
		return;
	}*/

	// ввод месяца
	cout << "Enter mounth: ";
	cin.ignore();
	cin.getline(mounth, 40);

	// ввод числа 
	cout << "Enter number: ";
	cin >> number;

	// строка с днями		  1			2		  3			4		  5
	//			     012345678901234567890123456789012345678901234567890123456
	char days[58] = "Monday Tuesday Wednesday Thursday Friday Saturday Sundey ";

	// название дней

	char** days_name = new char* [7];
	// понедельник
	days_name[0] = &days[0];
	// вторник
	days_name[1] = &days[7];
	// среда 
	days_name[2] = &days[15];
	// четверг
	days_name[3] = &days[25];
	// пятница
	days_name[4] = &days[34];
	// суббота
	days_name[5] = &days[41];
	// воскресенье
	days_name[6] = &days[50];

	//				  0        1         2         3         4         5         6         7         8  
	// месяцы         012345678901234567890123456789012345678901234567890123456789012345678901234567890123456
	char month[87] = "Jenuary February March April May June July August September October November December ";

	// названия месяцев

	char** mounth_name = new char* [12];
	// январь
	mounth_name[0] = &month[0];
	// февраль
	mounth_name[1] = &month[8];
	// март
	mounth_name[2] = &month[17];
	// апрель
	mounth_name[3] = &month[23];
	// май
	mounth_name[4] = &month[29];
	// июнь
	mounth_name[5] = &month[33];
	// июль
	mounth_name[6] = &month[38];
	// август
	mounth_name[7] = &month[43];
	// сентябрь
	mounth_name[8] = &month[50];
	// октябрь
	mounth_name[9] = &month[60];
	// ноябрь
	mounth_name[10] = &month[68];
	// декабрь
	mounth_name[11] = &month[77];

	// сравение введенного месяца и с названиями месяцев
	int number_mounth = cmp_string(mounth_name, mounth);

	if (number_mounth == 0)
	{
		cout << "ERROR" << endl;
		return;
	}

	// количество дней в месяцах
	//						1   2   3   4   5   6   7   8   9  10  11  12
	int mounth_numb[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// определение дня недели
	int day = day_number(year, number_mounth, number, mounth_numb);
	if (day == 0)
	{
		cout << "ERROR" << endl;
		return;
	}

	// вывод результата
	cout << "Result: ";
	out_name(days_name[day - 1]);
	cout << " " << number << " ";
	out_name(mounth_name[number_mounth - 1]);
	cout << " " << year << endl;

	delete[] days_name, mounth_name;
}

// определение дня недели по числу
int day_number(int year, int mounth, int number, int mounth_numb[])
{
	// стратовая дата
	int num_day = 3;
	int num_mounth = 1;
	int num_year = 1800;

	// флаг високосного года
	bool leap = false;

	// проверка на 29 февраля
	if (number == 29 && mounth == 2 && year / 100 * 100 == year && year / 100 * 100 % 400 == 1)
		return 0;
	if (number == 29 && mounth == 2 && year % 4 == 1)
		return 0;

	// определение дня недели 
	for (; num_year <= year; num_year++, num_day++)
	{
		// если день недели фосьмой, то он становится первым
		if (num_day == 8)
			num_day = 1;

		// если год проверки совпадает с введенным годом
		if (num_year == year)
		{
			// если год делится на 4 без остатка, то он високосный
			if (num_year % 4 == 0)
				leap = true;
			// если год является сотым, то если он не делится на 400, то он не високосный
			if (num_year / 100 * 100 == num_year && num_year / 100 * 100 % 400 != 0)
				leap = false;

			// проверка по месяцам
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

		// если год является сотым, то если он не делится на 400, то он не високосный
		if (num_year / 100 * 100 == num_year && num_year / 100 * 100 % 400 != 0)
		{
			continue;
		}
		// если год делится на 4 без остатка, то он високосный
		if (num_year % 4 == 0)
			num_day++;
		// если день недели фосьмой, то он становится первым
		if (num_day == 8)
			num_day = 1;
	}

	return num_day;
}

// сравние строк месяцев
int cmp_string(char** mounth, char use_mounth[])
{
	bool res = true;
	size_t i = 0;

	// удаление пробелов
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

	// если введены цифры
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

	// если это символы
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

// вывод названия
void out_name(char a[])
{
	for (size_t i = 0; a[i] != ' '; i++)
	{
		cout << a[i];
	}
}

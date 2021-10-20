#include <iostream>

using namespace std;

void main()
{
	// использование continue

	/*for (size_t i = 0; i < 5; i++)
	{
		if (i == 3)
			continue;
		cout << i << endl;
	}*/

	// пользователь вводит числа, пока не введет 0,
	// программа подсчитывает количество, сумму и произведение 
	// нечётных чисел (использовать continue)

	/*int n, pro = 1, sum = 0, count = 0;

	do
	{
		cin >> n;

		if (n % 2 == 0)
			continue;

		count++;
		sum += n;
		pro *= n;

	} while (n != 0);

	cout << "Count: " << count << endl;
	cout << "Sum: " << sum << endl;
	cout << "Pro: " << pro << endl;*/

	// оператор swith
	// подсчет троек, пятерок, семерок и других чисел

	/*int a, n3 = 0, n5 = 0, n7 = 0, others = 0;
	for (size_t i = 0; i < 5; i++)
	{
		cin >> a;
		switch (a)
		{
		case 3:
			n3++;
			break;
		case 5:
			n5++;
			break;
		case 7:
			n7++;
			break;
		default:
			others++;
		}
	}
	cout << "n3 = " << n3 << endl;
	cout << "n5 = " << n5 << endl;
	cout << "n7 = " << n7 << endl;
	cout << "Other numbers = " << others << endl;*/


	// пользователь вводит числа до тех пор пока не введет 0, 
	// программа посчитывает количество и сумму четных, нечетных чисел 
	// и чисел, которые без остатка делятся на 3

	int n, nsum = 0, sum = 0, sum3 = 0, ncount = 0, count = 0, count3 = 0;

	do
	{
		cin >> n;		

		if (n == 0)
			break;

		switch (n % 2)
		{
		case 0:
			sum += n;
			count++;
			break;
		case 1:
			
			nsum += n;
			ncount++;
			break;
		}

		if (n % 3 == 0)
		{
			sum3 += n;
			count3++;
		}

		// с помощью тернарного оператора 
		count3 = (n % 3 == 0) ? count3 + 1 : count3;


	} while (true);

	cout << "Count pos: " << count << ", sum: " << sum << endl;
	cout << "Count neg: " << ncount << ", sum: " << nsum << endl;
	cout << "Count %3: " << count3 << ", sum: " << sum3 << endl;


}
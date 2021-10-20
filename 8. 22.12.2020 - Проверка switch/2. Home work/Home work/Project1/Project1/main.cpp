#include <iostream>

using namespace std;

void main()
{
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
			cout << "Eror! Pleace, enter the correct number." << endl << endl;
			continue;
		}
		// ---------------------------------------------------------


		if (num == 1)
		{
			cout << "                 The task 1                 " << endl << endl;

			// 1. Пользователь вводит координаты 4х точек на плоскости. 
			// Программа определяет, является ли эта фигура
			// прямоугольником, лежащим параллельно оси X.

			const int size = 2, x = 0, y = 1;

			bool res = false;

			int a[size], b[size], c[size], d[size];

			// ввод координат точек

			cout << "Enter A (x): ";
			cin >> a[x];
			cout << "Enter A (y): ";
			cin >> a[y];

			cout << "Enter B (x): ";
			cin >> b[x];
			cout << "Enter B (y): ";
			cin >> b[y];

			cout << "Enter C (x): ";
			cin >> c[x];
			cout << "Enter C (y): ";
			cin >> c[y];

			cout << "Enter D (x): ";
			cin >> d[x];
			cout << "Enter D (y): ";
			cin >> d[y];

			// проверка на соотношение сторон
			if (a[x] == b[x] && c[x] == c[x] && a[x] + b[x] != a[y] + d[y] && b[y] == c[y] && a[y] == d[y])
			{
				res = true;
			}

			if (res == true)
				cout << "ABCD - rectangle" << endl;
			else
				cout << "ABCD - NOT rectangle" << endl;
		}

		if (num == 2)
		{
			cout << "                 The task 2                 " << endl << endl;

			// 2. Пользователь вводит числа до тех пор, пока они идут в 
			// порядке возрастания, программа подсчитывает сумму этих
			// чисел(2, 45, 67, 78, 56)

			int n;

			cout << "Enter num: ";
			cin >> n;

			int sum = n;

			int temp = n - 1;

			while (true)
			{
				cout << "Enter num: ";
				cin >> n;


				sum += n;

				if (n <= temp)
					break;

				temp = n;
			} 

			cout << "Sum: " << sum << endl;
		}

		if (num == 3)
		{
			cout << "                 The task 3                 " << endl << endl;

			// 3. Пользователь вводит числа до тех пор, пока они являются 
			// простыми, программа подсчитывает количество нечётных
			// чисел среди введенных

			int count = 0, n;

			bool off = false;

			while (off == false)
			{
				cout << "Enter num: ";
				cin >> n;

				if (n == 2)
				{
					continue;
				}

				switch (n % 2)
				{
				case 1:
					count++;
					for (size_t i = 2; i < (n / 2) + 1; i++)
					{
						if (n % i == 0)
						{
							off = true;
							break;
						}
					}
					break;
				case -1:
					count++;
					break;
				case 0:
					off = true;
					break;
				}

				if (n < 2)
					break;
			}
			cout << "Count: " << count << endl;
		}

		if (num == 4)
		{
			cout << "                 The task 4                 " << endl << endl;

			// 4. Пользователь вводит массив из 7 чисел, программа
			// выясняет, есть ли в массиве повторяющиеся числа

			const int size = 7;

			int arr[size];

			bool res = false;
			

			// ввод массива 
			for (size_t i = 0; i < size; i++)
			{
				cout << "Enter arr[" << i << "]: ";
				cin >> arr[i];
			}

			cout << endl;
			// вывод массива 
			for (size_t i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}

			int k = 0;

			// проверка на равенство элементов массива между собой 
			for (size_t i = 0; i < size; i++)
			{
				for (int n = 0;n < size; n++)
				{
					if (k != n && arr[k] == arr[n])
					{
						res = true;
						break;
					}
				}
				if (res)
					break;
				k++;
			}

			// вывод результата 
			if (res)
				cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
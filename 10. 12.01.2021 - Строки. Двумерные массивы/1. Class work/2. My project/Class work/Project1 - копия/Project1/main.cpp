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
	// n - нмоер строки в результирующей матрице
	// m - номер столбца в реультируюшей матрице
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

	// пользователь вводит матрицу 3х4 и одно число, 
	// программа вы€сн€ет, сколько раз это число встречаетс€
	// в матрице

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


	// пользователь вводит матрицу 3х4, программа замен€ет все посвтор€ющиес€
	// в матрице числа на ноль и выводит матрицу на экран

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

	// циклы по всем элементам двумерного массива 
	for (int i = 0; i < sizeY; i++)
	{
		for (int k = 0; k < sizeX; k++)
		{
			// циклы по провер€емым элементам двумерного массива
			for (int n = 0; n < sizeY; n++)
			{
				for (int m = 0; m < sizeX; m++)
				{
					// если при проверке пвоженных циклах достигнут элемент,
					// с которым происходит сравнение, то прекратить проверку и
					// помен€ть провер€емый элемент
					if (i == n && k == m)
						// переход на метку
						goto end;

					cout << "-- " << a[n][m] << endl;
					if (a[i][k] == a[n][m])
						a[i][k] = 0;							
				}
			}

		end:	// метка
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
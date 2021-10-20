#include <iostream>

using namespace std;

int main()
{
	int num;
	cout << "--------------------------------------------" << endl << endl;
	cout << "Enter the task number : ";
	cin >> num;
	cout << endl << "--------------------------------------------" << endl << endl;
	if (num == 1)
	{
		cout << "                 The task 1                 " << endl << endl;
		// 1. Пользователь вводит массив из 5 чисел.Программа увеличивает положителные числа в массиве в 2 раза и
		// уменьшает отрицательные числа на 3.

		const int size = 5;

		int arr[size];

		// Ввод массива
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "] ";
			cin >> arr[i];
		}

		// Функция
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] > 0 && arr [i] != 0)
				arr[i] *= 2;
			else if (arr[i] != 0) arr[i] -= 3;
		}

		// Ввывод всех элементов массива
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

	}

	if (num == 2)
	{
		cout << "                 The task 2                 " << endl << endl;
		// 2. Пользователь вводит 2 массива из 4 чисел кажлый.Программа выясняет, равен ли 0 элемент первого массива сумме
		// элементов второго массива.
		
		const int size = 4;

		int a[size], b[size], n;
		// ввод первого массива 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> a[i];
		} 

		cout << endl;

		// ввод второго массива 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> b[i];
		}

		// обработка данных

		int sum = 0;

		for (size_t i = 0; i < size; i++)
		{
			sum += b[i];
		}

		// вывод результата
		if (a[0] == sum)
			cout << "YES!" << endl;
		else cout << "NO!" << endl;
	}

	if (num == 3)
	{
		cout << "                 The task 3                 " << endl << endl;
		// 3. Пользователь вводит 2 массива из 4 чисел кажлый. Программа копирует элементы из введенных массивов в третий
		// массив через один : 1 2 3 4, 5 6 7 8 -> 1 5 2 6 3 7 4 8
		const int sizeMax = 8, sizeMin = 4;
		
		int a[sizeMin], b[sizeMin], arr[sizeMax];

		// ввод первого массива 
		for (size_t i = 0; i < sizeMin; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> a[i];
		}

		cout << endl;

		for (size_t i = 0; i < sizeMin; i++)
		// ввод второго массива 
		{
			cout << "Enter [" << i << "]: ";
			cin >> b[i];
		}

		// вывод первого массива

		for (size_t i = 0; i < sizeMin; i++)
		{
			cout << a[i] << " ";
		}

		cout << endl;

		// вывод второго массива
		for (size_t i = 0; i < sizeMin; i++)
		{
			cout << b[i] << " ";
		}

		cout << endl;

		// смешивание двух массивов в один
		for (size_t i = 0, x = 0, r = 1; i < sizeMin; i++, x+=2, r+=2)
		{
			arr[x] = a[i];
			arr[r] = b[i];
		}

		// вывод третьего массива 
		for (size_t i = 0; i < sizeMax; i++)
		{
			cout << arr[i] << " ";
		}
		
		cout << endl;
	}

	if (num == 4)
	{
		cout << "                 The task 4                 " << endl << endl;
		// 4. Пользователь вводит 2 массива из 4 чисел каждый. Программа меняет местами минимальный элемент первого массива
		// и максимальный элемент второго массива

		const int size = 4;

		int a[size], b[size];

		// ввод первого массива 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> a[i];
		}

		cout << endl;

		// ввод второго массива 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> b[i];
		}

		int pozMax_a = 0, pozMax_b = 0;

		// вычисление максимального элемента массива в первом и вотором массивах
		for (size_t i = 0, max_a = 0, max_b = 0; i < size; i++)
		{
			if (a[i] > max_a)
			{ 
				max_a = a[i];
				pozMax_a = i;
			}
				
			if (b[i] > max_b)
			{
				max_b = b[i]; 
				pozMax_b = i;
			}
		}

		// вывод максимальных элементов первого и второго массивов
		cout << endl << "Max a: " << a[pozMax_a] << endl;
		cout << "Max b: " << b[pozMax_b] << endl << endl;

		// обмен максимальными элементами массивов между собой
		int temp;
		temp = a[pozMax_a];
		a[pozMax_a] = b[pozMax_b];
		b[pozMax_b] = temp;

		// вывод первого массива 
		for (size_t i = 0; i < size; i++)
		{
			cout << a[i] << " ";
		}

		cout << endl;

		// вывод второго массива 
		for (size_t i = 0; i < size; i++)
		{
			cout << b[i] << " ";
		}

		cout << endl;
	}

	if (num == 5)
	{
		cout << "                 The task 5                 " << endl << endl;
		// 5. Пользователь вводит 2 массива из 4 чисел кажлый. Программа меняет местами все элементы обоих массивов так,
		// что в первом массиве будут элементы второго массива и наоборот.

		const int size = 4;

		int a[size], b[size];

		// ввод первого массива 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> a[i];
		}

		cout << endl;

		// ввод второго массива 
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "]: ";
			cin >> b[i];
		}

		cout << endl;

		// вывод первого массива
		for (size_t i = 0; i < size; i++)
		{
			cout << a[i] << " ";
		}

		cout << endl;

		// вывод второго массива 
		for (size_t i = 0; i < size; i++)
		{
			cout << b[i] << " ";
		}

		cout << endl << endl;
		// создание перемменной для хранения промежуточных данных
		int temp;

		// обмен элемментами между массивами
		for (size_t i = 0; i < size; i++)
		{
			temp = a[i];
			a[i] = b[i];
			b[i] = temp;
		}

		// вывод первого массивов
		for (size_t i = 0; i < size; i++)
		{
			cout << a[i] << " ";
		}

		cout << endl;

		// вывод второго массива
		for (size_t i = 0; i < size; i++)
		{
			cout << b[i] << " ";
		}

		cout << endl;

	}
	
}
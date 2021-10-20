#include <iostream>

	// библиотека времени
#include <time.h>
using namespace std;

void main()
{
	// Рандомные числа
	// Случайные числа 

	// время, инициализировать только один раз, нужно инициализировать 
	// за передлами цикла
	/*srand(time(0));


	int a, b;

	cout << "Enter min random number: ";
	cin >> a;

	cout << "Enter max random number: ";
	cin >> b;

	// формула диапазона "случайных" чисел 

	for (size_t i = 0; i < 20; i++)
	{
		cout << rand() % (a - b + 1) + a << endl;
	}
	*/

	// пользователь вводит количество случайных чисел и их
	// диапазон. Программа пишет на экран сами числа и вычисляет
	// их среднее арифсметическое 

	/*srand(time(0));

	int col, max, min, avg, temp; 
	float sum = 0;

	cout << "Col: ";
	cin >> col;

	cout << "Max: ";
	cin >> max; 

	cout << "Min: ";
	cin >> min;

	for (size_t i = 0; i < col; i++)
	{
		temp = rand() % (max - min + 1) + min;
		cout << temp << endl;
		sum += temp;
	}

	cout << "Result: " <<  sum / col << endl;*/

	// пользователь вводит диапазон случайныйх чисел, программа
	// заполняет массив из 10 чисел элементов слуйчайными числами
	// во введенном диапазоне и заменяет отрицательные элементы
	// массива на ноль

	/*int max, min;

	srand(time(0));

	cout << "Enter max:";
	cin >> max;

	cout << "Enter min:";
	cin >> min;

	const int size = 10;

	int arr[size];

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
		if (arr[i] < 0)
			arr[i] = 0;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}*/

	// пользователь вводит массив из 5 чисел, программа меняет местами 2 случайных
	// элемента этого массива и выводит на экран

	srand(time(0));

	const int size = 5;

	int arr[size], ranPoz_1, ranPoz_2;

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter [" << i << "]: ";
		cin >> arr[i];
	}

	cout << endl;

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	ranPoz_1 = rand() % 5;

	ranPoz_2 = rand() % 5;

	int temp; 
	temp = arr[ranPoz_1];
	arr[ranPoz_1] = arr[ranPoz_2];
	arr[ranPoz_2] = temp;


	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

}
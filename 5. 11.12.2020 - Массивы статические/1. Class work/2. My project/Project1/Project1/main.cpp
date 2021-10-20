#include <iostream>

using namespace std;

int main()
{
	// Пользователь вводит массив из 5 чисел,
	// программа "переворачивает" все числа в массиве
	// и выводит массив на экран 
	// 1 2 3 4 5 -> 5 4 3 2 1 

	/*const int size = 5;

	int arr[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter [" << i << "]:";
		cin >> arr[i];
	}

	// вывод массива до переворота
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	int temp;

	// переворот массива
	for (size_t i = 0; i < size/2; i++)
	{	
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}

	// вывод на экран
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}*/

	// пользователь вводит два массива
	// по четыре элемента каждый, программа 
	// объединяет их в один массив из 8 элементов
	// и выводит его на экран
	
	/*const int size1 = 4;
	const int size2 = 8;

	int arrMax[size2], arr1[size1], arr2[size1];

	// Ввод первого массива
	for (size_t i = 0; i < size1; i++)
	{
		cin >> arr1[i];
	}

	// Ввод второго массива
	for (size_t i = 0; i < size1; i++)
	{
		cin >> arr2[i];
	}

	// Заполнение третьего массива
	for (size_t i = 0; i < size1; i++)
	{
		arrMax[i] = arr1[i];
		arrMax[i+size1] = arr2[i];
	}

	// Вывод третьего массива на экран
	for (size_t i = 0; i < size2; i++)
	{
		cout << arrMax[i] << " ";
	}
	*/

	// пользователь вводит массив из 8
	// элементов, программа разделяет его на два 
	// по четыре элемента и выводит их на экран
	/*const int sizeMax = 8, sizeMin = 4;

	int aMax[sizeMax], a[sizeMin], b[sizeMin];

	for (size_t i = 0; i < sizeMax; i++)
	{
		cout << "Enter [" << i << "]:";
		cin >> aMax[i];
	}

	for (size_t i = 0; i < sizeMin; i++)
	{
		a[i] = aMax[i];
		b[i] = aMax[i + sizeMin];
	}

	for	(size_t i = 0; i < sizeMin; i++)
	{
		cout << a[i] << " ";
	}

	for	(size_t i = 0; i < sizeMin; i++)
	{
		cout << b[i] << " ";
	}*/
	

	// Пользователь вводит 2 массив из четырех
	// элементов каждый, программа проверяет равны
	// ли эти массивы друг другу поэлементно

	const int size = 4;

	int a[size], b[size], n = 0;

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter [" << i << "]: ";
		cin >> a[i];
	}

	cout << endl;

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter [" << i << "]: ";
		cin >> b[i];
	}

	cout << endl;

	for (size_t i = 0; i < size; i++)
	{
		if (a[i] == b[i])
			n++;
	}

	if (n == size)
		cout << "YES";
	else
		cout << "NO";
}
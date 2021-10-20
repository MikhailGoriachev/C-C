#include <iostream>

using namespace std;

void print_hello()
{
	cout << "Hello ";
}

void print_world()
{
	cout << "world!!!" << endl;
}

// вычисление суммы двух чисел
// тип функции название(первое входное значение, второе входное значение)
int sum(int a, int b)
{
	// int c = a + b;
	// return c;

	return a + b;
}

// функци€ находит среднее арифметическое если получает п€ть чисел
float avg(int a, int b, int c, int d, int e)
{
	return (float)(a + b + c + d + e) / 5.0f; // 5.0 - преводитс€ в double / 5.0f - переводитс€ в float
}

// функци€ находит среднее арифметическое если получает массив и длину 
float avg(int numbers[], size_t size)
{
	float result = 0;

	for (size_t i = 0; i < size; i++)
	{
		result += numbers[i];

	}

	return result / 5;
}

// функци€ находит маскимальное значение элемента
int array_max(int arr[], size_t size)
{
	// если длина массива равна нулю
	if (size == 0)
		return 0;

	int max = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}

// объ€вление функции 
int vowel(char a[], char b[], size_t size);

// функци€ переворота строки
void backstr(char a[], size_t size)
{
	int n = strlen(a);

	for (size_t i = 0; i < n / 2; i++)
	{
		swap(a[i], a[n - 1 - i]);
	}

}

// все фукции должны быть объ€вленны выше функции main

void main()
{
	// вызов функции
	/*print_hello();
	print_world();*/

	// int res = sum(3, 5);
	// cout << res << endl;

	/*cout << sum(3, 5) << endl;

	int n, m;
	cin >> n >> m;
	cout << "Sum = " << sum(n, m) << endl;*/

	// функци€ принимает п€ть чисел и возвращает их среднее
	// арифметическое 
	
	/*int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	int res = avg(a, b, c, d, e);

	cout << res << endl;*/
	
	// функци€ принимает 5 чисел и возвращает их среднее арифметическое 
	/*const int size = 5;
	int a[size];

	cout << "Enter " << size << " numbers" << endl;
	for (size_t i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	cout << "Avg: " << avg(a, size) << endl;*/

	// функци€ принимает массив чисел и возвращает масимальное 
	// число в массиве
	/*const int size = 5;

	int a[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter number: ";
		cin >> a[i];
	}

	cout << endl;

	int res = array_max(a, size);

	cout << "Max number: " << res << endl;*/

	// функци€ принимает две строки и взовращает общее количество гланых букв
	/*const int size = 40;

	char a[size], b[size];
	cout << "Enter A: ";
	cin.getline(a, size);

	cout << "Enter B: ";
	cin.getline(b, size);

	int res = vowel(a, b, size);

	cout << "Count vowel: " << res << endl;*/

	// функци€ принимает строку и переворачивает еЄ наоборот
	char a[40];

	cout << "Enter: ";
	cin.getline(a, 40);
	
	backstr(a, 40);

	cout << a << endl;
}

// функци€ 
int vowel(char a[], char b[], size_t size)
{
	char vow[40] = "AaEeYyUuOo";
	int count = 0;
	for (size_t i = 0; a[i] != 0; i++)
	{
		for (size_t k = 0; vow[k] != 0; k++)
		{
			if (a[i] == vow[k])
				count++;
		}
	}
	for (size_t i = 0; b[i] != 0; i++)
	{
		for (size_t k = 0; vow[k] != 0; k++)
		{
			if (b[i] == vow[k])
				count++;
		}
	}

	return count;
}

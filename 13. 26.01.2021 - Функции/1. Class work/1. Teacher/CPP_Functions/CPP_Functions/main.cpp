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
int sum(int a, int b)
{
	return a+b;
}

float avg(int a, int b, int c, int d, int e)
{
	return (float)(a + b + c + d + e) / 5.0f;
}

float avg(int numbers[], size_t size)
{
	float result = 0;

	for (size_t i = 0; i < size; i++)
	{
		result += numbers[i];
	}

	return result / 5;
}

int array_max(int numbers[], size_t size)
{
	if (size == 0)
		return 0;

	int result = numbers[0];

	for (size_t i = 0; i < size; i++)
	{
		if (result < numbers[i])
			result = numbers[i];
	}

	return result;
}

// объявление функции
int VowelsCount(char s1[], char s2[]);

void StrReverse(char s[])
{
	size_t size = strlen(s);

	for (size_t i = 0; i < size/2; i++)
	{
		char tmp = s[i];
		s[i] = s[size - i - 1];
		s[size - i - 1] = tmp;
	}
}

void main()
{
	/*print_hello();
	print_world();*/

	//int res = sum(3, 5);
	//cout << res << endl;

	/*cout << sum(3, 5) << endl;

	int n, m;
	cin >> n >> m;
	cout << "Sum = " << sum(n, m) << endl;*/

	// функция принимает 5 чисел и возвращает их среднее арифметическое
	//cout << avg(1, 2, 3, 4, 6) << endl;

	// функция принимает 5 чисел и возвращает их среднее арифметическое
	/*const int size = 5;

	int a[size];

	cout << "Enter " << size << " numbers:" << endl;
	for (size_t i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	cout << "Avg: " << avg(a, size) << endl;*/

	// функция принимает массив чисел и возвращает максимальное число в массиве
	/*const int size = 5;

	int a[size];

	cout << "Enter " << size << " numbers:" << endl;
	for (size_t i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	cout << "Max: " << array_max(a, size) << endl;*/

	// функция принимает 2 строки и возвращает общее колисчество гласных букв
	/*char s1[40], s2[40];
	cin >> s1 >> s2;
	cout << VowelsCount(s1, s2) << endl;*/

	// функция принимает строку и переворачивает её наоборот
	cout << "Enter a string: ";
	char s[40];
	cin.getline(s, 40);
	StrReverse(s);
	cout << s << endl;
}

int VowelsCount(char s[])
{
	int result = 0;

	for (size_t i = 0; i < strlen(s); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'y' || s[i] == 'u')
			result++;
	}

	return result;
}

int VowelsCount(char s1[], char s2[])
{
	int result = 0;

	result += VowelsCount(s1);
	result += VowelsCount(s2);

	return result;
}
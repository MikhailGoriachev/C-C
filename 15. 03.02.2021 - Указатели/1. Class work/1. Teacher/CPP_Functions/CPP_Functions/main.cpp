#include <iostream>
#include <time.h>

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

// ввод массива
void enterArray(int a[], size_t size);

// вычисление максимума в массиве
int maxArray(int a[], size_t size);

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

void printArray(char a[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

// конвертирование строки в число
int StrToInt(char s[])
{
	int result = 0;
	for (size_t i = 0; s[i]!=0; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += s[i] - '0';
		}
		else return 0;
	}
	return result;
}

double Calculate(char s[])
{
	double result = 0;
	bool isSecondNum = false;
	char s1[200], s2[200];
	size_t s1Size = 0, s2Size = 0;
	char op = '.';

	for (size_t i = 0; s[i]!=0; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			// обработка второго числа
			if (isSecondNum)
			{
				s2[s2Size++] = s[i];
			}
			else // обработка первого числа
			{
				s1[s1Size++] = s[i];
			}
		}
		else
		{
			if (!isSecondNum)
			{
				op = s[i];
				isSecondNum = true;
			}
			else return 0;
		}
	}
	s1[s1Size] = 0;
	s2[s2Size] = 0;
	long num1 = StrToInt(s1);
	long num2 = StrToInt(s2);

	switch (op)
	{
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			result = (double)num1 / num2;
			break;
		default:
			return 0;
	}
	
	return result;
}

void main()
{
	srand(time(0));

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
	/*cout << "Enter a string: ";
	char s[40];
	cin.getline(s, 40);
	StrReverse(s);
	cout << s << endl;*/

	// объявление функции
	//int min(int a, int b, int c);

	// 1. Функция принимает 3 числа и возвращает минимальное из них
	/*int a, b, c;
	cin >> a >> b >> c;
	cout << min(a, b, c) << endl;*/

	// 2. Функция принимает 2 массива и находит максимальное значение в двух массивах
	/*int twoArrayMax(int a[], size_t size1, int b[], size_t size2);

	const size_t size = 5;

	int a[size], b[size];

	cout << "Enter first array:" << endl;
	enterArray(a, size);

	cout << "Enter second array:" << endl;
	enterArray(b, size);

	cout << "Max element of both arrays: " << endl;
	cout << twoArrayMax(a, size, b, size) << endl;*/

	// 5. Функция принимает строку и после каждой гласной буквы вставляет '!'. "Hello" = > "He!llo!"

	/*void insertExlamationMark(char s[], size_t maxSize);

	const size_t size = 20;

	char str[size];

	cout << "Enter a string: ";
	cin >> str;

	insertExlamationMark(str, size);

	cout << "Result: " << str << endl;*/

	// функция принимает двумерный массив 3 строки, 4 столбца и заменяет все нечётные числа
	// на тройки (ввод, замена, вывод)
	/*void enter2DArray(int a[3][4]);
	void print2DArray(int a[3][4]);
	void replace2DArray(int a[3][4]);

	int a[3][4];

	enter2DArray(a);
	print2DArray(a);
	replace2DArray(a);
	print2DArray(a);*/

	// функция принимает двумерный массив символов 3 строки, 3 столбца и хаотично перемешивает символы
	// (ввод, перемешивание, вывод)
	
	void enter2DCharArray(char a[3][4]);
	void print2DCharArray(char a[3][4]);
	void shuffle2DCharArray(char a[3][3]);
	size_t copy2DCharArray(char a[3][4], char b[]);
	bool checkArrayChar(char b[], size_t size, char ch);

	/*char a[3][3];

	enter2DCharArray(a);
	print2DCharArray(a);
	shuffle2DCharArray(a);
	print2DCharArray(a);*/

	// 2. Функция принимает 2D-массив символов 3x4 и копирует в одномерный массив все символы без повторений
	/*char a[3][4];

	char b[12];

	enter2DCharArray(a);
	print2DCharArray(a);

	size_t resSize = copy2DCharArray(a, b);

	printArray(b, resSize);*/

	char expression[200];
	cin >> expression;
	cout << Calculate(expression) << endl;
}

void enter2DCharArray(char a[3][4])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cin >> a[i][k];
		}
	}
}

// проверка на вхождение символа в массив
bool checkArrayChar(char b[], size_t size, char ch)
{
	for (size_t i = 0; i < size; i++)
	{
		if (b[i] == ch)
			return true;
	}
	return false;
}

// копирование 2D-массива в одмонерный массив без повторений
size_t copy2DCharArray(char a[3][4], char b[])
{
	int resSize = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			// если текущий символ не входит в результирующий массив, то скопировать его туда
			if (!checkArrayChar(b, resSize, a[i][k]))
				b[resSize++] = a[i][k];
		}
	}
	return resSize;
}

void print2DCharArray(char a[3][4])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void shuffle2DCharArray(char a[3][3])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 3; k++)
		{
			int x = rand() % 3;
			int y = rand() % 3;
			int x2 = rand() % 3;
			int y2 = rand() % 3;
			
			char temp = a[y][x];
			a[y][x] = a[y2][x2];
			a[y2][x2] = temp;
		}
	}
}

void enter2DArray(int a[3][4])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cin >> a[i][k];
		}
	}
}

void print2DArray(int a[3][4])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void replace2DArray(int a[3][4])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 4; k++)
		{
			if (a[i][k] % 2 == 1)
				a[i][k] = 3;
		}
	}
}

void insertExlamationMark(char s[], size_t maxSize)
{
	size_t vowelsCount = 0;
	size_t letterCount = strlen(s);

	for (size_t i = 0; s[i]!=0; i++)
	{
		if (s[i] == 'a' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'y')
			vowelsCount++;
	}

	// проверка на выход за границу строки
	if ((letterCount + vowelsCount) >= maxSize)
		return;

	size_t addedSymbols = 0;
	for (size_t i = 0; i < (letterCount + vowelsCount); i++)
	{
		if (s[i] == 'a' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'y')
		{
			// сдвиг букв направо
			for (size_t k = letterCount + addedSymbols; k>i; k--)
			{
				s[k + 1] = s[k];
			}
			s[i + 1] = '!';
			addedSymbols++;
		}
	}
}

int twoArrayMax(int a[], size_t size1, int b[], size_t size2)
{
	int max1 = maxArray(a, size1);
	int max2 = maxArray(b, size2);

	if (max1 >= max2)
		return max1;

	return max2;
}

int maxArray(int a[], size_t size)
{
	if (size == 0)
		return 0;

	int max = a[0];
	for (size_t i = 1; i < size; i++)
	{
		if (max < a[i])
			max = a[i];
	}

	return max;
}

void enterArray(int a[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter element " << i << ": ";
		cin >> a[i];
	}
}

// 1. Функция принимает 3 числа и возвращает минимальное из них
int min(int a, int b, int c)
{
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
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
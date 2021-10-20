#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void f2(int i)
{
	cout << "i = " << i << endl;
	if (i > 1)
		f2(i - 1);
}

void f(int i)
{
	cout << "i = " << i << endl;
	if(i<5)
		f(i+1);
}

void PrintStr(const char* str, int i)
{
	cout << str[i] << endl;
	if (str[i])
		PrintStr(str, i + 1);
}

int Sum(int x)
{
	int result = x;
	if (x >= 1)
		result = result + Sum(x - 1);

	return result;
}

// Рекурсивная функция принимает число и выводит все нечётные числа от 1 и до этого числа
void PrintOdds2(int n, int c)
{
	if (c <= n)
	{
		if (c % 2)
			cout << c << endl;

		PrintOdds2(n, c + 1);
	}
}

void PrintOdds(int n)
{
	PrintOdds2(n, 1);
}

// Рекурсивная функция принимает 2 числа[a, b] и выводит диапазон чисел от[a; b]
void PrintRange(int a, int b, int current)
{
	if (current >= a && current <= b)
	{
		cout << current << endl;

		PrintRange(a, b, current + 1);
	}
}

// Рекурсивная функция принимает строку и возвращает количество букв 'a'
int CalcA(const char s[], int index)
{
	// если найдена последняя буква строки, то не вызывать рекурсию
	if (s[index] == 0)
		return 0;

	int result = 0;

	// если текущая буква равна 'a', то увеличить результат на 1
	if (s[index] == 'a')
		result++;

	// подсчитать рекурсивно количество букв 'a', начиная со следующей буквы
	result += CalcA(s, index + 1);

	return result;
}

// Рекурсивная функция принимает массив и его размер и находит максимум в массиве
int ArrayMax(int a[], size_t size, int index)
{
	// если index - это номер последнего элемента - то максимум - это последний элемент
	if (index == size - 1)
		return a[index];

	// вычислить максимум в массиве, начиная с элемента index+1
	int max = ArrayMax(a, size, index + 1);

	// определить, какой из элементов больше текущий или один из последующих
	if (max >= a[index])
		return max;
	else return a[index];
}

// Рекурсивная функция принимает 2 строки и выясняет, равны ли они друг другу
bool StringCmp(const char s[], const char s2[], int index)
{
	// если достигнут конец одной из строк
	if (s[index] == 0 || s2[index] == 0)
		return s[index] == s2[index];

	// рекурсивное сравнение символов, начиная со следущего
	bool result = StringCmp(s, s2, index + 1);

	// сравнение текущих символов
	if (s[index] != s2[index])
		result = false;

	return result;
}

// рекурсивная функция принимает строку и 2 символа и меняет все вхождения первого символа в строке на второй
void ReplaceLetter(char s[], char ch, char ch2, int index)
{
	if (s[index] == ch)
		s[index] = ch2;

	if (s[index] != 0)
		ReplaceLetter(s, ch, ch2, index+1);
}

void main()
{
	char str[100];
	strcpy_s(str, "Hello world");
	ReplaceLetter(str, 'e', '3', 0);

	cout << str << endl;

	cout << "End." << endl;
}
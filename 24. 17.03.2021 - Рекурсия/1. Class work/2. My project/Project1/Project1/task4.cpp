#include <iostream>

using namespace std;

void swapSymb(char* str, char* a, char* b)
{
	if (*str != 0)
	{
		if (*str == *a)
		{
			*str = *b;
		}
		swapSymb(str + 1, a, b);
	}
}

void task4()
{
	// рекурсивная функция принимает строку и 2 симовла 
	// и меняет все вхождения первого символа в строке на второй

	// строка 
	char* str = (char*)malloc(sizeof(char) * 40);

	// ввод строки
	cout << "Enter string: ";
	cin.ignore();
	cin.getline(str, 40);

	cout << endl;

	// первый символ
	char* a = (char*)malloc(sizeof(char));

	// второй символ
	char* b = (char*)malloc(sizeof(char));

	// ввод первого символа
	cout << "Enter first symbol: ";
	cin >> a;

	// ввод второго символа 
	cout << "Enter second symbol: ";
	cin >> b;

	// вызов функции замены
	swapSymb(str, a, b);

	// вывод строки
	cout << str << endl;
}
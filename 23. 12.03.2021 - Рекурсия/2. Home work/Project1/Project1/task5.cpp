#include <iostream>

using namespace std;

// сравнивание строк
bool stringCmp(char a[], char b[])
{
	if (*a == *b)
	{
		if (*a == 0)
			return true;
		bool res = stringCmp(a + 1, b + 1);
	}
	else return false;
}

void task5()
{
	// 5. –екурсивна€ функци€ принимает 2 строки и 
	// вы€сн€ет, равны ли они друг другу.

	// две строки
	char* a = (char*)malloc(sizeof(char) * 40);
	char* b = (char*)malloc(sizeof(char) * 40);

	// ввод первой сторки
	cout << "Enter first string: ";
	cin.ignore();
	cin.getline(a, 40);

	// ввод второй строки
	cout << "Enter second string: ";
	cin.getline(b, 40);

	// запуск функции
	if (stringCmp(a, b))
		cout << "Yes" << endl;
	else cout << "No" << endl;

	free(a);
	free(b);
}
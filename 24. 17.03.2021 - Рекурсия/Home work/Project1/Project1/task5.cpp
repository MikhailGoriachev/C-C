#include <iostream>

using namespace std;

void randMix(char* str, int len, int n)
{
	// если это не конец строки
	if (*(str + n))
	{
		int i = rand() % len;

		swap(*(str + n), *(str + i));

		randMix(str, len, n + 1);
	}
}

void task5()
{
	// 5. Рекурсивная функция принимает строку и хаотично 
	// перемешивает символы внутри строки

	srand(time(0));

	// строка 
	char* str = new char[40];

	// ввод строки
	cout << "Enter string:" << endl;
	cout << "> ";
	cin.ignore();
	cin.getline(str, 40);
	
	cout << endl;

	// длина строки
	int len = strlen(str);

	// перемешивание строки
	randMix(str, len, 0);

	// вывод результата
	cout << "Result" << endl;
	cout << "> " << str << endl;

	delete[] str;
}
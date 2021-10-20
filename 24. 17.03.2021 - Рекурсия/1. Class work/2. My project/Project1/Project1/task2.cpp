#include <iostream>

using namespace std;

// переворот строки
void swapString(char* string, size_t len, size_t i)
{
	if (i < len / 2 + 1)
	{
		// переворот строки
		swap(*string, *(string + len - 1 - i));
		swapString(string + 1, len - 1, i + 1);
	}
}

void task2()
{
	// переворот строки рекурсивно

	// строка 
	char* str = (char*)malloc(sizeof(char) * 40);
	
	// ввод строки
	cout << "Enter string: ";
	cin.ignore();
	cin.getline(str, 40);

	// длина введённой строки
	size_t len = strlen(str);

	// вызов функции
	swapString(str, len, 0);

	cout << "Result" << endl;

	// вывод строки
	cout << str << endl;

	free(str);
}
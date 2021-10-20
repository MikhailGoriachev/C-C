#include <iostream>

using namespace std;

void charOut(char* str)
{
	cout << *str++ << endl;
	if (*str)
		charOut(str);
}

void task4()
{
	// функция принимает строку и выводит её в столбик
	char* str = (char*)malloc(sizeof(char) * 40);

	cout << "Enter string: ";
	cin.ignore();
	cin.getline(str, 40);

	char* point = str;

	charOut(point);

	free(str);
}
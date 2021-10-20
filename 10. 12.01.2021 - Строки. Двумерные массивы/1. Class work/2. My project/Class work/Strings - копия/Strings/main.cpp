#include <iostream>

using namespace std;

void main()
{
	// первый способ
	/*char str[40];
	str[0] = 'H';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = 0;*/ // конец строки последний элемент равен 0

	// второй способ
	// char str[40] = {'H', 'e' , 'l', 'l', 'o'};

	// третий способ
	char str[40] = "Hello";
	char str2[40];

	// копироание строки str в str2
	strcpy_s(str2, str);

	cin >> str;
	cin >> str2;

	// сравнение строк 
	// strcmp -  если символы равны = 0, если первая строка идет раньше второй 
	// в алфавитном порядке = -1, если первая строка идет позже второй в 
	// алфавитном порядке = 1
	if (strcmp(str, str2) == 0)
		cout << "String are qual" << endl;

	else cout << "not equal";
	// выводит длину строки 
	// cout << strlen(str) << endl;

	cout << endl;
	cout << str << endl;
	cout << str2 << endl;
}
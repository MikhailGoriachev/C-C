#include <iostream>

using namespace std;

void main()
{
	/*char str[40];
	str[0] = 'H';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = 0;*/

	//char str[40] = {'H', 'e', 'l', 'l', 'o'};

	char str[40] = "Hello";
	char str2[40];
	cout << strlen(str) << endl;

	// копирование строки str в str2
	strcpy_s(str2, str);

	cin >> str;
	cin >> str2;

	//cout << strcmp(str, str2) << endl;

	// сравнение строк
	if (strcmp(str, str2) == 0)
		cout << "Strings are equal" << endl;
	else cout << "not equal";
	
	cout << str2 << endl;

	cout << str << endl;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

struct Person
{
	char name[40];
	int age;
};

void main()
{
	struct {
		char d;
		short c;
		int a;
		int b;
	}test;

	cout << sizeof(test) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(char) << endl;
}
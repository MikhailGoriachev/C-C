#include <iostream>

using namespace std;

void f(int i)
{
	cout << "i = " << i << endl;
	if(i<5)
		f(i+1);
}

void task2()
{
	f(1);
	cout << "End." << endl;
}
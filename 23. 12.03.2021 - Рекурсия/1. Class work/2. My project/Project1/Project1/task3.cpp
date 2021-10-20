#include <iostream>

using namespace std;

void d(int i)
{
	cout << "i = " << i << endl;
	if (i > 1)
	{
		d(i - 1);
	}
}

void task3()
{
	d(10);
	cout << "End." << endl;
}
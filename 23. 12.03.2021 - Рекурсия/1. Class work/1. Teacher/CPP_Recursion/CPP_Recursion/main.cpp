#include <iostream>

using namespace std;

void f2(int i)
{
	cout << "i = " << i << endl;
	if (i > 1)
		f2(i - 1);
}

void f(int i)
{
	cout << "i = " << i << endl;
	if(i<5)
		f(i+1);
}

void PrintStr(const char* str, int i)
{
	cout << str[i] << endl;
	if (str[i])
		PrintStr(str, i + 1);
}

int Sum(int x)
{
	int result = x;
	if (x >= 1)
		result = result + Sum(x - 1);

	return result;
}


void main()
{
	cout << Sum(3) << endl;
	cout << "End." << endl;
}
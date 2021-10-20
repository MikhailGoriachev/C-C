#include <iostream>

using namespace std;

// ����������� �� ������� �����
bool primeNumber(int* num, int n)
{
	if (*num % n != 0 && n != 0 && n <= (*num / 2))
	{
		if (primeNumber(num, ++n))
			return true;
	}
	else if (n > *num / 2 && *num > 1)
		return true;
	else return false;
}

// ���������� ������� ����� � �������
int countPrimeArr(int* arr, int size, int count)
{
	if (size > 0)
	{
		if (primeNumber(arr, 2))
			count++;
		count = countPrimeArr(arr + 1, size - 1, count);
	}

	return count;
}

// ���� �������
void enterArray(int* arr, int size)
{
	if (size > 0)
	{
		cout << "Enter element: ";
		cin >> *arr;

		enterArray(arr + 1, size - 1);
	}
}

void task1()
{
	// ������� ��������� ����� � �������� ������� �� ��� �����

	// ������ ������� 
	int size;

	// ���� ������� �������
	cout << "Enter size array: ";
	cin >> size;

	// ������
	//int* num = (int*)malloc(sizeof(int) * size);
	int* num = new int[size];

	// ���� �������
	enterArray(num, size);

	// ����� ������������� ���������� ������� �����
	cout << "Prime number: " << countPrimeArr(num, size, 0) << endl;
	
	delete[] num;
	//free(num);
}
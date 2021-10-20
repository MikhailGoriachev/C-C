#include <iostream>

using namespace std;

// ����� ������������� �����
int maxArray(int arr[], int size)
{
	if (size - 1 > 0)
	{
		int a = maxArray(arr + 1, --size);
		if (a > *arr)
			return a;
	}

	return *arr;
}

void task4()
{
	// 4. ����������� ������� ��������� ������ � ��� ������
	// � ������� �������� �������

	srand(time(0));

	// ������ �������
	int size;

	// ���� ������� �������
	cout << "Enter size array: ";
	cin >> size;

	cout << endl;

	// ������������� ������ ���������� �������
	int* arr = (int*)malloc(sizeof(int) * size);

	// ���������� ������� ���������� �������
	for (int* p_arr = arr; p_arr < arr + size; p_arr++)
	{
		*p_arr = rand() % (100 - 10) + 10;
	}

	// ����� �������
	for (int* p_arr = arr; p_arr < arr + size; p_arr++)
	{
		cout << *p_arr << " ";
	}

	cout << endl << endl;

	// ����� ������� � ����� ������������� ����� � �������
	cout << "Max: " << maxArray(arr, size) << endl;

	free(arr);
}
#include <iostream>
#include "head.h"

using namespace std;

void task1()
{
	// 1. ������������ ������ 2 ������, ��������� ������� ��� ��������� ������ ������ � ������
	// hello big big world
	//	big
	//
	//	hello   world

	// ������ ������
	char* str_a = (char*)malloc(sizeof(char) * 40);

	// ������ ������ 
	char* str_b = (char*)malloc(sizeof(char) * 40);

	// ���� ������ ������
	cout << "Enter first string: ";
	cin.ignore();
	cin.getline(str_a, 40);

	// ���� ������ ������
	cout << "Enter second string: ";
	cin.getline(str_b, 40);

	cout << endl;

	// ��������� �� ����� ������ ������
	long* len_a = (long*)malloc(sizeof(long));

	// ����� ������ ������	
	*len_a = strlen(str_a);

	// ����� ������ ������
	long* len_b = (long*)malloc(sizeof(long));

	// ��������� �� ����� ������ ������
	*len_b = strlen(str_b);

	// ���� ������ ������ ������ ������
	if (*len_a < *len_b)
	{
		cout << "The first string less than the second string!" << endl;
		return;
	}

	// ��������� �� ���������� ��������� ��������� ������ ������ � ������
	size_t* count = (size_t*)malloc(sizeof(size_t));

	*count = 0;

	// ������������ ������ ������ �� ������� � ��� ������ ������
	for (char* p_a = str_a; *(p_a + *len_b - 1) ; p_a++)
	{
		// ���� ���������� ��������
		bool flag = true;

		// ��������� ���������
		for (char* b = str_b, *a = p_a; *b; b++, a++)
		{
			// ���� ������� �� ��������� � ������ � ������ ������
			if (*a != *b)
			{
				// ���� ���������� �������������
				flag = false;

				// ��������� ��������
				break;
			}
		}

		// ���� ���� �����������, ������ ������ ������ ������� � ������ 
		if (flag)
		{
			// ���������� �������� ��������� ������ ������ � ������
			*count += 1;

			// �������� ������ ������ �� ������	
			// ���� �������� �� ��� ��� ���� ������� ���������� �������� ������ ������ � ������ 
			// �� ������ ������ � ������� ��������� 
			for (char* end = p_a + *len_b; p_a < end ; end--)
			{
				// ���� ��������
				// ���� ��������, ���� ������� ������� + ���� ������� �� ����������� ��������� ��������� ������
				for (char* a = p_a; a < str_a + *len_a; a++)
				{
					swap(*a, *(a + 1));
				}
				*len_a -= 1;
			}

			// �������� ��������� �� ���� �������, ���� ����� ����������� ������� ��� ����������
			// �������� ����� ������� ��������� ���� �� ������� ��������
			p_a--;
		}
	}

	// ����� ���������� 
	cout << "Result" << endl;

	cout << endl;

	// ����� ������ ������
	cout << str_a << endl;

	cout << endl;

	// ����� ���������� ��������� ������ ������ � ������
	cout << "Count: " << *count << endl;

	// �������� ������� ������ � ����
	free(len_a);
	free(len_b);
	free(str_a);
	free(str_b);
	free(count);
}
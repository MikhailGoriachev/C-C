#include <iostream>
#include "head.h"

using namespace std;

void task2()
{
	// 2. ������������ ������ 3 ������, ��������� �������� ��� ��������� ������ ������ � ������
	// hello big big world
	//	big
	//	small
	//
	//	hello small small world

	// ������ ������ 
	char* str_a = (char*)malloc(sizeof(char) * 80);

	// ������ ������ 
	char* str_b = (char*)malloc(sizeof(char) * 80);

	// ������ ������ 
	char* str_c = (char*)malloc(sizeof(char) * 80);

	// ���� ������ ������ 
	cout << "Enter first string: ";
	cin.ignore();
	cin.getline(str_a, 80);

	// ���� ������ ������
	cout << "Enter secong string: ";
	cin.getline(str_b, 80);

	// ���� ������� ������
	cout << "Enter tird string: ";
	cin.getline(str_c, 80);

	cout << endl;

	// ����� ������ ������
	long* len_a = (long*)malloc(sizeof(long));

	*len_a = strlen(str_a);

	// ����� ������ ������
	long* len_b = (long*)malloc(sizeof(long));

	*len_b = strlen(str_b);

	// ����� ������� ������
	long* len_c = (long*)malloc(sizeof(long));

	*len_c = strlen(str_c);

	// ���� ������ ������ �����
	if (*len_a == 0)
	{
		cout << "Error! The first line is empty" << endl;
		return;
	}

	// ���� ������ ������ ������ ������ 
	if (*len_a < *len_b)
	{
		cout << "Error! The first string less than the second string!" << endl;
		return;
	}

	// ���� ������ ������ ����� �������� '\0'
	if (*str_b == 0)
	{
		cout << "Error! The secong line is '\\0'" << endl;
		return;
	}
	

	// ������� ���������� ��������� ������ ������ � ������
	long* count = (long*)malloc(sizeof(long));

	*count = 0;

	// ������������ ������ ������
	for (char* poz_a = str_a; *(poz_a + *len_b - 1); poz_a++)
	{
		// ���� �������� ���������
		bool flag = true;

		// ��������� ��� ��������� ������� � ������ ������
		char* a = poz_a;

		// �������� ����� �� ��������� 
		for (char* b = str_b; *b; b++, a++)
		{
			// ���� �������� �� �����
			if (*a != *b)
			{
				// ���� ��������� 
				flag = false;

				// ����� �� ������� ��������
				break;
			}
		}

		// ���� ������ �����
		if (flag)
		{
			// ���������� �������� ��������
			*count += 1;

			// ���� ������ ������ � ������ �������� �� �����
			// 
			// ���� ������ ������ ������ �������
			if (*len_b < *len_c)
			{
				// �������� ������ �� ������� ����� ������ � ������� �������
				// �������� ����� �����������, ���� ������� ��������� ��������� ������ ������ 
				// � ������ �� ��������� ��������� ������� ������� ������ � ������ �����

				a = poz_a + *len_b + 1;

				for (; a <= poz_a + *len_c; a++)
				{
					// �������� ������
					for (char* a_a = str_a + *len_a; a_a >= a; a_a--)
					{
						swap(*a_a, *(a_a - 1));
					}

					// ���������� ����� ������ ������
					*len_a += 1;

					*(str_a + *len_a) = 0;
				}
			}

			// ���� ������ ������ ������, ��� ������
			if (*len_b > *len_c)
			{
				// �������� ����� �� ������� ����� ������� � ������ ������� 
				// �������� ����� ����������� �� ��� ���, ���� ������� ���������� 
				// ��������� � ������ ������ �� ������ ����� �������� ��������� � 
				// ������ + ����� ������� ������
				a = poz_a + *len_b - 1;

				for (; a >= poz_a + *len_c; a--)
				{
					// �������� �����
					for (char* a_a = a, * end = str_a + *len_a; a_a <= end; a_a++)
					{
						swap(*a_a, *(a_a + 1));
					}

					*len_a -= 1;
				}
			}
			
			// ���������� ��������������� ����� ������� �������
			// ����������� �� ��� ��� ���� ��������� � ������� ������ 
			// �� �������� �� �������� � 0
			for (char* c = str_c; *c; c++, poz_a++)
			{
				*poz_a = *c;
			}

			// ���� ������� ��������� ������ ������ ����� ��������� �� ������ �������
			// ������ � ��� ���� ������� �������� 0
			if (poz_a == str_a && *poz_a == 0)
				break;

			// ���������� ��������� � ������ ������ �� ����, ���� ��� 
			// ��������� �������� �����, ����� ����������� ��������� 
			// �� ���� ������ ��������� �������� �� ��������� ������� ������
			poz_a--;

			
		}
	}

	// ����� ����������
	cout << "Result" << endl;
	cout << endl;
	cout << "First string: " << str_a << endl;
	cout << endl;
	cout << "Count: " << *count << endl;

	// �������� ���������� ����������� ������
	free(str_a);
	free(str_b);
	free(str_c);
	free(len_a);
	free(len_b);
	free(len_c);
	free(count);
}
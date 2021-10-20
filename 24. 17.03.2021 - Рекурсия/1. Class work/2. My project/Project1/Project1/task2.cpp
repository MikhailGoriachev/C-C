#include <iostream>

using namespace std;

// ��������� ������
void swapString(char* string, size_t len, size_t i)
{
	if (i < len / 2 + 1)
	{
		// ��������� ������
		swap(*string, *(string + len - 1 - i));
		swapString(string + 1, len - 1, i + 1);
	}
}

void task2()
{
	// ��������� ������ ����������

	// ������ 
	char* str = (char*)malloc(sizeof(char) * 40);
	
	// ���� ������
	cout << "Enter string: ";
	cin.ignore();
	cin.getline(str, 40);

	// ����� �������� ������
	size_t len = strlen(str);

	// ����� �������
	swapString(str, len, 0);

	cout << "Result" << endl;

	// ����� ������
	cout << str << endl;

	free(str);
}
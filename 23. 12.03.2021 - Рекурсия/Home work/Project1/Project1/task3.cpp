#include <iostream>

using namespace std;

int countA(char str[], int count)
{
	if (*str != 0)
	{
		if (*str == 'a')
			count++;
		return countA(++str, count);
	}

	return count;
}

void task3()
{
	// 3. ����������� ������� ��������� ������ � ����������
	// ���������� ���� 'a'

	// ������ 
	char* str = (char*)malloc(sizeof(char) * 40);

	// ���� ������
	cout << "Enter string: ";
	cin.ignore();
	cin.getline(str, 40);

	cout << endl;

	// ����� ������� � ����� ���������� ���� 'a' � ������
	cout << "Count a: " << countA(str, 0) << endl;

	free(str);
}
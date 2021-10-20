#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task4()
{
	// ��������� �������� ���� �������� ���� � ������
	char nameFile1[40], nameFile2[40];

	cout << "Enter name file 1: ";
	cin >> nameFile1;

	cout << "Enter name file 2: ";
	cin >> nameFile2;

	FILE* sourceFile = fopen(nameFile1, "rb");
	FILE* destinationFile = fopen(nameFile2, "wb");

	if (sourceFile != nullptr && destinationFile != nullptr)
	{
		// ����������� ��������� � ����� � ����� �����
		fseek(sourceFile, 0, SEEK_END);

		// ���������� �������� ���������
		long fileSize = ftell(sourceFile);

		// ����������� ��������� � ����� � ����� ������
		fseek(sourceFile, 0, SEEK_SET);

		// �������� ������ ��� �������� ���� ���� ��������� �����
		char* buffer = new char[fileSize];

		if (buffer != nullptr)
		{
			// ������� ���������� ��������� �����
			fread(buffer, sizeof(char), fileSize, sourceFile);

			// ������� ���������� ��������� �����
			fwrite(buffer, sizeof(char), fileSize, destinationFile);

			// ���������� ������  �� ��� ��������� �����
			delete[] buffer;
		}

		fclose(sourceFile);
		fclose(destinationFile);
	}
	else cout << "Error opening file!!!" << endl;

}
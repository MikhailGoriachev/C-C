#pragma once

#include <iostream>

// ��������� ������ ��� ����������
struct data_arr
{
	// ����� ������� 
	long sizeArray;

	// ��������� �����
	clock_t start;

	// ����� ����������
	clock_t stop;

	// ����������� �����
	clock_t time;

	// ���������� �����������
	long long comp;

	// ���������� �����������
	long long moving;

	// �������� ����������
	char nameSort[20];

	// ���� � ����� � ��������
	char saveArrayPath[_MAX_PATH];
};

// ����� �����
void outLine();

// ������� ����� �������
void pressAnyKey();

// ����� "�����" ���������
void outHeader();

// ����������� �������
void CopyArray(long* destination, long* source, long* size);

// ���� ���������� 
void EnterOptions(data_arr* data, char* c, long** array, long** arrayCpy);

// 1. SORT BY BUBBLE
void BubbleSort(long* array, data_arr* data, long size);

// 2. SORT BY SELECTION
void SelectSort(long* array, data_arr* data);

// 3. SORT BY INSERTS
void InsertSort(long* array, data_arr* data);

// 4. QUICK SORT
void QuickSort(long* array, long size, data_arr* data);

// 5. SORT BY SHELL
void ShellSort(long* a, data_arr* data);

// 6. MergeSort
void MergeSort(long* arr, long leftBorder, long rightBorder, data_arr* data);

// 7. HEAP SORT
void HeapSort(long* arr, data_arr* data);

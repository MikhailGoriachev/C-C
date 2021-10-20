#pragma once

// заголовки заданий 

void task1();
void task2();
void task3();
void task4();
void task5();
// общие функции

// функция проверки и/или создания файла
// отказ в создании - 0, файл создан - 1, файл существует - 2
int fileCreate(char name[]);

// проверка на наличие "\n" в конце строки
void detectBackN(char a[]);

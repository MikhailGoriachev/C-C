#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void task5()
{
    FILE* pFile;
    int n;
    char name[100];

    pFile = fopen("myfile.txt", "w");
    for (n = 0; n < 3; n++)
    {
        puts("please, enter a name: ");
        cin >> name;
        fprintf(pFile, "Name %d [%-10.10s]n", n, name);
    }
    fclose(pFile);
}


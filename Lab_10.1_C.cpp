#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
using namespace std;



void OpenFile(char* fname)
{
    FILE* f = fopen(fname, "r");
    if (!f)
    {
        printf("File not opened!\n");
        return;
    }
    fclose(f);
}

void PrintTXT(char* fname)
{
    FILE* fin = fopen(fname, "r");
    if (!fin)
    {
        printf("File not opened!\n");
        return;
    }

    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), fin))
    {
        printf("%s", buffer);
    }

    fclose(fin);
}

int CountSimbol(char* fname)
{
    FILE* fin = fopen(fname, "r");
    if (!fin)
    {
        printf("File not opened!\n");
        return 0;
    }

    char buffer[1000];
    int k = 0;
    while (fgets(buffer, sizeof(buffer), fin))
    {
        for (unsigned i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '=')
                k++;
        }
    }

    fclose(fin);
    return k;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char fname[100];
    printf("¬вед≥ть ≥м'€ файлу €кий потр≥бно в≥дкрити : ");
    scanf("%s", fname);

    OpenFile(fname);
    PrintTXT(fname);
    printf("k(+-=) = %d\n", CountSimbol(fname));

    return 0;
}


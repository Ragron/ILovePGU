#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
int main()
{
    setlocale(LC_ALL, "Rus");

    setlocale(LC_ALL, "Russian");
    int mass[10];
    int max_mass = 0;
    int min_mass = 200;
    int result, i;
    srand(time(NULL));
    // Зад 2 
    printf("Зад №2\n");
    for (i = 0; i < 10; i++) {
        mass[i] = rand() % 20 + 1;
        printf("%3d", mass[i]);
    }
    //Зад 1
    printf("\nЗад №1");
    for (i = 0; i < 10; i++) {
        if (mass[i] < min_mass)
            min_mass = mass[i];
        if (mass[i] > max_mass)
            max_mass = mass[i];
    }
    result = max_mass - min_mass;
    printf("\n%d\n", result);
    //Зад 3
    printf("Зад №3\n");
    int* size;
    int n;
    printf("Размер массива\n");
    scanf("%d", &n);
    size = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        size[i] = rand() % 30 + 1;
        printf("%3d", size[i]);
    }
    printf("\n");
    free(size);
    //Зад 4
    printf("Зад №4\n");
    int mass_2[5][5];
    int summ_column[5];
    int summ_row, j;
    for (i = 0; i < 5; i++) summ_column[i] = 0;
    for (i = 0; i < 5; i++) {
        summ_row = 0;
        for (j = 0; j < 5; j++) {
            mass_2[i][j] = rand() % 10;
            printf("%5d", mass_2[i][j]);
            summ_row += mass_2[i][j];
            summ_column[j] += mass_2[i][j];
        }
        printf("   <%d\n", summ_row);
    }
    for (i = 0; i < 5; i++) {
        printf("%5s", "^");
    }
    printf("\n");
    for (i = 0; i < 5; i++) {
        printf("%5d", summ_column[i]);
    }
    printf("\n");
    //Зад 5
    printf("Зад №5\n");
    struct student {
        char famil[20], name[20], number[20];
    };
    char poisk[20];
    int q = 0;
    student arr[3];
    printf("Укажите фамилию, имя и номер студента\n");
    for (int i = 0; i < 3; i++) {
        scanf("%s %s %s", arr[i].famil, arr[i].name, arr[i].number);
    }
    for (int i = 0; i < 3; i++) {
        printf(" %s  %s  %s \n", arr[i].famil, arr[i].name, arr[i].number);
    }
    printf("Укажите фамилию небходимого студента\n");
    scanf("%s", poisk);
    for (int i = 0; i < 3; i++) {
        if (strcmp(poisk, arr[i].famil) == 0) {
            q = 1;
            printf(" %s  %s  %s \n", arr[i].famil, arr[i].name, arr[i].number);
        }
    }
    if (q == 0) {
        printf("Такого студента нету :o");
    }
    _getch();
    return 0;
}

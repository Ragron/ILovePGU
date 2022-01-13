﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


int m[10000];
void qs(int* items, int left, int right)
{
	int i, j;
	int x, y;
	i = left; j = right;

	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}


void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}


int cmp(const void* a, const void* b) {
	{
		return *(int*)a - *(int*)b;
	}
}

int main()
{

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	setlocale(LC_ALL, "Rus");

	srand(time(NULL));


	//for (int i = 0; i < 10000; i++) {   
	//	m[i] = rand() % 100 + 1;
	//}

	//for (int i = 1; i < 10000; i++) {		//Возрастающая 
	//	m[i] = m[i-1]+1;
	 //}

	//	for (int i = 0; i < 10000; i++) {	//Убывающая 
	//	m[i] = 10000-i;
	// }

	//		for (int i = 0; i < 5000; i++) {	//Возрастающе-убывающая
	//			m[i] = m[i - 1] + 1;
	// }
	//		for (int i = 5; i < 10000; i++) {
	//			m[i] = 10000 - i;
	//		}

	int start_time = clock();

	//shell(m, 10000);	
	//qs(m, 0, 10000 - 1);	
	qsort(m, 10000, sizeof(int), cmp);


	int end_time = clock();
	int search_time = end_time - start_time;

	printf("%d", search_time);
	return (0);
}

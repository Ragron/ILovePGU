#define _CRT_SECURE_NO_WARNINGS
#include "locale"
#include "stdio.h"
#include "conio.h"
#include <locale.h> 
#include <stdlib.h>
#include <malloc.h>
#include <queue>
using namespace std;

queue <int> q;
void DFS1(int v, int** matrix, int size, int iskl, int* NUM, int chet) {

	for (int i = 0; i < size; i++) {
		if (matrix[v][i] == 1 && NUM[i] == 0)
		{
			if (iskl != i) {
				q.push(i);
			}
			NUM[i] = 1;
		}
	}
	while (!q.empty()) {
		printf("Расстояние от введённой вершины до вершины №%d =%d\n", q.front(), chet);
		q.pop();
	}
	for (int i = 0; i < size; i++) {

		if (NUM[i] == 1)
		{
			chet = chet + 1;
			NUM[i] = 2;
			DFS1(i, matrix, size, iskl, NUM, chet);
		}
	}

}



int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	int v, n;
	int k = 0;
	printf("Введите размер матрицы:  ");
	scanf("%d", &n);


	int** M;
	M = (int**)malloc(n * sizeof(int*));
	int* A;
	A = (int*)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++)
	{
		M[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		A[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{

		printf("%d\n", A[i]);
	}

	printf("Матрицы:");
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > k) {
				M[i][j] = rand() % 2;
				printf("%3d", M[i][j]);
			}
			else if (j < k) {
				M[i][j] = M[j][i];
				printf("%3d", M[i][j]);
			}
			else {
				M[i][j] = 0;
				printf("%3d", M[i][j]);
			}
		}
		k++;
		printf("\n");
	}

	printf("\n\n");

	printf("Введите вершину, с которой будет начинаться обход:  ");
	scanf("%d", &v);

	printf("\n");
	printf("%d", v);
	int h = 0;
	int chet = 1;
	while (h != 1)
	{
		DFS1(v, M, n, v, A, chet);
	}
}

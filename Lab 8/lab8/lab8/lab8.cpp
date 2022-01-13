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

void BFSD(int v, int** G, int* DIST, int size) {
	q.push(v);
	DIST[v] = 0;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 0; i < size; i++) {
			if (G[v][i] > 0 and DIST[i] > (DIST[v] + G[v][i])) {
				q.push(i);
				DIST[i] = DIST[v] + G[v][i];
			}
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
	int* E;
	E = (int*)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++)
	{
		M[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		A[i] = 10000;
	}
	for (int i = 0; i < n; i++)
	{
		E[i] = i;
	}

	printf("Матрицы:");
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > k) {
				int random = rand() % 2;
				if (random == 0) {
					M[i][j] = 0;
					printf("%3d", M[i][j]);
				}
				else {
					M[i][j] = rand() % 10;
					printf("%3d", M[i][j]);
				}
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
	} // Создание матрицы

	printf("\n\n");

	printf("\n");
	int rad = 10000, dim = 0, max;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++)
		{
			A[i] = 10000;
		}
		BFSD(j, M, A, n);
		max = 0;
		for (int i = 0; i < n; i++) {
			if (A[i] > max) max = A[i];
			printf("Расстояние от вершины %d до вершины №%d = %d\n", j, i, A[i]);
		}
		E[j] = max;
		printf("эксцентриситет = %d\n", max);
		if (dim < max) dim = max;
		if (rad > max and rad != 0) rad = max;
		printf("\n\n");
	}
	printf("Диаметр графа = %d\n", dim);
	printf("Радиус графа = %d\n", rad);
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		if (E[i] == rad) printf("Вершина №%d является центральной\n", i);
	}
	for (int i = 0; i < n; i++) {
		if (E[i] == dim) printf("Вершина №%d является переферийной\n", i);
	}
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (M[i][j] != 0) count++;
		}
		if (count == 0) printf("Вершина №%d является изолированной\n", i);
		if (count == 1) printf("Вершина №%d является концевой\n", i);
		if (count == n - 1) printf("Вершина №%d является доминирующей\n", i);
	}
}
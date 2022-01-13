#include "stdio.h";
#include "stdlib.h";
#include "time.h";

unsigned short int a[1000][1000], b[1000][1000], c[1000][1000];
int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int i = 0, j = 0, r;
	int schet = 1000;
	srand(time(NULL));
	short int start_time = clock();

	int elem_c;
	while (i < schet)
	{
		while (j < schet)
		{
			a[i][j] = rand() % 100 + 1;
				j++;
		}
		i++;
	}
	srand(time(NULL));
	i = 0; j = 0;
	while (i < schet)
	{
		while (j < schet)
		{
			b[i][j] = rand() % 100 + 1;
			j++;
		}
		i++;
	}
	for (i = 0; i < schet; i++)
	{
		for (j = 0; j < schet; j++)
		{
			elem_c = 0;
			for (r = 0; r < 1000; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	short int end_time = clock();

	short int search_time = end_time - start_time;

	printf("%f", search_time / 1000.0);
	return(search_time);
}

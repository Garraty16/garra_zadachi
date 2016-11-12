#include <stdio.h>
#define nMax 100

int main (int argc, char *argv[])
{
	// размеры матриц
	int ai, aj, bi, bj;
	printf ("Vvedite razmeri martic A (MxN) i B (KxL) cherez probel (1-%d).\nM, N, K, L: ", nMax);
	scanf("%d %d %d %d", &ai, &aj, &bi, &bj);
	
	// validation
	if (ai < 1 || aj < 1 || bi < 1 || bj < 1 || ai > nMax || aj > nMax || bi > nMax || bj > nMax)
	{
		printf("Nepravil'nie razmeri matric. Dosvidania.");
		return 0;
	}
	if (aj != bi)
	{
		printf ("N doljno bit' ravno K. Soryan.");
		return 0;
	}
	
	// массивы матриц A, B и C
	int A[ai][aj], B[bi][bj], C[ai][bj];
	printf("\nTeper' vvedite elementi matric.\n");
	int i, j;
	
	// вводим элементы матрицы A
	for (i = 0; i < ai; i++)
		for (j = 0; j < aj; j++)
		{
			printf("A[%d][%d] = ", (i+1), (j+1));
			scanf("%d", &A[i][j]);
		}
		
	// вводим элементы матрицы B
	for (i = 0; i < bi; i++)
		for (j = 0; j < bj; j++)
		{
			printf("B[%d][%d] = ", (i+1), (j+1));
			scanf("%d", &B[i][j]);
		}
	printf("\n");
	
	// вычисляем матрицу C
	int dCurElement;
	int k;
	
	for (i = 0; i < ai; i++)
		for (j = 0; j < bj; j++)
		{
			dCurElement = 0;
			for (k = 0; k < ai; k++)
				dCurElement += A[i][k] * B[k][j];
			C[i][j] = dCurElement;
		}
		
	// выводим матрицу С на экран
	for (i = 0; i < ai; i++)
	{
		for (j = 0; j < bj; j++)
		{
			printf ("C[%d][%d] = %d ", (i + 1), (j + 1), C[i][j]);
		}
		
		printf("\n");
	}
		
	return 0;
}



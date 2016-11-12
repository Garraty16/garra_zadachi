// objective: определить строку, сумма элементов которой максимальна
#include <stdio.h>

int main (int argc, char *argv[])
{
	int n, m, i, j, iMax;
	float curSum, sumMax;
	int firstRun = 1; // 1 - true, 0 - false
	int answ = 1;
	
	// input data
	printf("n, m: ");
	scanf("%d%d", &n, &m);
	float a[n][m];
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			printf("a[%d][%d] = ", i+1, j+1);
			scanf("%f", &a[i][j]);
		}
	}
	
	// computations
	for (i = 0; i < n; i++){
		curSum = 0;
		// calculate sum of row i
		for (j = 0; j < m; j++){
			curSum += a[i][j];
		}
		if (firstRun == 1){
			sumMax = curSum;
			iMax = i;
			firstRun = 0;
		} else {
			if (curSum > sumMax){
				sumMax = curSum;
				iMax = i;
			}
		}
	}
	
	// output
	printf("\nRow %d has the maximum sum of its elements", iMax + 1);
	
	return 0;
}


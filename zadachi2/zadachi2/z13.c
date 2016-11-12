// objective: определить, являются ли члены массива возрастающей последовательностью
#include <stdio.h>

int main (int argc, char *argv[])
{
	int n, i;
	int answ = 1; // 1 - true, 0 - false
	
	// input data
	printf("n:");
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++){
		printf("a[%d] = ", i+1);
		scanf("%d", &a[i]);
	}
	
	// computations
	for (i = 1; i < n; i++){
		if (a[i-1] > a[i]){
			answ = 0;
			break;
		}
	}
	
	// output
	switch (answ) {
		case 1:
			printf("\nYes, elements complement a raising row");
			break;
		case 0: 
			printf("\nNo, sorry, some elements are not fit under the conditions.");
			break;
		default:
			break;
	}
	
	return 0;
}

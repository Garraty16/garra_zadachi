// objective: определить, есть ли в группе студент с заданным именем
#include <stdio.h>
#define MAX_NAME_LENGTH 100

int main (int argc, char *argv[])
{
	int n, i;
	int answ = 0; // 1 - true, 0 - false
	char name[MAX_NAME_LENGTH];
	
	// input data
	printf("n: ");
	scanf("%d", &n);
	char a[n][MAX_NAME_LENGTH];
	gets(a[0]); // fix?
	printf("Name of a student to find: ");
	gets(name);
	for (i = 0; i < n; i++){
		printf("group's member #%d: ", i+1);
		gets(a[i]);
	}
	
	// computations
	for (i = 0; i < n; i++){
		if (strcmp(a[i], name) == 0)
		{
			answ = 1;
			break;
		}
	}
	
	// output
	switch (answ) {
		case 1:
			printf("\nYes, there's such a student");
			break;
		case 0: 
			printf("\nNo such a student in this group! Are you trying to fool me?");
			break;
		default:
			break;
	}
	
	return 0;
}

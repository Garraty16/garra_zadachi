#include <stdio.h>
#define secInHr 3600
#define secInMin 60

int main (int argc, char *argv[])
{
	int n, h, m;
	printf ("Secunda sutok N: ");
	scanf("%d", &n);
	h = n / secInHr;
	n -= h * secInHr;
	m = n / secInMin;
	printf("Hours: %d\nMinutes: %d", h, m);
	
return 0;
}
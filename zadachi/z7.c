#include <stdio.h>

int factorial (int n)
{
	if (n <= 1)
		return n;
	else 
		return (n*factorial(n-1));
}

int main (int argc, char *argv[])
{
	int i = 1;
	for (i; i < 11; i++)
		printf("%d! = %d\n", i, factorial(i));
	
	return 0;
}


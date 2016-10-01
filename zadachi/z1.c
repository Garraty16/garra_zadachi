#include <stdio.h>

int main (int argc, char *argv[])
{
	int n;
	printf ("Please, enter n: ");
	scanf("%d", &n);
	
	if (n > 0)
		n *= 2;
	else if (n < 0)
		n -= 3;
	else 
		n = 10;
	
	printf ("Result: %d", n);
	return 0;
}
#include <stdio.h>

int calcN(int n){
	int an = n;
	if (an > 0)
		an *= 2;
	else if (an < 0)
		an -= 3;
	else 
		an = 10;
	return an;
}

int main (int argc, char *argv[])
{
	int n;
	printf ("Please, enter n: ");
	scanf("%d", &n);
	n = calcN(n);
	
	printf ("Result: %d", n);
	return 0;
}
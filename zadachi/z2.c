#include <stdio.h>
// to make this working, add -lm
// in linker options
#include <math.h>
// longest possible Length of an input a
#define maxLength 256

int calc_result(char a[maxLength]){
	int LengthA = 0, result = 0, b[maxLength], i, iCurChar;
	
	// counting number's size
	LengthA = strlen(a) - 1;

	// converting elements of a to int and inserting
	// it into the array b
	for (i = 0; i < LengthA; i++)
	{
		iCurChar = a[LengthA - i - 1] - '0';
		b[i] = iCurChar;
	}

	// computing result
	for (i = 0; i < LengthA; i++)
		result += b[i] * pow(2, i);
		
	return result;
}

int main (int argc, char *argv[])
{
	char a[maxLength];
	int result;

	// reading a number
	printf ("Input number: ");
	fgets(a, sizeof(a), stdin);

	result = calc_result(a);

  	printf("Result: %d", result);
	return 0;
}
#include <stdio.h>
// для rand()
#include <stdlib.h>
// именованная константа
#define N 4

int main (int argc, char *argv[])
{
	// инициализируем генератор рандомных чисел
	srand(time(NULL));
	// случайное число от 1 до 10
	int x = 1 + rand() % 10;
	
	int guess = 0;
	
	int i;
	printf("Ya zagadal chislo. ");
	
	for (i = 0; i < N; i++)
	{
		printf("\nU vas ostalos %d popitok.\nx = ", N - i);
		scanf("%d", &guess);
		if (guess == x)
		{
			printf("You win!");
			break;
		}
		else if (guess > x)
			printf("Menshe\n");
		else 
			printf("Bolshe\n");
	}
	
	return 0;
}


#include <stdio.h>
// для rand()
#include <stdlib.h>
// именованная константа
#define N 4

int play_game(int min, int max){
	// инициализируем генератор рандомных чисел
	srand(time(NULL));
	// случайное число от 1 до 10
	int x = min + rand() % (max - min);
	
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
}

int main (int argc, char *argv[])
{
	play_game(1, 10);
	
	return 0;
}


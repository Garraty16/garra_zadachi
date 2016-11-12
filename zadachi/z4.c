#include <stdio.h>
#include <math.h>

int* DecideSqrStatement(int a, int b, int c)
{
	static int answ[3]; // массив, содержащий Х1 и Х2. 3й член - количество решений уравнения
						// static потому, что нельзя возвращать указатели на локальные переменные
	int D; // дискриминант 
	D = b*b - 4*a*c;
	if (D < 0)
		answ[2] = 0; // d < 0 => нет решений
	else {
		D = sqrtf(D); 
		answ[0] = (-b - D) / (2*a); // x1
		answ[1] = (-b + D) / (2*a); // x2
		if (answ[0] == answ[1])
			answ[2] = 1; // одно решение
		else
			answ[2] = 2; // два решения
	}
	
		
	int* answer = answ; // указатель на массив answ
	return answer;
} 

int main (int argc, char *argv[])
{
	int a, b, c; // коэффициенты уравнения
	printf ("Dlya resheniya uravnenia aX^2 + bX + c = 0,\nVvedite a, b i c cherez probel: ");
	scanf("%d %d %d", &a, &b, &c);
	
	int *x = DecideSqrStatement(a, b, c);
	printf("Otvet:\n");
	
	// выводим ответ в зависимости от количества решений
	switch (x[2]) {
		case 0:
			printf("D < 0. Resheniy net.");
			break;	
		
		case 1:
			printf("X = %d", x[0]);
			break;
			
		case 2:
			printf("X1 = %d,\nX2 = %d.", x[0], x[1]);
			break;
			
		default:
		break;
	}
	
	return 0;
}
#include <stdio.h>

int degree (int n, int d)
{ 
	if (d == 0)
		return 1; // любое число в степени 0 == 1
	else if (d == 1)
		return n; // n в степени 1 == n
	else return (n * degree(n, d-1)); // рекурсия - возвращаем n * n_в_степени_(d-1)
}

int main (int argc, char *argv[])
{
	int n; // число, которое нужно возвести в степень (n == number)
	int d; // степень, в которую возводим (d == degree)
	int answ; // ответ
	
	// пользователь вводит числа n и d
	printf("Vvedite chislo N, kotoroe vozvodim v stepen D: ");
	scanf("%d", &n);
	printf("Vvedite stepen D: ");
	scanf("%d", &d);
	
	answ = degree(n, d);
	
	printf ("%d^%d = %d", n, d, answ);
	
	return 0;
}
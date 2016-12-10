// objective: с клавиатуры вводится строка символов.
// Определить, является ли она записью шестнадцатеричного числа
// Примечание: под 16-значным числом я подразумеваю использование только ПРОПИСНЫХ A..F
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM_SIZE 255

int main (int argc, char *argv[])
{
	char a[MAX_NUM_SIZE];
	int isHex = 0, n = 0, i = 0, iCurElem;
	printf("Value:\n");
    gets(a);
    n = strlen(a);

    // define whether there are no symbols except the numbers
    if (a[0] == '0' && a[1] == 'x' && n > 2){
        isHex = 1;
        for (i = 2; i < n; i++){
            iCurElem = (int)a[i];
            // if not fits to conditions of HEX-number
            // first check with && - 0..9, second && - A..F
            if (!((iCurElem >= 48 && iCurElem <= 57) || (iCurElem >= 65 && iCurElem <=70))){
                isHex = 0;
                break;
            }
        }
    }

    // output
    if (isHex == 1)
        printf("The number you typed is Hexagonal!");
    else
        printf("What you typed isn't an Hexagonal number");
	return 0;
}

// objective: с клавиатуры вводится строка символов.
// Определить, является ли она записью шестнадцатеричного числа
// Примечание: под 16-значным числом я подразумеваю использование только ПРОПИСНЫХ A..F
#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_SIZE 255

// GLOBAL
int numsLength;

// конвертирует строку в число и возвращает его
int string_to_number(char *a){
    int num = atoi(a);
    return num;
}

// очищает строку
void flush_string(char *a){
    int i;
    for (i = 0; i < MAX_STRING_SIZE; i++){
        a[i] = '\0';
    }
}

// преобразует строку в массив чисел и возвращает его
int* convert_string_to_numbers(char *a){
    static int answ[MAX_STRING_SIZE];
    int *p = answ, i, answLength = 0;
    static char curNumberArr[MAX_STRING_SIZE];
    char *curNumber = curNumberArr;
    int iCurNumber;
    int iCurNumberLength = 0;
    for (i = 0; i < strlen(a); i++){
        if (a[i] == '.'){
            iCurNumber = string_to_number(curNumber);
            answ[answLength] = iCurNumber;
            answLength++;
            break;
        }
        if (a[i] == ' '){
            iCurNumber = string_to_number(curNumber);
            answ[answLength] = iCurNumber;
            answLength++;
            flush_string(curNumber);
            iCurNumberLength = 0;
        } else {
            curNumber[iCurNumberLength] = a[i];
            iCurNumberLength++;
        }
    }

    numsLength = answLength;
    return p;
}

int main (int argc, char *argv[])
{
    char a[MAX_STRING_SIZE];
    // output array of numbers
    int *nums, i;
    printf("Type a consequence on numbers with a dot on the end:\n");
    gets(a);
    nums = convert_string_to_numbers(a);
    printf("\nOutput:\n");
    for (i = 0; i < numsLength; i++){
        if (i != numsLength)
            printf("%d\t ", nums[i]);
        else
            printf("%d");
        if ((i+1) % 3 == 0 && i != 0)
            printf("\n");
    }
	return 0;
}

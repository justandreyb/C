// Разработать программу, определяющую симметричность произвольного текста любой длины. Текст
// должен оканчиваться точкой(46). Эту задачу рекомендуется решать с помощью двух стеков. В первы
// стек поместить весь текст, а во второй - его половину так, чтобы последний символ текста 
// находился на дне стека. Потом путем поэлементного сравнения получить ответ
// Andrey B. - 21


#include <stdio.h>
#include <string.h>
#define MAXLENGTH 1000

struct Stack
{
	char Data;
	struct Stack *pNext;
};

void main(void) {
	
	char Elements[MAXLENGTH];
	printf("Enter the text : ");
	fflush(stdin);
	fgets(Elements, MAXLENGTH, stdin ); 
    char count;
    for (count = 0; count < MAXLENGTH; count++)
    {
        if (Elements[count] == '\n' )
        {
            Elements[count] = '\0';
            break;
        }
    }
    printf("Number of elements in text : %d \n", strlen(Elements));
	
	struct Stack *First_Stack, *Twice_Stack;

}
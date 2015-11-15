// Разработать программу, определяющую симметричность произвольного текста любой длины. Текст
// должен оканчиваться точкой(46). Эту задачу рекомендуется решать с помощью двух стеков. В первы
// стек поместить весь текст, а во второй - его половину так, чтобы последний символ текста 
// находился на дне стека. Потом путем поэлементного сравнения получить ответ
// Andrey B. - 21


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLENGTH 1000
#define MAXSIZE 500

struct Struct_Stack
{
    char Data;
    struct Struct_Stack *Next;
};
typedef struct Struct_Stack STACK;
STACK *StackIn = NULL, *StackCheck = NULL;

/*
void push(STACK *, char Letter);
char pop(STACK *);
void display(STACK *);
*/
/*  Function to add an element to the stack */
void push (STACK **Stack, char Letter)
{
   STACK *Last;
   Last = malloc(sizeof *Last);
   Last->Data = Letter;
   Last->Next = *Stack;
   *Stack = Last;
   return;
}
/*  Function to delete an element from the stack */
char pop (STACK **Stack)
{
    char Letter = 0;
    STACK *Last;
    if (*Stack == NULL)
    	return Letter;
    else
    {
	    Last = *Stack;
	    Letter = Last->Data;
	    *Stack = Last->Next;
	    free(Last);
	    return Letter;
	}
}
/*  Function to display the status of the stack */
void display (STACK *Stack)
{
   STACK *Last;
   if (Stack == NULL)
       printf("\n\tStack is empty\n");
   else
   {
       Last = Stack;
       printf("\n\tThe elements of the queue are : \n\n");
       while(Last != NULL)
       {       
            printf("%25c\n", Last->Data);   
            Last = Last->Next;
       }
   }
}

void main(void) {
	
	char Elements[MAXLENGTH];
	printf("Enter the text : ");
	fflush(stdin);
	fgets(Elements, MAXLENGTH, stdin ); 
    int count;
    div_t Length;

    for (count = 0; count < MAXLENGTH; count++)		
    {
        if (Elements[count] == '\n' )
        {
            Elements[count] = '\0';
            break;
        }
    }
    /*Length = div(strlen(Elements)-1,2);
    printf("Number of elements in text : %d \n", strlen(Elements));
	printf("\nResult : %d.%d\n", Length.quot, Length.rem);
    */
    for (count = 0; count < strlen(Elements); count++)
		push(&StackIn, Elements[count]);
	/*printf("\nResult : %d.%d\n", Length.quot, Length.rem);
	if (Length.rem == 0)
		for (count = (strlen(Elements)-2); count >= Length.quot; count--)	
			{push(StackCheck, Elements[count]);
				printf("I'M IN 1");
				}
	else
		for (count = (strlen(Elements)-2); count > Length.quot; count--) //Check loPol	
			{push(StackCheck, Elements[count]);
				printf("I'M IN 2 ; (Stack.Next = %d)\n",StackCheck->Next);
				}
	*/
	display(StackIn);
}

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
    Length = div(strlen(Elements)-1,2);
   
    char CenterLetter = 0;
    for (count = 0; count < strlen(Elements); count++)
		push(&StackIn, Elements[count]);
	
	if (Length.rem == 0)
		for (count = (strlen(Elements)-2); count >= Length.quot; count--)	
			push(&StackCheck, Elements[count]);
	else
	{	
		CenterLetter = Length.quot;
		for (count = (strlen(Elements)-2); count > Length.quot; count--) 	
			push(&StackCheck, Elements[count]);
	}

	char Flag = 0, StackIn_Letter, StackCheck_Letter;
	for (count = 0; count < strlen(Elements); count++)
	{
		StackIn_Letter = pop(&StackIn);	
		if (Length.rem == 0)
		{
			if (count > Length.quot)
			{	
				StackCheck_Letter = pop(&StackCheck);
				if (StackIn_Letter != StackCheck_Letter)
				{
					Flag = 0;
					break;
				}
				else
					Flag = 1;
			}
		}
		else
		{	
			if (count > Length.quot + 1 )
			{	
				StackCheck_Letter = pop(&StackCheck);
				if (StackIn_Letter != StackCheck_Letter)
				{
					Flag = 0;
					break;
				}
				else
					Flag = 1;
			}	
		}
	}

	if (Flag != 0)
		printf("\n Your text is a polynomial !");
	else
		printf("\n Your text isn't a polynomial !");

}

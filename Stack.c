/*
 * C program to implement stack. Stack is a LIFO data structure.
 * Stack operations: PUSH(insert operation), POP(Delete operation)
 * and Display stack.
 */
#include <stdio.h>
#define MAXSIZE 5
 
struct Struct_Stack
{
    char Data[MAXSIZE];
    int Next;
};
typedef struct Struct_Stack STACK;
STACK Stack;
 
void push(void);
int  pop(void);
void display(void);
 
void main ()
{
    char choice;
    int option = 1;
    Stack.Next = -1;
 
    printf ("STACK OPERATION\n");
    while (option)
    {
        printf ("------------------------------------------\n");
        printf ("      1    -->    PUSH               \n");
        printf ("      2    -->    POP               \n");
        printf ("      3    -->    DISPLAY               \n");
        printf ("      4    -->    EXIT           \n");
        printf ("------------------------------------------\n");
 
        printf ("Enter your choice : ");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        }
        fflush (stdin);
        printf ("\nDo you want to continue(Type 0 or 1)? : ");
        scanf    ("%d", &option);
    }
}
/*  Function to add an element to the stack */
void push ()
{
    int num;
    if (Stack.Next == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        printf ("Enter the element to be pushed : ");
        scanf ("%3d", &num);
        Stack.Next = Stack.Next + 1;
        Stack.Data[Stack.Next] = num;
    }
    return;
}
/*  Function to delete an element from the stack */
int pop ()
{
    int num;
    if (Stack.Next == - 1)
    {
        printf ("Stack is Empty\n");
        return (Stack.Next);
    }
    else
    {
        num = Stack.Data[Stack.Next];
        printf ("Poped element is = %3d ", Stack.Data[Stack.Next]);
        Stack.Next = Stack.Next - 1;
    }
    return(num);
}
/*  Function to display the status of the stack */
void display ()
{
    int i;
    if (Stack.Next == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\nThe status of the stack is : \n");
        for (i = Stack.Next; i >= 0; i--)
        {
            printf ("%10d\n", Stack.Data[i]);
        }
    }
    printf ("\n");
}
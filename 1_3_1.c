//+
//Ввести с клавиатуры строку символов. Определить длину и, если L кратна 4 , первая часть меняется со второй

#include <stdio.h>
#include <string.h>

void main(void)
{
	const char length = 100;
    char myString[length]; 
 	char myNewString[length];
 	char count,count_new;

    printf("Enter your string: ");
 
    fgets( myString, 100, stdin ); 
 
    char i;
    for ( i = 0; i < 100; i++ )
    {
        if ( myString[i] == '\n' )
        {
            myString[i] = '\0';
            break;
        }
    }
 
    printf( "\nThe length of your string: %d", strlen(myString));
    
    count_new = 0;
    if (strlen(myString) % 4 == 0)
    {
    	for (count = ((strlen(myString) / 2)); count <= (strlen(myString)-1); count++)
    		{
    			myNewString[count_new] = myString[count];
    			count_new++;
    		}
    	for (count = 0; count <= ((strlen(myString) / 2)-1); count++)
    		{
    			myNewString[count_new] = myString[count];
    			count_new++;
    		}
		myNewString[count_new] = '\0';	

    	printf("\nYour new string : %s", myNewString);
    }
}
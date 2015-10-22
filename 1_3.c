
//Andrey B. - 3 (Strings)
//Проверить, является ли слово палиндромом. Если да- напечатать, если нет - напечатать без больших букв
//65-90
#include <stdio.h>
#include <string.h>

void main(void)
{
	const char Length = 100;
    char myString[Length];
 	char myNewString[Length];
    char Letters[26];
    char toDel[Length];
    char count_l, flag, answer, let;
    
    printf("Enter word: " );
    fgets( myString, 100, stdin );

    char count;
    for ( count = 0; count < Length; count++ )
    {
        if ( myString[count] == '\n' )
        {
            myString[count] = '\0';
            break;
        }
    }

    flag = 1;
	answer = 0;
    for (count = 0; count < (strlen(myString)-1); count++) 
    {
    	if (myString[count] == myString[strlen(myString)-flag])
    		answer = 1;
    	else
    	{
    		answer = 0;
    		break;
    	}
    	flag++;	 
    }

    let = 64;
    for (count_l = 0; count_l <= 25; count_l++)
    {
		Letters[count_l] = let;
    	let++;
    }

    if (answer == 1)
		printf("You enter polynomial : %s .", myString);
	else
	{
		flag = 0;
		for (count = 0; count < (strlen(myString)-1); count++) 
    		for (count_l = 0; count_l <= 25; count_l++)
			{	
				if (myString[count] == Letters[count_l])
				{
					answer = 0;		
					toDel[flag] = count;
					flag++;
					break;
				}
			}	

/*		answer = 0;
		char flag_l = 0;
		for (count = 0; count < strlen(myString); count++)
			for (count_l = 0; count_l < flag; count_l++)
				if (toDel[count_l] != count)
				{
					printf("\nMyString: %c ; Flag : %d", myString[count], flag_l);
					myNewString[flag_l] = myString[count];
					printf("\nMyNewString: %c",myNewString[flag_l]);
					flag_l++;
					answer = 1;
					break;
				}	
		myNewString[strlen(myString)-(flag)] = '\0';
*/		
		if (answer = 0)
			printf("\nYou enter not a polynomial : %s", myString);
		else
		{
			//Не удаляет LooPl
			printf("\nYou enter not a polynomial : ");	
			for (count = 0; count < strlen(myString); count++)
				for (count_l = 0; count_l < flag; count_l++)
					if (toDel[count_l] != count)
					{	
						printf("%c", myString[count]);
						break;
					}
		}		
	}
}
//Получить все предложения, которые получаются при перестановке слов исходного предложения, которые через _
// 95 = _

#include <stdio.h>
#include <string.h>
#define LENGTH 100

static int factorial (int n)
{
  return (n < 2) ? 1 : n * factorial (n - 1);
}

void main(void)
{
    char myString[LENGTH];
    char let, flag, count_95; 

    printf( "Enter your string: " );
    fgets( myString, LENGTH, stdin ); 
    char count;
    for (count = 0; count < LENGTH; count++)
        if (myString[count] == '\n')
        {
            myString[count] = '\0';
            break;
        }

    count_95 = 0;
	for (count = 0; count < strlen (myString); count++)	
		if (myString[count] == 95)
	    	count_95++;
	char place_95[count_95];

	printf("\nWords count : %d ; Combinations : %d", (count_95 + 1), factorial (count_95+1));

	char *point;
	char Words[LENGTH / 10][LENGTH]; 
	count_95 = -1;
	point = strtok(myString, "_");
    while(point != NULL)
    {
        count_95++;
        strcpy(Words[count_95], point);
        point = strtok(NULL, "_");
    }
    count_95++;

    for (count = 0; count < count_95; count++)
        printf("\n%s",Words[count]);

    char *ChangingWords[factorial(count_95)][count_95];
    flag = count_95;
    char count_cur, count_first, count_repeat;
    char word = 0;
    char x = 0, y = 0;
    char numb = 1;

    //Create full array with all combinations (without last 2)
    //while (factorial(flag) >= 2)
    //{
        for (count = 0; count < count_95; count++)
        {
            for (count_first = 0; count_first <= factorial(flag-1); count_first++)
            {
                for (count_repeat = 0; count_repeat < factorial(flag-1); count_repeat++)
                {   
                    if (word < count_95)
                    {
                        //printf("\n%d) ( %s )", numb, Words[word]);
                        ChangingWords[y][x] = Words[word];
                        printf("\nElement[%d,%d] : ( %s )", y, x, ChangingWords[y][x]);
                        y++;
                        //numb++; // Delete numb
                    }
                    else
                        break;
                }
                word++;
            }
            x++;
            y = 0;
            flag--; 
            if ((count_95-flag) != count_95 + 1)
                word = count_95 - flag;         //Danger !
            
        }   
    //}

    /*//Swapping
    int swap[LENGTH];
    strcpy(swap, Words[l - 1]);
    strcpy(Words[l - 1], Words[r - 1]);
    strcpy(Words[r - 1], swap);
    */

    char count_y;
    printf("\n\nYour lines : \n");
    for (count = 0; count < factorial(count_95); count++)
    {
        for (count_y = 0; count_y < /*count_95*/ 2; count_y++)
            printf("( %s )", ChangingWords[count][count_y]);           
        printf("\n");
    }

    return;
}   	
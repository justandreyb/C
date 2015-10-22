//Все предложения, которые получаются при перестановке слов исходного предложения, которые через _
// 95 = _

#include <stdio.h>
#include <string.h>
#define LENGTH 100

static int factorial (int n)
{
  return (n < 2) ? 1 : n * factorial (n - 1);
}

/*char changing (char Line, char beg_pos, char end_pos, char word_count, char str_length)
{
	printf("\n");
	for (char count_95 = 0; count_95 < factorial (word_count-1); count_95++)
		if (beg_pos != 0 || beg_pos != (str_length-1))
			for (char count = 0; count < str_length; count++)
				if (count <= beg_pos || count > end_pos)		// ">=" -> +"_"
					printf ("%c", Line[count]);
		else
			for
	return;
}
*/ 
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

    //Swapping
    int swap[LENGTH];
    strcpy(swap, Words[l - 1]);
    strcpy(Words[l - 1], Words[r - 1]);
    strcpy(Words[r - 1], swap);
    
//

    char myOutString[LENGTH];
    for(count = 0; count < k; count++)
    {
        strcat(myOutString, a[count]);
        strcat(myOutString, "_");
    }
    strcat(sout, a[count_95]);

	count_95 = 0;
	for (count = 0; count < strlen (myString); count++)	
		if (myString[count] == 95)
	    {
			place_95[count_95] = count;
			count_95++;
		}
	//for (count = 0; count < count_95; count++)
	//	printf("\nPlace : %d",place_95[count]);

	for (int comb_count = 0; comb_count <= factorial (count_95); comb_count++)


}   	
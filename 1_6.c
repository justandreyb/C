// Дан файл А. Записать в файл В компоненты файла А в в обратном порядке.
 
#include <stdio.h>
#include <conio.h>

void main (void) {
	char name[15];
	FILE *in_file, *out_file;
    char in_filename[100];
 
	printf("Enter the filename to open: ");
    fgets(in_filename, 100, stdin ); 
    char i;
    for ( i = 0; i < 100; i++ )
    {
        if (in_filename[i] == '\n' )
        {
            in_filename[i] = '\0';
            break;
        }
    }

	if ((in_file = fopen(in_filename,"r")) == NULL)
		printf("Error in open/create file\n");
	else 
	{	
		printf("Enter your name : ");
		fflush(stdin);
		fgets(name, 15, stdin ); 
    	for ( i = 0; i < 100; i++ )
    	{
	        if (name[i] == '\n' )
	        {
	            name[i] = '\0';
	            break;
        	}
    	}
		fprintf(file, "%s\n", name);
	}
	fclose(file);

	return;

} 
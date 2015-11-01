// Дан файл А. Записать в файл В компоненты файла А в в обратном порядке.
 
#include <stdio.h>
#include <conio.h>

void main (void) {
	char name[15];
	FILE *file;
    char filename[100];

	printf("Enter the filename to open: ");
    fgets(filename, 100, stdin ); 
    char i;
    for ( i = 0; i < 100; i++ )
    {
        if (filename[i] == '\n' )
        {
            filename[i] = '\0';
            break;
        }
    }

	if ((file = fopen(filename,"w")) == NULL)
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
	printf("\nDone\n");
	return;

} 
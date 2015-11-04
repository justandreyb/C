// Дан файл А. Записать в файл В компоненты файла А в в обратном порядке.
 
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define FILECONTAIN 1000
#define FILENAMELEN 100

void main (void) {

	FILE *in_file, *out_file;
    char in_filename[FILENAMELEN];
 
	printf("Enter the filename to open: ");
    fgets(in_filename, FILENAMELEN, stdin ); 
    char count;
    for ( count = 0; count < FILENAMELEN; count++ )
    {
        if (in_filename[count] == '\n' )
        {
            in_filename[count] = '\0';
            break;
        }
    }

	if ((in_file = fopen(in_filename,"r")) == NULL)
		printf("Error in open/create file\n");
	else 
	{	
		char Infile[FILECONTAIN];
		while(!feof(in_file))
			fgets(Infile, FILECONTAIN, in_file);	
		fclose(in_file); 
    	
    	printf("\nLength: %d", strlen(Infile));

    	if ((out_file = fopen("outputfile.txt","w")) == NULL)
    		printf("Error in creating output file");
    	else
    	{
			for (count = (strlen(Infile)-1); count >= 0; count--)
				fprintf(out_file, "%c", Infile[count]);
			fclose(out_file);
			printf("\nDone !");
		}
	}
	return;

} 
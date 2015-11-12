// Записать текстовый файл F1, состоящий из произвольной последовательности
// буквенных символов. Упорядочить символы в алфавитном порядке, при этом
// все повторяющиеся символы должны быть удалены, и переписать текст в файл F2

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
		count = 0;
		//GetStdHandle(stdin) = "Hello!";
		while ((Infile[count] = fgetc (in_file)) != EOF) 
		{
			if (Infile[count] == '\n') 
			{
				Infile[count] = '\0';
				count = 0;
			}
			else 
				count++;
		}
		Infile[count] = '\0';
		printf("%s\n",Infile);
		fclose(in_file); 
    	
    	printf("\nLength: %d", strlen(Infile));
    	//SetConsoleCursorPosition = SetConsoleCursorPosition - 2;

    	char count_sort;
    	for (count_sort = 1; count_sort < strlen(Infile); count_sort++) 
    		for (count = 1 ; count < strlen(Infile); count++)
				if (Infile[count-1] > Infile[count])
				{
					Infile[count-1] = Infile[count-1] + Infile[count];
					Infile[count] = Infile[count-1] - Infile[count];
					Infile[count-1] = Infile[count-1] - Infile[count];
				}

    	if ((out_file = fopen("output.txt","w")) == NULL)
    		printf("Error in creating output file");
    	else
    	{
    		char flag = '\0';
			for (count = 0 ; count < strlen(Infile); count++)
				if (Infile[count] != flag)
				{
					fprintf(out_file, "%c", Infile[count]);
					flag = Infile[count];
				}
			fclose(out_file);
			printf("\nDone !");
			system("notepad C:\\C\\C\\output.txt");
		}
	}
	return;

} 
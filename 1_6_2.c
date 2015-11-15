// В программе предусмотреть создание меню со следующими пунктами:
// -Создание нового файла
// -Просмотр созданного файла 
// -Коррекция файла - дозапись новых данных или исправление старых


#include <stdio.h>
#include <conio.h>
#include <string.h>
#define FILECONTAIN 1000
#define FILENAMELEN 100

//1
void CreateNewFile (void) {
	
	printf("________________________________");
	printf("\nEnter the filename to create: ");
	fflush(stdin);
	char filename[FILENAMELEN];
    fgets(filename, FILENAMELEN, stdin ); 
    char count;
    for (count = 0; count < FILENAMELEN; count++)
    {
        if (filename[count] == '\n' )
        {
            filename[count] = '\0';
            break;
        }
    }
    FILE *new_file;
    if ((new_file = fopen(filename,"w")) == NULL)
		printf("Error in create file %s\n",filename);
	else 
	{	
		printf("File %s successfully created.\n",filename);
		fclose(new_file);
	}

}

//2
void ShowFile(void) {

	char Filename[FILENAMELEN];
	fflush(stdin);
	printf("Enter the file to show : ");
    fgets(Filename, FILENAMELEN, stdin ); 
    char count;
    for (count = 0; count < FILENAMELEN; count++)
    {
        if (Filename[count] == '\n' )
        {
            Filename[count] = '\0';
            break;
        }
    }

	FILE *Curfile;
	if ((Curfile = fopen(Filename,"r")) == NULL)
		printf("Error in show file %s\n",Filename);
	else 
	{	
		char Infile[FILECONTAIN];
		while(!feof(Curfile))
			fgets(Infile, FILECONTAIN, Curfile);	
		fclose(Curfile); 
    	
    	printf("File %s contain :\n", Filename);
    	for (count = 0; count < strlen(Infile); count++)
			printf("%c", Infile[count]);

		fclose(Curfile);
	}
}

//3
void ChangeFile(void) {
	
	char Filename[FILENAMELEN];
	fflush(stdin);
	printf("Enter the file to change : ");
    fgets(Filename, FILENAMELEN, stdin ); 
    char count;
    for (count = 0; count < FILENAMELEN; count++)
    {
        if (Filename[count] == '\n' )
        {
            Filename[count] = '\0';
            break;
        }
    }
/*
	FILE *Curfile;
	if ((Curfile = fopen(Filename,"r+")) == NULL)
		printf("Error in open file %s\n",Filename);
	else 
	{	
		char Infile[FILECONTAIN];
		while(!feof(Curfile))
			fgets(Infile, FILECONTAIN, Curfile);	
		fclose(Curfile); 
    	
    	printf("File %s contain :\n", Filename);
    	for (count = 0; count < strlen(Infile); count++)
			printf("%c", Infile[count]);

		fclose(Curfile);
	}
*/
}

void AddToFile(void) {

	char Filename[FILENAMELEN];
	fflush(stdin);
	printf("Enter the name of file to add new information : ");
    fgets(Filename, FILENAMELEN, stdin ); 
    char count;
    for (count = 0; count < FILENAMELEN; count++)
    {
        if (Filename[count] == '\n' )
        {
            Filename[count] = '\0';
            break;
        }
    }

	FILE *Curfile;
	if ((Curfile = fopen(Filename,"a+")) == NULL)
		printf("Error in open file %s\n",Filename);
	else 
	{	
		char Infile[FILECONTAIN];
		printf("Enter new information : ");
		fgets( Infile, FILECONTAIN, stdin ); 
	    char i;
	    for ( i = 0; i < 100; i++ )
	    {
	        if (Infile[i] == '\n' )
	        {
	            Infile[i] = '\0';
	            break;
	        }
	    }
	    fprintf(Curfile," %s",Infile);	
		fclose(Curfile); 
	}
}

void main (void) {

	printf("| Create file - 1 | Show file - 2 | Edit file - 3 |\n");
	char Operation;
	char Operation_3;
	SelectOperation:
	printf("Enter your operation : ");
	scanf("%d",&Operation);
	switch (Operation) {
	case 1:
		CreateNewFile();
		break;
	case 2:
		ShowFile();
		break;
	case 3:
		SelectOperation_3:
		fflush(stdin);
		printf("| Change file - 1 | Add to file - 2 |");
		scanf("%d",&Operation_3);
		switch (Operation_3) {
			case 1:
				ChangeFile();
				break;
			case 2:
				AddToFile();
				break;
			default:
				printf("Incorrect operation. \n");
				goto SelectOperation_3;
				break;
		}
		break;
	default:
		printf("Incorrect operation. \n");
		goto SelectOperation;
	}

	printf("\nDo you wont continue ? (Yes = 1) : ");
	fflush(stdin);
	scanf("%d",&Operation);
	if (Operation == 1)
		goto SelectOperation;

	return;
}
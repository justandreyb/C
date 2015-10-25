//Элементы структуры: фамилия ст, номер группы, место проживания(общ. или нет);
//Вывести отсортированный по алфавиту список прожив в общежитии студентов и их кол-во
// Andrey B. - 17 - Structure
//43 = "+" ; 45 = "-"
#include <stdio.h>
#include <string.h>
#define SURNM 20

struct Student {
	char Surname[SURNM];
	int Group;
	char Dormitory;
};

void main (void)
{
	char number;
	printf("Enter a number of students : ");
	scanf("%d", &number);

	struct Student Students[number], Change;
	char flag;
	char count;
	printf("________________________________\n");
	for (count = 0; count < number; count++)
	{
		flag = count;
		printf("Enter a surname of %d student : ",(count+1));
		fflush(stdin);
		fgets(Students[flag].Surname, SURNM, stdin); 
	    for (count = 0; count < SURNM; count++)
	        if (Students[flag].Surname[count] == '\n')
	        {
	            Students[flag].Surname[count] = '\0';
	            break;
	        }	    
	    count = flag;
		printf("Enter a group of %s : ",Students[count].Surname);
	    scanf("%d",&Students[count].Group);
	    fflush(stdin);
	    printf("He/she lives in a dormitory ? (+ / -) : ");
	    scanf("%c",&Students[count].Dormitory);	
	    printf("________________________________\n");	
	}

	for (count = 0; count < number - 1; count++)
		for (flag = count + 1; flag < number; flag++)
			if (strcmp(Students[count].Surname, Students[flag].Surname) > 0)
			{ 
				Change = Students[count]; 
				Students[count] = Students[flag]; 
				Students[flag] = Change; 
			}

	flag = 0;
	for (count = 0; count < number; count++)
		if (Students[count].Dormitory == '+')
		{
			printf("%10s (Group : %6d)\n", Students[count].Surname, Students[count].Group);
			flag++;
		}	
	return;
}

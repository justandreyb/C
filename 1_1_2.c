//+
//Расположить элементы строк матрицы 5*5 в порядке возрастания, если номера строк 
//четные и в порядке убывания, если номера строк нечетные.

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

void main(void)
{
	const int matr_count = 5;

	char count, count_x, count_y, count_even, count_uneven;
	char matrix[matr_count][matr_count];
	char flag;
	char count_sort;

	srand(time(NULL));

	for (count_x = 0; count_x <= (matr_count - 1); count_x++)					
		for (count_y = 0; count_y <= (matr_count - 1); count_y++)
			matrix[count_x][count_y] = 0 + rand() % 50;

	printf("\n Your matrix : \n");

	for (count_x = 0; count_x <= (matr_count-1); count_x++)
	{
		for (count_y = 0; count_y <= (matr_count-1); count_y++)
			printf(" %d ", matrix[count_x][count_y]);			
		printf("\n");
	}

	count_even = 1;
	count_uneven = 0;
	for (count_x = 0; count_x <= (matr_count-1); count_x++)
	{
		if ((count_x + 1) % 2 == 0)	
		{
			for (count_sort = 1; count_sort <= matr_count; count_sort++)
				for (count_y = (matr_count-1); count_y >= 1; count_y--)	
					if (matrix[count_x][count_y-1] > matrix[count_x][count_y])
					{
						matrix[count_even][count_y] = matrix[count_even][count_y-1] + matrix[count_even][count_y];
						matrix[count_even][count_y-1] = matrix[count_even][count_y] - matrix[count_even][count_y-1];
						matrix[count_even][count_y] = matrix[count_even][count_y] - matrix[count_even][count_y-1];
					}
			count_even = count_even + 2;						
		}
		else
		{
			for (count_sort = 1; count_sort <= matr_count; count_sort++)	
				for (count_y = 1; count_y <= (matr_count-1); count_y++)		
					if (matrix[count_uneven][count_y-1] < matrix[count_uneven][count_y])
					{
						matrix[count_uneven][count_y] = matrix[count_uneven][count_y-1] + matrix[count_uneven][count_y];
						matrix[count_uneven][count_y-1] = matrix[count_uneven][count_y] - matrix[count_uneven][count_y-1];
						matrix[count_uneven][count_y] = matrix[count_uneven][count_y] - matrix[count_uneven][count_y-1];
					}
			count_uneven = count_uneven + 2;					
		}

	}

	printf("\n Your new matrix : \n");

	for (count_x = 0; count_x <= (matr_count-1); count_x++)
	{
		for (count_y = 0; count_y <= (matr_count-1); count_y++)
			printf(" %d ", matrix[count_x][count_y]);			
		printf("\n");
	}

}
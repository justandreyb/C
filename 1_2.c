//В матрице 5*10 упорядочить элементы в каждой строке по возрастанию, а строки матрицы расположить по возрастанию суммы элементов строк

#include <stdio.h>
// Andrey B. - 6 - arrays
void main(void)
{
	const int x = 3;
	const int y = 5;
	int count_x, count_y, max_el, count_sort, count_sort_x;
	int matrix[x][y];
    int count, cur_x, cur_y;

//Create matrix
	srand(time(NULL));	

	for (count_x = 0; count_x <= (x - 1); count_x++)					
	{
		for (count_y = 0; count_y <= (y - 2); count_y++)
			matrix[count_x][count_y] = 0 + rand() % 50;
		matrix[count_x][y] = 0;
	}

//Print matrix
	printf("\n Your matrix : \n");
	for (count_x = 0; count_x <= (x - 1); count_x++)
	{
		for (count_y = 0; count_y <= (y - 2); count_y++)
			printf(" %d ", matrix[count_x][count_y]);			
		printf("\n");
	}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int Sum = 0;
	for (count_x = 0; count_x <= (x - 1); count_x++)
	{	
		for (count_y = 0; count_y <= (y - 2); count_y++)
		{
			printf("\nElement : %d ; Sum before: %d ",matrix[count_x][count_y], Sum);
			Sum = Sum + matrix[count_x][count_y];
		}
		matrix[x-1][y] = Sum;
		printf("\nSum_%d = %d", (count_x+1), matrix[x-1][y]);
		Sum = 0;
	}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
//Regularize elements
	for (count_x = 0; count_x <= (x - 1); count_x++)
		for (count_sort = 1; count_sort <= y; count_sort++)
			for (count_y = 1; count_y <= (y - 2); count_y++)
			{
				if (matrix[count_x][count_y-1] > matrix[count_x][count_y])
				{
					matrix[count_x][count_y-1] = matrix[count_x][count_y-1] + matrix[count_x][count_y];
					matrix[count_x][count_y] = matrix[count_x][count_y-1] - matrix[count_x][count_y];
					matrix[count_x][count_y-1] = matrix[count_x][count_y-1] - matrix[count_x][count_y];
				}
			}

//Print regularuzed matrix 
	printf("\n Your regularized matrix : \n");
	for (count_x = 0; count_x <= (x - 1); count_x++)
	{
		for (count_y = 0; count_y <= (y - 2); count_y++)
			printf(" %d ", matrix[count_x][count_y]);			
		printf("\n");
	}
	
	for (count_x = 1; count_x <= (x - 1); count_x++)
	{	
		for (count_sort = 1; count_sort <= x; count_sort++)	
			if (matrix[count_x-1][y] > matrix[count_x][y])
			{	
				count_sort_x = count_x - 1;
				for (count_y = 0; count_y <= (y - 2); count_y++)
				{
					matrix[count_sort_x][count_y] = matrix[count_x][count_y] + matrix[count_sort_x][count_y];
					matrix[count_x][count_y] = matrix[count_sort_x][count_y] - matrix[count_x][count_y];
					matrix[count_sort_x][count_y] = matrix[count_sort_x][count_y] - matrix[count_x][count_y];
				}
				matrix[count_sort_x][y] = matrix[count_x][y] + matrix[count_sort_x][y];
				matrix[count_x][y] = matrix[count_sort_x][y] - matrix[count_x][y];
				matrix[count_sort_x][y] = matrix[count_sort_x][y] - matrix[count_x][y];
			}
	}
	
//Print regularuzed matrix 
	printf("\n Your regularized matrix : \n");
	for (count_x = 0; count_x <= (x - 1); count_x++)
	{
		for (count_y = 0; count_y <= (y - 2); count_y++)
			printf(" %d ", matrix[count_x][count_y]);			
		printf("\n");
	}
}
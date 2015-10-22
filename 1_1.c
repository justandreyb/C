//+
#include <stdio.h>
// Andrey B. - 2 (Done)
void main(void)
{
	const int matr_count = 3;

	char count, count_x, count_y, max_el, cent_el;
	char matrix[matr_count][matr_count];;
	char cur_x, cur_y;
	char max_x, max_y, flag;

	for (count_x = 0; count_x <= (matr_count - 1); count_x++)					
	{	for (count_y = 0; count_y <= (matr_count - 1); count_y++)
		{
			printf("Write element [%d,%d] : ", (count_x+1), (count_y+1));
			scanf("%d", &matrix[count_x][count_y]);
		}
    }
	max_el = -128;
	printf("\n Your matrix : \n");

	for (count_x = 0; count_x <= (matr_count-1); count_x++)
	{
		for (count_y = 0; count_y <= (matr_count-1); count_y++)
			printf(" %d ", matrix[count_x][count_y]);			
		printf("\n");
	}

	for (count = 0; count <= (matr_count-1); count++)
	{
		//printf("\n Current element [%d,%d] : %d ; Maximal element : %d",(count + 1), (count + 1), matrix[count][count], max_el);
		if (max_el < matrix[count][count])
		{
			max_el = matrix[count][count];	
			max_x = count;
			max_y = count;
		}
	}

	flag = matr_count - 1;
	for (cur_x = 0; cur_x<= (matr_count-1); cur_x++)
	{
		cur_y = flag;
		flag = flag - 1; 	
		//printf("\n Current element [%d,%d] : %d ; Maximal element : %d",(cur_x + 1), (cur_y + 1), matrix[cur_x][cur_y], max_el); 
		if (max_el < matrix[cur_x][cur_y])
		{
			max_el = matrix[cur_x][cur_y];
			max_x = cur_x;
			max_y = cur_y;
		}
	}		

	cent_el = matrix[matr_count / 2][matr_count / 2];
	matrix[matr_count / 2][matr_count / 2] = max_el;
	matrix[max_x][max_y] = cent_el;

	printf("\n Your new matrix : \n");

	for (count_x = 0; count_x <= (matr_count-1); count_x++)
	{
		for (count_y = 0; count_y <= (matr_count-1); count_y++)
			printf(" %d ", matrix[count_x][count_y]);			
		printf("\n");
	}

}
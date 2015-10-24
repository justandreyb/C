/*
	1	2	3	4						
	1	2	4	3				
	1	3	2	4					
	1	3	4	2						
	1	4	2	3						
	1	4	3	2						
	2	1	3	4				
	2	1	4	3				
	2	3	1	4				
	2	3	4	1				
	2	4	1	3					
	2	4	3	1				
	3	1	2	4
	3	1	4	2
	3	2	1	4
	3	2	4	1
	3	4	1	2
	3	4	2	1
	4	1	2	3
	4	1	3	2
	4	2	1	3
	4	2	3	1
	4	3	1	2
	4	3	2	1
*/

char ChangingWords[LENGTH][factorial(count_95)]; //!
char flag = count_95;
char y = 0;
while (factorial(flag) >= 2)
{
	for (count = 0; count < count_95; count++)
	{
		for (char count_cur = 0; count_cur <= factorial(flag); count_cur++)
			ChangingWords[count_cur][y] = Words[y]
		y++;
	}
	flag--;		
}
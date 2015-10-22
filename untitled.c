
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
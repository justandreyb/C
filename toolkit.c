//toolkit

#include <stdio.h>
#include <math.h>

int N_1 (int x, int y) {

	int z;
	
	if (x > y) 
		z = x - y;
	else
		z = y - x + 1;

	return z;
}

void N_2 (void) {

	int a, b;

	printf("\n2) \n");
	printf("\nEnter A : ");
	scanf("%d",&a);
	printf("\nEnter B : ");
	scanf("%d",&b);

	if (a > b) 
		printf("\nA > B \nYour answer: %d",a);
	else
		printf("\nA < B \nA: %d , B: %d", a, b);

	return;
}

int N_3 (int x, int y) {
	
	if (x <= y) 
		x = 0;

	return x;
}

void N_4 (int x, int y, int z) {
	
	int Flag[] = {0,0,0};

	printf("\n 4) \n");
	if ((x >= 1)&&(x <= 3)) 
		Flag[0] = 1;	
	if ((y >= 1)&&(y <= 3)) 
		Flag[1] = 1;	
	if ((z >= 1)&&(z <= 3)) 
		Flag[2] = 1;	
	
	int i;
	for (i = 0; i <= 2; i++)
		if (Flag[i] == 1) 
		{
			if (i == 0)
				printf("X : %d ;",x);
			if (i == 1)
				printf("Y : %d ;",y);
			if (i == 2)
				printf("Z : %d ;",z);		
		}
	return;
}

void N_5 (int x, int y, int z) {

	int Flag[] = {0,0,0};

	printf("\n 5) \n");
	if (x >= 0)
		Flag[0] = x * x;	
	if (y >= 0) 
		Flag[1] = y * y;	
	if (z >= 0) 
		Flag[2] = z * z;	
	
	int i;
	for (i = 0; i <= 2; i++)
		printf("%d: %d ;", (i + 1), Flag[i]);		
		
	return;

}

void N_6 (int a, int b, int c) {
	
	// a*x^2 + b*x + c=0
	float x_1, x_2;

	printf("\n 6) \n");
	if ((b^2-4*a*c) >= 0) 
	{		
		x_1 = (b*(-1) - sqrt(b^2-4*a*c)) / (2*a);
		x_2 = (b*(-1) + sqrt(b^2-4*a*c)) / (2*a);
		printf("Your answer: \nX1 = %d, X2 = %d",x_1,x_2);
	}

	printf("Your answer: False");

	return ;
}

void N_11 (void) {
	// a^n
	int a;
	char n;

	printf("Enter N : ");
	scanf("%d",&n);
	
	char i;
	int answer;
	answer = 1;
	printf("Enter A : ");
	scanf("%d",&a);
	printf("1)\n");
		for (i = 1 ; i <= n ; i++) 
			answer = answer * a;

		printf ("%d ^ %d = %d ", a, n, answer);
		
	printf("\n2)\n");
		for (i = 0 ; i <= (n - 3) ; i++) {
			answer = answer * (a + i);
		} 
			
		printf("a(a + 1)..(a + n - 1) = %d",answer);
}

double N_16 (void) {
	int	 i ;
	double sum =0;

	for (i = 1; i <= 100; i++)
		sum = sum + (1.0/(i*i));
	return sum;
}

void N_17 (void) {

	int	 i;
	double sum = 0;

	for (i = 1; i <= 50; i++)
		sum = sum + (1.0 / (i*i*i));
	printf("%f",sum);
	getchar();
}


void main (void) {

	char number;
	printf("Enter N : ");
	scanf("%d",&number);
	
	switch (number) {
		case 1:
			printf("\n1) Z: %d\n",N_1(3,5));
			break;
		case 2:
			N_2();
			break;
		case 3:
			printf("\n3) %d\n",N_3(5,3));
			break;
		case 4:
			N_4(1,5,3);
			break;
		case 5:
			N_5(7,2,4);
			break;
		case 6:
			N_6(1,3,4);
			break;
		case 11:
			N_11();
			break;	
		case 16:
			printf("Answer : %d",N_16());
			break;
		case 17:
			N_17();
			break;	
	}
}
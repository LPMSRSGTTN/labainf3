#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define L 100001

int f(int n)
{
	if (n < 2) 
		return 1;
	if (n >= 2 && n % 3 == 0) 
		return f(n / 3) + 1;
	if (n >= 2 && n % 3 != 0) 
		return f(n - 2) + 5;
}
double g(double x, int N)
{
    double sum = 0;
	for (int n = 0; n <= N; n++)
	{
        double fct = flcl(2*n - 1);
		double stp = pow(x, 2*n - 1);
		double tmp = (2*n) * stp / (fct);
        sum += tmp;
	}
    return sum;
}
double dg(double x, int N)
{
	double sm = 2*x;
	double tmp = 2 * x;
	for (int n = 2; n <= N; n++)
	{
		tmp *= n * pow(x, 2) / ((n - 1) * (2 * n - 1)); //
		sm += tmp;
	}
	return sm;
}
int flcl(int k)
{	
	int fact = 1;
	if (k % 2 == 0)
	{
		for (int i = 1; i <= k; i++)
		{
			if (i % 2 == 0)
			{
				fact *= i;
			}
			else
			{
				continue;
			}
		}
	}
	else
	{
		for (int i = 1; i <= k; i++)
		{
			if (i % 2 != 0)
			{
				fact *= i;
			}
			else
			{
				continue;
			}
		}
	}
	return fact;
}
int main()
{	
	int x1, count = 0, odd_count = 0;
    double x;
    int N;
	for (int n = 1; n < L; n++)
	{
		if (f(n) == 55)
		{
			count++;
		}
	}
	printf("f(n) = 55: %d \n", count);

	printf("input num: ");
	scanf_s("%d", &x1);
	int x2 = f(x1);
	char result[20];
	snprintf(result, sizeof(result), "%d", x2);
	for (int i = 0; result[i] != '\0'; i++)
	{
		if ((result[i] - '0') % 2 != 0)
		{
			odd_count++;
		}
	}
	printf("%d", x2);
	printf("\nodd symbols in f(%d):  %d \n", x1, odd_count);
	printf("==========================\n");
	printf("input X: ");
	scanf_s("%lf", &x);
	printf("input N: ");
	scanf_s("%d", &N);
	printf("2nd task:  %lf", g(x, N));
	printf("\n2nd task recurrent:  %lf", dg(x, N));
	return 0;
}
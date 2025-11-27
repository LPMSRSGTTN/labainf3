//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define N 12

int num();
int* choice(int* arr1);
void task1(int* arr1, int num1);
void task2(int* arr1);

int main()
{
	int arr[N];
	int num1 = num();
	int* arr1 = choice(arr);
	task1(arr1, num1);
	task2(arr1);
	return 0;
}

int num()
{
	int num;
	printf("Задайте случайное число: ");
	scanf_s("%d", &num);
	return num;
}

int* choice(int* arr1)
{
	int i = 0;
	if (N < 12)
	{
		for (i; i < N; i++)
		{
			printf("\nВведите элемент %d\n", i + 1);
			scanf_s("%d", &arr1[i]);
		}
	}
	else
	{
		srand(time(NULL));
		while (i < N)
		{
			arr1[i] = rand() % 100;
			printf("\n%d элемент: %d", i + 1, arr1[i]);
			i++;
		}
	}
	return arr1;
}

void task1(int* arr1, int num1)
{
	int minn = 1000;
	for (int i = N - 1; i >= 0; i--)
	{
		if (arr1[i] % num1 == 0 & minn > arr1[i])
			printf("\n Минимальный элемент, кратный заданному числу: %d", arr1[i]);
		minn = arr1[i];
	}
}

void task2(int* arr1)
{
	int i = 0;
	int notnull = -1;
	bool flag = true;
	while (i < N)
	{
		if (arr1[i] != 0)
			notnull = i;
		i++;
	}
	if (notnull == -1)
		printf("\nНет ненулевых элементов в массиве");
	else
		printf("\nПоследний ненулевой элемент массива: %d", notnull);
}


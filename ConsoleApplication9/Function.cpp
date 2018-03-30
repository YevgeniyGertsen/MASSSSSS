#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int * GetMemory(int *length)
{
	int *mas = NULL;
	printf("Введите длину массива: ");
	scanf("%d", length);
	mas = (int*)calloc(*length, sizeof(int));
	if (mas == NULL)
	{
		printf("Not enough memory.\n");
		exit(0);
	}
	else
		return mas;
}
void fillArray(int *mass, int length)
{
	for (short int i = 0; i < length; i++)
		*(mass + i) = -40 + rand() % 70;
}
void printArray(int *mass, int length)
{
	for (short int i = 0; i < length; i++)
		printf("%d\t", *(mass + i));
	printf("\n");
}
int SearchSecondPositivElement(int *mass, int length)
{
	int counter = 0;
	for (short int i = 0; i < length; i++)
	{
		if (*(mass + i) > 0)
		{
			counter++;
			if (counter == 2)
			{
				return i;
			}
		}
	}
}
void ReverseElements(int *mas, int length)
{
	int check = length - 1, m;
	for (short int i = 0; i < length / 2; i++)
	{
		m = *(mas + i);
		*(mas + i) = *(mas + check);
		*(mas + check) = m;
		check--;
	}
}
void ElementNeKrat3(int *mass, int length)
{
	double summa = 0, sr = 0;
	for (short int i = 0; i < length; i++)
		if (*(mass + i) % 3 != 0)
		{
			summa += *(mass + i);
			sr++;
		}
	printf("Сумма элементов, не кратных 3 = %lf\n", summa);
	printf("Среднее арифметическое элеметов, не кратных 3 = %lf\n", summa / sr);
}
void SwitchMinAndLastElement(int *mass, int length)
{
	int min = *mass, s = 0, m;
	for (short int i = 0; i < length; i++)
	{
		if (min > *(mass + i))
		{
			s = i;
			min = *(mass + i);
		}
	}
	printf("\n");
	printf("Минимальный элемент массива = %d\n", min);
	m = *(mass + length-1);
	*(mass + length - 1) = min;
	*(mass + s) = m;
}
long int TwoTo8(int *mass)
{
	long int proizv = 1;
	for (short int i = 2; i <= 8; i++)
	{
		proizv *= *(mass + i);
	}
	return proizv;
}
void ChetOrNechet(int *mas, int length)
{
	int counter1 = 0, counter2 = 0;
	printf("Массив, созданный из чётных элементов предыдущего: \n");
	for (short int i = 0; i < length; i++)
	{
		if (*(mas + i) % 2 == 0)
		{
			counter1++;
			printf("%d\t", *(mas + i));
		}
	}
	printf("\n");
	printf("Массив, созданный из нечётных элементов предыдущего: \n");
	for (short int i = 0; i < length; i++)
	{
		if (*(mas + i) % 2 != 0)
		{
			counter2++;
			printf("%d\t", *(mas + i));
		}
	}
	printf("\n");
	printf("Чётных элементов %d.\n", counter1);
	printf("Нечётных элементов %d.\n", counter2);
	if (counter1 < counter2)
		printf("Чётных элементов меньше, чем нечётных.\n");
	else if (counter1 > counter2)
		printf("Чётных элементов больше, чем нечётных.\n");
	else if (counter1 == counter2)
		printf("Одинаковое количество чётных и нечётных элементов.\n");
}
void NotBiggerThan10(int *mas, int length)
{
	int counter = 0;
	for (short int i = 0; i < length; i++)
		if (*(mas + i) > 0 && *(mas + i) > 10)
			counter++;

	int *MASSSS = (int*)calloc(counter, sizeof(int));
	int k = 0;
	for (short int i = 0; i < length; i++)
	{
		if (*(mas + i) > 0 && *(mas + i) > 10)
		{

			*(MASSSS + k) = *(mas + i);
			k++;
		}
	}
	printArray(MASSSS, counter);
	printf("Кол-во положительных элементов = %d\n", counter);
	free(MASSSS);
}
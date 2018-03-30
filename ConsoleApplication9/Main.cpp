#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	short int w;
	printf("Введите номер задания: ");
	scanf("%hu", &w);
	switch (w)
	{
	case 1:
	{
		//1.Ввести вещественные числа. Создать из них массив.
		//Определить индекс второго положительного элемента массива.
		int *mass = NULL, length;
		printf("Введите длину массива: ");
		scanf("%d", &length);
		mass = (int*)calloc(length, sizeof(int));
		if (mass == NULL)
		{
			printf("Not enough memory.\n");
			exit(0);
		}
		else
		{
			fillArray(mass, length);
			printArray(mass, length);
			printf("Индекс второго положительного элемента = %d\n", SearchSecondPositivElement(mass, length));
		}
		free(mass);
	}
	break;
	case 2:
	{
		//2.Ввести вещественные числа.Создать из них массив.
		//Переставить элементы массива в обратном порядке.
		int *mas = NULL, length;
		printf("Введите длину массива: ");
		scanf("%d", &length);
		mas = (int*)calloc(length, sizeof(int));
		if (mas == NULL)
		{
			printf("Not enough memory.\n");
			exit(0);
		}
		else
		{
			fillArray(mas, length);
			printArray(mas, length);
			ReverseElements(mas, length);
			printArray(mas, length);
		}
	}
	break;
	case 3:
	{
		//3.Ввести целое число N и массив из N целых чисел.
		//Определить среднее арифметическое элементов массива, не кратных 3.
		int length = 0;
		int *mas = GetMemory(&length);
		fillArray(mas, length);
		printArray(mas, length);
		ElementNeKrat3(mas, length);
	}
	break;
	case 7:
	{
		//7.Ввести целые числа. Создать из них массив. 
		//Поменять местами последний и минимальный элементы массива.
		int *pointer = NULL;
		pointer = (int*)calloc(1, sizeof(int));
		int x = 1;
		do
		{
			printf("Введите число: ");
			if (scanf("%d", (pointer + x - 1)) == 1)
			{
				x++;
				pointer = (int *)realloc(pointer, (sizeof(int) * x));
			}
			else
				break;
		} while (true);
		x--;
		printArray(pointer, x);
		SwitchMinAndLastElement(pointer, x);
		printArray(pointer, x);
		free(pointer);
	}
	break;
	case 9:
	{
		//9.Ввести целые числа. Создать из них массив. 
		//Вычислить произведение элементов из промежутка(2, 8).
		int length = 0;
		int *mas = GetMemory(&length);
		fillArray(mas, length);
		printArray(mas, length);
		printf("Произведение с 2 по 8 = %ld\n", TwoTo8(mas));
		free(mas);
	}
	break;
	case 13:
	{
		//13.Ввести в StringGrid массив из 10 целых чисел. Создать два новых массива – 
		//из четных и нечётных элементов исходного массива. 
		//Определить, в каком массиве больше элементов.
		int length = 0;
		int *mas = GetMemory(&length);
		fillArray(mas, length);
		printArray(mas, length);
		ChetOrNechet(mas, length);
	}
	break;
	case 14:
	{
		//14.Ввести массив из 12 вещественных чисел. 
		//Создать новый массив из элементов исходного, 
		//в который не включать элементы, которые по модулю больше 10. 
		//Определить количество положительных элементов нового массива.
		int length = 0;
		int *mas = GetMemory(&length);
		fillArray(mas, length);
		printArray(mas, length);
		NotBiggerThan10(mas, length);
		fillArray(mas, length);
	}
	break;
	}
}

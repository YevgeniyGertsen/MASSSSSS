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
	printf("������� ����� �������: ");
	scanf("%hu", &w);
	switch (w)
	{
	case 1:
	{
		//1.������ ������������ �����. ������� �� ��� ������.
		//���������� ������ ������� �������������� �������� �������.
		int *mass = NULL, length;
		printf("������� ����� �������: ");
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
			printf("������ ������� �������������� �������� = %d\n", SearchSecondPositivElement(mass, length));
		}
		free(mass);
	}
	break;
	case 2:
	{
		//2.������ ������������ �����.������� �� ��� ������.
		//����������� �������� ������� � �������� �������.
		int *mas = NULL, length;
		printf("������� ����� �������: ");
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
		//3.������ ����� ����� N � ������ �� N ����� �����.
		//���������� ������� �������������� ��������� �������, �� ������� 3.
		int length = 0;
		int *mas = GetMemory(&length);
		fillArray(mas, length);
		printArray(mas, length);
		ElementNeKrat3(mas, length);
	}
	break;
	case 7:
	{
		//7.������ ����� �����. ������� �� ��� ������. 
		//�������� ������� ��������� � ����������� �������� �������.
		int *pointer = NULL;
		pointer = (int*)calloc(1, sizeof(int));
		int x = 1;
		do
		{
			printf("������� �����: ");
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
		//9.������ ����� �����. ������� �� ��� ������. 
		//��������� ������������ ��������� �� ����������(2, 8).
		int length = 0;
		int *mas = GetMemory(&length);
		fillArray(mas, length);
		printArray(mas, length);
		printf("������������ � 2 �� 8 = %ld\n", TwoTo8(mas));
		free(mas);
	}
	break;
	case 13:
	{
		//13.������ � StringGrid ������ �� 10 ����� �����. ������� ��� ����� ������� � 
		//�� ������ � �������� ��������� ��������� �������. 
		//����������, � ����� ������� ������ ���������.
		int length = 0;
		int *mas = GetMemory(&length);
		fillArray(mas, length);
		printArray(mas, length);
		ChetOrNechet(mas, length);
	}
	break;
	case 14:
	{
		//14.������ ������ �� 12 ������������ �����. 
		//������� ����� ������ �� ��������� ���������, 
		//� ������� �� �������� ��������, ������� �� ������ ������ 10. 
		//���������� ���������� ������������� ��������� ������ �������.
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

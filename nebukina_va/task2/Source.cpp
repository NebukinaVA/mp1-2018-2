#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "Rus");
	int numb1, numb2, mode, i, end;
	int min, max;
	int attempt = 0;
	char symbol;
	srand(time(NULL));
	numb1 = (rand() % 1000 + 1);
	symbol = '+';
	min = 0;
	max = 1000;
	attempt = 0;
	i = 0;
	printf("������� ����� ��������� ������\n 1) �� ����������� �����\n 2) ��������� ���������� �����\n");
	scanf_s("%i", &mode);
	while ((mode != 1) && (mode != 2))
	{
		printf("��� ������ ������. ���������� ��� ���.\n");
		scanf_s("%i", &mode);
	}
	if (mode == 1)
	{
		while (i != numb1)
		{
			printf("������� ����� �� 1 �� 1000\n");
			scanf_s("%i", &i);
			attempt++;
			if ((i > 1000) || (i < 1))
				printf("����� �� ������ � ��������. ���������� ��� ���.\n");
			else
				if (i > numb1)
					printf("���������� ����� ������\n");
				else
					if (i < numb1)
						printf("���������� ����� ������\n");
					else
						printf("�� �������!\n");
		}
		printf("���������� ������� %i\n", attempt);
	}
	else
	{
		printf("��������� ����� �� 1 �� 1000.\n");
		while (symbol!='=')
		{
			numb2 = (max + min) / 2;
			printf("���� ����� %i? ���� ��, ������� '=', ���� ���, ������� '<' ��� '>'\n", numb2);
			scanf_s("%c", &symbol);
			scanf_s("%c", &symbol);
			attempt++;
			switch (symbol)
			{
			case '>':
				min = numb2;
				break;
			case '<': 
				max = numb2;
				break;
			case '=': 
				printf("��������� ������ ����� �� %i �������.\n", attempt);
				break;
			default:
				printf("������� '=', '<' ��� '>'\n");
				break;
			}
		}
	}
	scanf_s("%i", &end);
	return 0;
}

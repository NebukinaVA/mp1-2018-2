#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define l 5
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int i, n, cash, number, end;
	int sum = 0;
	int amount[l] = { 0 };
	int code[l] = { 1238, 5349, 6357, 4562, 7589 };
	int price[l] = { 274, 856, 563, 159, 15 };
	int total[l] = { 0 };
	int discount[l] = { 0 };
	char drug[5][20] = { {"��������"}, {"������"}, {"��������"}, {"����������"}, {"����� 3 ��."} };
	printf("����� ���������� � ������!\n������� �������� �� �������������� ����:\n1238\n5349\n6357\n4562\n7589\n���� �� ��������� � ��������, ������� 0 ������ ���������.\n");
	scanf_s("%i", &n);
	for (i = 0; i < l; i++)
	{
		discount[i] = (rand() % 49 + 1);
	}
	while (n != 0)
	{
		while ((n != code[0]) && (n != 0) && (n != code[1]) && (n != code[2]) && (n != code[3]) && (n != code[4]))
		{
			printf("������ � ����� ���������� ���.\n");
			scanf_s("%i", &n);
		}
		for (i = 0; i < l; i++)
		{
			if (n == 0)
				break;
			else
				if (n == code[i])
				{
					printf("�����: ");
					puts(drug[i]);
					total[i] = price[i] * (100 - discount[i]) / 100;
					printf("���� %i ���.\n������ �� ����� %i ����.\n���� �� ����� � ������ ������ %i ���.\n", price[i], discount[i], total[i]);
					printf("������� ���������� ����������� ������: ");
					scanf_s("%i", &number);
					amount[i] += number;
					printf("������� �������� ���������� ������ ��� 0.\n");
					scanf_s("%i", &n);
					break;
				}
		}
	}
	for (i = 0; i < l; i++)
	{
		total[i] = amount[i] * (price[i] * (100 - discount[i]) / 100);
		sum += total[i];
	}
	printf("*�������� ���*\n");
	for (i = 0; i < l; i++)
	{
		if (amount[i] > 0)
		{
			puts(drug[i]);
			printf("���-�� %i,  ����� %i ���.\n", amount[i], total[i]);
		}
	}
	printf("���� %i ���.", sum);
	scanf_s("%i", &end);
}
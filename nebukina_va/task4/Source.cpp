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
	int i, n, cash, number, end, DISC;
	int TOT = 0;
	int sum = 0;
	int amount[l] = { 0 };
	int code[l] = { 1238, 5349, 6357, 4562, 7589 };
	int price[l] = { 274, 856, 563, 159, 15 };
	int total[l] = { 0 };
	int discount[l] = { 0 };
	char drug[5][20] = { {"Ксимелин"}, {"Имудон"}, {"Игаверин"}, {"Спазмалгон"}, {"Маски 3 шт."} };
	printf("Добро пожаловать в аптеку!\nВведите штрихкод из представленных ниже:\n1238\n5349\n6357\n4562\n7589\nЕсли вы закончили с покупкой, введите 0 вместо штрихкода.\n");
	scanf_s("%i", &n);
	for (i = 0; i < l; i++)
	{
		discount[i] = (rand() % 49 + 1);
	}
	while (n != 0)
	{
		while ((n != code[0]) && (n != 0) && (n != code[1]) && (n != code[2]) && (n != code[3]) && (n != code[4]))
		{
			printf("Товара с таким штрихкодом нет.\n");
			scanf_s("%i", &n);
		}
		for (i = 0; i < l; i++)
		{
			if (n == 0)
				break;
			else
				if (n == code[i])
				{
					printf("Товар: ");
					puts(drug[i]);
					total[i] = price[i] * (100 - discount[i]) / 100;
					printf("Цена %i руб.\nСкидка на товар %i проц.\nЦена на товар с учетом скидки %i руб.\n", price[i], discount[i], total[i]);
					printf("Введите количество покупаемого товара: ");
					scanf_s("%i", &number);
					amount[i] += number;
					printf("Введите штрихкод следующего товара или 0.\n");
					scanf_s("%i", &n);
					break;
				}
		}
	}
	for (i = 0; i < l; i++)
	{
		total[i] = amount[i] * (price[i] * (100 - discount[i]) / 100);
		sum += total[i];
		TOT += amount[i] * price[i];
	}
	DISC = TOT - sum;
<<<<<<< HEAD
	printf("*�������� ���*\n");
=======
	printf("*КАССОВЫЙ ЧЕК*\n");
>>>>>>> 399ea6102c3508ee8d350c139f0fc58b956b6db9
	for (i = 0; i < l; i++)
	{
		if (amount[i] > 0)
		{
			puts(drug[i]);
			printf("КОЛ-ВО %i,  СУММА %i РУБ.\n", amount[i], total[i]);
		}
	}
<<<<<<< HEAD
	printf("��������� ������� � ������� %i ���.\n��������� ������ %i ���.\n���� %i ���.", TOT, DISC, sum);
=======
	printf("СТОИМОСТЬ ТОВАРОВ В ПОКУПКЕ %i РУБ.\nСУММАРНАЯ СКИДКА %i РУБ.\nИТОГ %i РУБ.", TOT, DISC, sum);
>>>>>>> 399ea6102c3508ee8d350c139f0fc58b956b6db9
	scanf_s("%i", &end);
}

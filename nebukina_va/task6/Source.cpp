#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <locale.h>
#include <math.h>

void Sin(long double x, long double accuracy, long N)
{
	long double y = 0;
	long i, j;
	for (i = 0; i <= N; i++)
	{
		y = y + ((-1)^i)*(x ^ (2 * i + 1)) / ((2 * i + 1)!); // изменить тип х
	}
}

void Cos(long double x, long double accuracy, long N)
{
	long double y = 0;
	long i, j;
	for (i = 0; i <= N; i++)
	{
		y = y + ((-1) ^ i)*(x ^ (2 * i)) / ((2 * i)!); // изменить тип х
	}
}

void Exp(long double x, long double accuracy, long N)
{
	long double y = 0;
	long i, j;
	for (i = 0; i <= N; i++)
	{
		y = y + (x ^ i) / (i!); // изменить тип х
	}
}

int main()
{
	double x;
	long double accuracy, etalon, myresult;
	unsigned long double delta;
	long N = 0;
	int funct = 0;
	int mode = 0;

	setlocale(LC_ALL, "Rus");
	while ((mode != 1) && (mode != 2))
	{
    printf("Выберите режим:\n1) Однократный расчет функции в заданной точке.\n2) Серийный эксперимент.\n");
	scanf_s("%i", &mode);
	}
	if (mode == 1)
	{
		while ((funct < 1) || (funct > 4))
		{
		ptintf("Выберите функцию из предложенных:\n1) sin(x)\n2) cos(x)\n3) exp(x)\n4) arsh(x)\n");
		scanf_s("%i", &funct);
		}
		printf("Введите точку x, в которой необходимо вычислить значение.\n");
		scanf_s("%d", &x);
		printf("Введите желаемую точность результата (0.000001 или больше).\n");
		scanf_s("%d", &accuracy);
		while ((N < 1) || (N > 1000))
		{
			ptintf("Задайте число элементов ряда для выполнения расчета (от 1 до 1000):\n");
			scanf_s("%l", &N);
		}

		switch (funct)
		{
		case 1:
			etalon = sin(x);
			myresult = Sin(x, accuracy, N);
		case 2:
			etalon = cos(x);
		case 3:
			etalon = exp(x);
		case 4:
			etalon = arsh(x);
		}
		delta = | etalon - myresult | ;
		printf("Эталонное значение в точке x: %d", etalon);
		printf("Вычисленная оценка значения функции в точке x: %d", myresult);
		printf("Разница между оценкой и эталонным значением в точке x: %ud", delta);
	}
}

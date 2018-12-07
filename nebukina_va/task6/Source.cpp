#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <locale.h>
#include <math.h>

double F(long n)
{
	long i;
	long fact = 1;
	for (i = 1; i <= n; i++)
	{
		fact *= i;
	}
}

double mysin(long double x, long double accuracy, long N)
{
	long double y = 0;
	long i, j;
	for (i = 0; i <= N; i++)
	{
		y = y + ((-1) ^ i)*(pow(x, (2 * i + 1))) / (F(2 * i + 1));
	}
}

double mycos(long double x, long double accuracy, long N)
{
	long double y = 0;
	long i, j;
	for (i = 0; i <= N; i++)
	{
		y = y + ((-1) ^ i)*(pow(x, (2 * i))) / (F(2 * i)); 
	}
}

double myexp(long double x, long double accuracy, long N)
{
	long double y = 0;
	long i, j;
	for (i = 0; i <= N; i++)
	{
		y = y + (pow(x, i)) / (F(i)); 
	}
}

double myarsh(long double x, long double accuracy, long N)
{
        long double y = 0;
	long i;
	for (i = 0; i <= N; i++)
	{

	}
}

int main()
{
	double x;
	long double accuracy, etalon, myresult;
	long double delta;
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
		printf("Выберите функцию из предложенных:\n1) sin(x)\n2) cos(x)\n3) exp(x)\n4) arsh(x)\n");
		scanf_s("%i", &funct);
		}
		printf("Введите точку x, в которой необходимо вычислить значение.\n");
		scanf_s("%f", &x);
		printf("Введите желаемую точность результата (0,000001 или больше).\n");
		scanf_s("%f", &accuracy);
		while ((N < 1) || (N > 1000))
		{
			printf("Задайте число элементов ряда для выполнения расчета (от 1 до 1000):\n");
			scanf_s("%d", &N);
		}

		switch (funct)
		{
		case 1:
			etalon = sin(x);
		case 2:
			etalon = cos(x);
		case 3:
			etalon = exp(x);
		case 4:
			etalon = arsh(x);
		}
		delta = etalon - myresult; // по модулю
		printf("Эталонное значение в точке x: %f", etalon);
		printf("Вычисленная оценка значения функции в точке x: %f", myresult);
		printf("Разница между оценкой и эталонным значением в точке x: %fu", delta);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <locale.h>
#include <math.h>

long double mysin(double x, long double precision, int& N, long double stand)
{
	long double y = x;
	long double res = x;
	int i;
	for (i = 2; (i <= N) && (fabsl(stand - y) >= precision); i++)
	{
		res *= (-1) * ((x * x) / ((2 * i - 2) * (2 * i - 1)));
		y = y + res;
	}
	N = i - 1;
	return y;
}

long double mycos(double x, long double precision, int& N, long double stand)
{
	long double y = 1;
	long double res = 1;
	int i;
	for (i = 2; (i <= N) && (fabsl(stand - y) >= precision); i++)
	{
		res *= (-1) * ((x * x) / ((2 * i - 2) * (2 * i - 3)));
		y = y + res;
	}
	N = i - 1;
	return y;
}

long double myexp(double x, long double precision, int& N, long double stand)
{
	long double y = 1;
	long double res = 1;
	int i;
	for (i = 2; (i <= N) && (fabsl(stand - y) >= precision); i++)
	{
		res = (res * x) / (i - 1);
		y = y + res;
	}
	N = i - 1;
	return y;
}

long double myarsh(double x, long double precision, int& N, long double stand)
{
	long double y = x;
	long double res = x;
	int i;
	for (i = 2; (i <= N) && (fabsl(stand - y) >= precision); i++)
	{
		res *= (-1) * (x * x) * (2 * i - 3) * (2 * i - 3) / ((2 * i - 2) * (2 * i - 1));
		y = y + res;
	}
	N = i - 1;
	return y;
}

int main()
{
	double x;
	long double precision, stand, myresult = 0;
	long double delta = 0;
	int N = 0;
	int NMax = 0;
	int f_num = 0;
	int mode = 0;
	int add;
	void(*p)();
	long double(*myfunct[4])(double, long double, int&, long double);
	myfunct[0] = mysin;
	myfunct[1] = mycos;
	myfunct[2] = myexp;
	myfunct[3] = myarsh;
	double(*funct[5])(double);
	funct[0] = sin;
	funct[1] = cos;
	funct[2] = exp;
	funct[3] = asinh;

	setlocale(LC_ALL, "Rus");
	while ((mode != 1) && (mode != 2))
	{
		printf("�������� �����:\n1) ����������� ������ ������� � �������� �����.\n2) �������� �����������.\n");
		scanf_s("%i", &mode);
	}
	while ((f_num < 1) || (f_num > 4))
	{
		printf("�������� ������� �� ������������:\n1) sin(x)\n2) cos(x)\n3) exp(x)\n4) arsh(x)\n");
		scanf_s("%i", &f_num);
	}
	printf("������� ����� x, � ������� ���������� ��������� ��������.\n");
	scanf_s("%lf", &x);
	stand = funct[f_num - 1](x);
	if (mode == 1)
	{
		printf("������� �������� �������� ���������� (0,000001 ��� ������).\n");
		scanf_s("%lf", &precision);
		while ((N < 1) || (N > 1000))
		{
			printf("������� ����� ��������� ���� ��� ���������� ������� (�� 1 �� 1000):\n");
			scanf_s("%i", &N);
		}
		myresult = myfunct[f_num - 1](x, precision, N, stand);
		delta = fabsl(stand - myresult);
		printf("��������� �������� � ����� x: %lf\n", stand);
		printf("����������� ������ �������� ������� � ����� x: %lf\n", myresult);
		printf("������� ����� ������� � ��������� ��������� � ����� x: %lf\n", delta);
		printf("���������� ���������, ������� ���� ���������: %li\n", N);
	}
	else
	{
		while ((NMax < 1) || (NMax > 25))
		{
			printf("������� ����� ������������� NMax (�� 1 �� 25).\n");
			scanf_s("%d", &NMax);
		}
		delta = fabsl(stand - myresult);
		printf("  N           ������          ������          �������\n");
		printf("_____________________________________________________\n\n");
		for (int i = 1; i <= NMax; i++)
		{
			myresult = myfunct[f_num - 1](x, 0, i, stand);
			delta = fabsl(stand - myresult);
			printf("%3i %17lf %15lf %15lf\n", i, stand, myresult, delta);
		}
	}
	_getch();
}
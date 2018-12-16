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
<<<<<<< HEAD
		printf("Выберите режим:\n1) Однократный расчет функции в заданной точке.\n2) Серийный эксперимент.\n");
=======
		printf("Р’С‹Р±РµСЂРёС‚Рµ СЂРµР¶РёРј:\n1) РћРґРЅРѕРєСЂР°С‚РЅС‹Р№ СЂР°СЃС‡РµС‚ С„СѓРЅРєС†РёРё РІ Р·Р°РґР°РЅРЅРѕР№ С‚РѕС‡РєРµ.\n2) РЎРµСЂРёР№РЅС‹Р№ СЌРєСЃРїРµСЂРёРјРµРЅС‚.\n");
>>>>>>> 399ea6102c3508ee8d350c139f0fc58b956b6db9
		scanf_s("%i", &mode);
	}
	while ((f_num < 1) || (f_num > 4))
	{
<<<<<<< HEAD
			printf("Выберите функцию из предложенных:\n1) sin(x)\n2) cos(x)\n3) exp(x)\n4) arsh(x)\n");
			scanf_s("%i", &f_num);
	}
	printf("Введите точку x, в которой необходимо вычислить значение.\n");
=======
			printf("Р’С‹Р±РµСЂРёС‚Рµ С„СѓРЅРєС†РёСЋ РёР· РїСЂРµРґР»РѕР¶РµРЅРЅС‹С…:\n1) sin(x)\n2) cos(x)\n3) exp(x)\n4) arsh(x)\n");
			scanf_s("%i", &f_num);
	}
	printf("Р’РІРµРґРёС‚Рµ С‚РѕС‡РєСѓ x, РІ РєРѕС‚РѕСЂРѕР№ РЅРµРѕР±С…РѕРґРёРјРѕ РІС‹С‡РёСЃР»РёС‚СЊ Р·РЅР°С‡РµРЅРёРµ.\n");
>>>>>>> 399ea6102c3508ee8d350c139f0fc58b956b6db9
	scanf_s("%lf", &x);
	stand = funct[f_num - 1](x);
	if (mode == 1)
	{
<<<<<<< HEAD
		printf("Введите желаемую точность результата (0,000001 или больше).\n");
	    scanf_s("%lf", &precision);
		while ((N < 1) || (N > 1000))
		{
			printf("Задайте число элементов ряда для выполнения расчета (от 1 до 1000):\n");
=======
		printf("Р’РІРµРґРёС‚Рµ Р¶РµР»Р°РµРјСѓСЋ С‚РѕС‡РЅРѕСЃС‚СЊ СЂРµР·СѓР»СЊС‚Р°С‚Р° (0,000001 РёР»Рё Р±РѕР»СЊС€Рµ).\n");
	    scanf_s("%lf", &precision);
		while ((N < 1) || (N > 1000))
		{
			printf("Р—Р°РґР°Р№С‚Рµ С‡РёСЃР»Рѕ СЌР»РµРјРµРЅС‚РѕРІ СЂСЏРґР° РґР»СЏ РІС‹РїРѕР»РЅРµРЅРёСЏ СЂР°СЃС‡РµС‚Р° (РѕС‚ 1 РґРѕ 1000):\n");
>>>>>>> 399ea6102c3508ee8d350c139f0fc58b956b6db9
			scanf_s("%i", &N);
		}
		myresult = myfunct[f_num - 1](x, precision, N, stand);
		delta = fabsl(stand - myresult);
<<<<<<< HEAD
		printf("Эталонное значение в точке x: %lf\n", stand);
		printf("Вычисленная оценка значения функции в точке x: %lf\n", myresult);
		printf("Разница между оценкой и эталонным значением в точке x: %lf\n", delta);
		printf("Количество слагаемых, которое было вычислено: %li\n", N);
=======
		printf("Р­С‚Р°Р»РѕРЅРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ РІ С‚РѕС‡РєРµ x: %lf\n", stand);
		printf("Р’С‹С‡РёСЃР»РµРЅРЅР°СЏ РѕС†РµРЅРєР° Р·РЅР°С‡РµРЅРёСЏ С„СѓРЅРєС†РёРё РІ С‚РѕС‡РєРµ x: %lf\n", myresult);
		printf("Р Р°Р·РЅРёС†Р° РјРµР¶РґСѓ РѕС†РµРЅРєРѕР№ Рё СЌС‚Р°Р»РѕРЅРЅС‹Рј Р·РЅР°С‡РµРЅРёРµРј РІ С‚РѕС‡РєРµ x: %lf\n", delta);
		printf("РљРѕР»РёС‡РµСЃС‚РІРѕ СЃР»Р°РіР°РµРјС‹С…, РєРѕС‚РѕСЂРѕРµ Р±С‹Р»Рѕ РІС‹С‡РёСЃР»РµРЅРѕ: %li\n", N);
>>>>>>> 399ea6102c3508ee8d350c139f0fc58b956b6db9
	}
	else
	{
		while ((NMax < 1) || (NMax > 25))
		{
<<<<<<< HEAD
			printf("Задайте число экспериментов NMax (от 1 до 25).\n");
			scanf_s("%d", &NMax);
		}
		delta = fabsl(stand - myresult);
		printf("  N           ЭТАЛОН          ОЦЕНКА          РАЗНИЦА\n");
=======
			printf("Р—Р°РґР°Р№С‚Рµ С‡РёСЃР»Рѕ СЌРєСЃРїРµСЂРёРјРµРЅС‚РѕРІ NMax (РѕС‚ 1 РґРѕ 25).\n");
			scanf_s("%d", &NMax);
		}
		delta = fabsl(stand - myresult);
		printf("  N           Р­РўРђР›РћРќ          РћР¦Р•РќРљРђ          Р РђР—РќРР¦Рђ\n");
>>>>>>> 399ea6102c3508ee8d350c139f0fc58b956b6db9
		printf("_____________________________________________________\n\n");
		for (int i = 1; i <= NMax; i++)
		{
			myresult = myfunct[f_num - 1](x, 0, i, stand);
			delta = fabsl(stand - myresult);
			printf("%3i %17lf %15lf %15lf\n", i, stand, myresult, delta);
		}
	}
<<<<<<< HEAD
	scanf_s("%lf", &precision);

}
=======
	_getch();
} 
>>>>>>> 399ea6102c3508ee8d350c139f0fc58b956b6db9

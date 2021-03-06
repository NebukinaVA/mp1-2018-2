#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	float M, m1, m2, m3, m4, m5, end;
	float wood, pb, fb; // pb=ДСП, fb=ДВП
	float a1, b1, c1; // параметры накладной задней стенки из ДВП
	float b2, c2; // параметры боковин из ДСП
	float c3; // накладные верхняя и нижняя крышки из ДСП
	float c4; // накладные двери из дерева
	float c5; // внутренние полки в шкафу из ДСП
	printf("Введите по порядку через пробел плотность дерева, ДСП и ДВП в г/см^3\n");
	scanf_s("%f %f %f", &wood, &pb, &fb);
	printf("Введите по порядку через пробел высоту, ширину и толщину задней стенки из ДВП в см\n");
	scanf_s("%f %f %f", &a1, &b1, &c1);
	printf("Введите по порядку через пробел глубину и толщину боковин из ДСП в см\n");
	scanf_s("%f %f", &b2, &c2);
	printf("Введите толщину верхней и нижней крышек из ДСП в см\n");
	scanf_s("%f", &c3);
	printf("Введите толщину накладных дверей из дерева в см\n");
	scanf_s("%f", &c4);
	printf("Введите толщину внутренних полок из ДСП в см\n");
	scanf_s("%f", &c5);
	m1 = fb * a1 * b1 * c1;
	m2 = 2* pb * (a1 - 2 * c3) * b2 * c2;
	m3 = 2 * pb * b1 * c3 * (b2 + c1);
	m4 = wood * a1 * b1 * c4;
	m5 = pb * (b1 - 2 * c2) * b2 * c5 * ((a1 - 2 * c3) / 40);
	M = (m1 + m2 + m3 + m4 + m5) / 1000;
	printf("Масса шкафа %f кг\n", M);
	printf("Введите любое число, чтобы завершить");
	scanf_s("%f", &end);
}

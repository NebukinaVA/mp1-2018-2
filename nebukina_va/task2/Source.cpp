#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "Rus");
	int numb, mode, i;
	int attempt = 0;
	srand(time(NULL));
	numb = rand();
		printf("������� ����� ��������� ������\n 1) �� ����������� �����\n 2) ��������� ���������� �����\n");
	scanf_s("%i", &mode);
	if (mode = 1)
		do
		{
			printf("������� ����� �� 1 �� 1000");
	scanf_s("%i", &i);
	attempt + 1;
	if (i > numb)
		printf("���������� ����� ������\n");
	else
		printf("���������� ����� ������\n");
		} while (i != numb);
	printf("�� ������� �����!");

}
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "Rus");
	int numb, mode, i, end;
	int attempt = 0;
	char more, less;
	srand(time(NULL));
	numb = (rand() % 1000 + 1);
	attempt = 0;
	i = 0;
	printf("������� ����� ��������� ������\n 1) �� ����������� �����\n 2) ��������� ���������� �����\n");
	scanf_s("%i", &mode);
	if (mode = 1)
		while (i != numb);
	{
		printf("������� ����� �� 1 �� 1000");
		scanf_s("%i", &i);
		attempt++;
		if (i > numb)
			printf("���������� ����� ������\n");
		else
			if (i < numb)
				printf("���������� ����� ������\n");
			else
				printf("�� �������!\n");
		printf("���������� ������� %i\n", attempt);
	}
	scanf_s("%i", &end);
	return 0;
}
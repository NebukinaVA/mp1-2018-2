#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, num, i, a; //n - ����� �����
	int cow = 0;
	int bull = 0;
	int comp[5]; // ����� ����������
	int number[5]; // ����� ������
	int p; // ������
	srand(time(NULL));
	printf("���� '���� � ������'!\n �������� ����� ������������� �����.\n ������� 2, 3, 4 ��� 5.\n");
	scanf_s("%i", &n);
	while ((n < 2) && (n > 5))
	{
		printf("���������� �������� ����� ���� ������ 2, 3, 4 ��� 5.\n");
		scanf_s("%i", &n);
	}
	comp[0] = (rand() % 9 + 1);
	for (i = 1; i <= n; i++)
	{
		comp[i] = (rand() % 9 + 1);
		while (comp[i] == comp[i - 1])
		{
			comp[i] = (rand() % 9 + 1);
		}
	}
	printf("������� ��� ������� ����� � ���������������� �������.\n");
	scanf_s("%i", num);
	for (i=1; i<=n; i++)
		
		number[i]=num/
}
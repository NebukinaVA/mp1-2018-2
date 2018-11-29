#define _CRT_SECURE_NO_WARNINGS
#define NFILES 5000
#define length 32
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <string.h>
#include <locale.h>

void BubbleSort(unsigned long a[], char name[NFILES][length], long n)
{
	long i, j;
	unsigned int x;
	char p[200];
	
	for (i = 0; i < n; i++) 
	{         
		for (j = n - 1; j > i; j--) 
		{   
			if (a[j - 1] > a[j]) 
			{
				x = a[j - 1]; a[j - 1] = a[j]; a[j] = x;
				strncpy(p, name[j], length);
				strncpy(name[j], name[j - 1], length);
				strncpy(name[j - 1], p, length);
			}
		}
	}
}

int main(void)
{
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	long count = 0;
	int n = 0;
	int m = 0;
	int end;
	long i = 0;
	int sort = 0;
	int mode = 0;
	clock_t t1, t2;
	double tt;
	unsigned long sizes[NFILES];
	char names[NFILES][length];

	setlocale(LC_ALL, "Rus");
	while (n == 0) 
	{
		
		printf("Введите имя каталога в формате C:\\\\...\\\\*\n");
		gets_s(path, 200);
		if ((hFile = _findfirst(path, &c_file)) == -1L)
			printf("Файлов не найдено!\n");
		else
		{
			printf("Список файлов:\n\n");
			printf("FILE            SIZE\n", ' ');
			printf("----            ----\n", ' ');
			do {
				if (count < NFILES)
				{
					strncpy(names[count], c_file.name, length);
					sizes[count] = c_file.size;
					printf("%-12.12s   %10ld\n", c_file.name, c_file.size);
					count++;
				}
			} while (_findnext(hFile, &c_file) == 0);
			_findclose(hFile);				
			printf("\nКоличество файлов: %d\n", count);
			do {
				while ((sort < 1) || (sort > 3))
				{
					printf("Выберите метод сортировки:\n1) Пузырьком\n2) Выбором\n3) Вставками\n");
					scanf_s("%i", &sort);
				}
				while ((mode < 1) || (mode > 2))
				{
					printf("Выберите способ сортировки:\n1) По возрастанию\n2) По убыванию\n");
					scanf_s("%i", &mode);
				}
				switch (sort)
				{
				case 1:
					t1 = clock();
					BubbleSort(sizes, names, count);
					t2 = clock();
					break;
				}
				printf("Отсортированный список файлов:\n\n");
				printf("FILE            SIZE\n", ' ');
				printf("----            ----\n", ' ');
				if (m == 1)
				{
					for (i = 0; i < count; i++)
					{
						printf("%-12.12s %10u\n", names[i], sizes[i]);
					}
				}
				else {
					for (i = count - 1; i >= 0; i--)
					{
						printf("%-12.12s %10u\n", names[i], sizes[i]);
					}
				}
				tt = long double (t2 - t1) / CLOCKS_PER_SEC;
				printf("Время сортировки: %d клоков\n", tt);
				printf("Желаете изменить метод сортировки?\n0 - да, 1 - нет.\n");
				scanf_s("%i", &m);
				while ((m != 0) && (m != 1))
				{
					printf("Введите 0 или 1.\n");					
					scanf_s("%i", &m);
				}
			} while (m == 0);
			printf("Желаете отсортировать другой репозиторий?\n0 - да, 1 - нет.\n");
			scanf_s("%i", &n);
			while ((n != 0) && (n != 1))
			{
				printf("Введите 0 или 1.\n");
				scanf_s("%i", &n);
			}
		}
	}
	scanf_s("%i", &end);
	return 0;
}

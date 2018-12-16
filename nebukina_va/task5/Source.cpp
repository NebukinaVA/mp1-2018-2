<<<<<<< HEAD
﻿#define _CRT_SECURE_NO_WARNINGS
#define MAXSTACK 2048	
#define NFILES 5000
=======
#define _CRT_SECURE_NO_WARNINGS
#define NFILES 5000
#define length 32
>>>>>>> 399ea6102c3508ee8d350c139f0fc58b956b6db9
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <string.h>
#include <locale.h>

<<<<<<< HEAD
void bubbleSort(unsigned long a[], int indexes[], int count, int mode)
{
	int i, j, k;
	unsigned long x;
	for (i = 0; i < count; i++)
	{
		for (j = count - 1; j > i; j--)
		{
			int direct = mode ? (a[j - 1] < a[j]) : a[j - 1] > a[j];
			if (direct)
			{
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
				k = indexes[j - 1];
				indexes[j - 1] = indexes[j];
				indexes[j] = k;
			}
		}
	}
}

void BubbleSort(unsigned long a[], long size)
{
	long j, k = size - 1;
	long lb = 1, ub = size - 1;
	unsigned long x;
	do
	{
		for (j = ub; j > 0; j--)
		{
			if (a[j - 1] > a[j])
			{
				x = a[j - 1]; a[j - 1] = a[j]; a[j] = x;
				k = j;
			}
		}
		lb = k + 1;
		for (j = 1; j <= ub; j++)
		{
			if (a[j - 1] > a[j])
			{
				x = a[j - 1]; a[j - 1] = a[j]; a[j] = x;
				k = j;
			}
		}
		ub = k - 1;
	} while (lb < ub);
}

void SelectSort(unsigned long a[], long size)
{
	long i, j, k;
	unsigned long x;
	for (i = 0; i < size; i++)  	// i - номер текущего шага
	{
		k = i; x = a[i];
		for (j = i + 1; j < size; j++)	// цикл выбора наименьшего элемента
		{
			if (a[j] < x)
			{
				k = j; x = a[j];	         // k - индекс наименьшего элемента
			}
			a[k] = a[i]; a[i] = x;   	// меняем местами наименьший с a[i]
=======
void SelectSort(unsigned long a[], char name[NFILES][length], long n)
{
	long i, j, k;
	unsigned long x;
	char p[200];
	for (i = 0; i < n; i++)  	
	{
		k = i; x = a[i];
		for (j = i + 1; j < n; j++)	
		{
			if (a[j] < x)
			{
				k = j; x = a[j];	         
			}
			a[k] = a[i]; a[i] = x;   	
			strncpy(p, name[k], length);
			strncpy(name[k], name[i], length);
			strncpy(name[i], p, length);
>>>>>>> 399ea6102c3508ee8d350c139f0fc58b956b6db9
		}
	}
}

<<<<<<< HEAD
void InsertSort(unsigned long a[], long size)
{
	unsigned long x;
	long i, j;
	for (i = 0; i < size; i++)   // цикл проходов, i - номер прохода
	{
		x = a[i];
		// поиск места элемента в готовой последовательности 
		for (j = i - 1; (j >= 0) && (a[j] > x); j--)
		{
			a[j + 1] = a[j];  	// сдвигаем элемент направо, пока не дошли
		}                       // место найдено, вставить элемент
		a[j + 1] = x;
	}
}

// можно улучшить
=======
void InsertSort(unsigned long a[], char name[NFILES][length], long n)
{
	unsigned long x;
	long i, j;
	char p[200];
	for (i = 0; i < n; i++)   
	{
		x = a[i];
		strncpy(p, name[i], 32);
		for (j = i - 1; (j >= 0) && (a[j] > x); j--)
		{
			a[j + 1] = a[j]; 
			strncpy(name[j + 1], name[j], length);
		}                      
		a[j + 1] = x;
		strncpy(name[j + 1], p, length);
	}
}

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
>>>>>>> 399ea6102c3508ee8d350c139f0fc58b956b6db9

int main(void)
{
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
<<<<<<< HEAD
	int count = 0;
	int end;
	int n = 0;
	int i = 0;
	int j = 0;
	int sort = 0;
	int mode = 0;
	clock_t t1, t2;
	double tt;
	int indexes[NFILES];
	unsigned long sizes[NFILES] = { 0 };
	char names[NFILES][32];
	char buffer[30];
    
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < NFILES; i++)
	{ 
		indexes[i] = i;
	}
	   	
	// Find first .c file in directory c:\temp
	while (n = 0) 
	{
		printf("Введите имя каталога в формате C:\\\\...\\\\*\n");
		gets_s(path);
		if ((hFile = _findfirst(path, &c_file)) == -1L)
		{
			printf("Файлов не найдено!\n");
		}
		else
		{
			while ((sort < 1) || (sort > 3))
			{
				printf("Выберите метод сортировки:\n1) Пузырьком\n2) Выбором\n3) Вставками\n");
				scanf_s("%i", &sort);
			}
			while ((mode < 1) || (mode > 2))
			{
				printf("Выберите сортировку:\n1) По возрастанию\n2) По убыванию\n");
				scanf_s("%i", &mode);
			}

			do
			{

				if (i >= 0)
				{
					sizes[i] = c_file.size;
					strncpy(names[i], c_file.name, 250);
					count++;
				}
				ctime_s(buffer, _countof(buffer), &c_file.time_write);
				i++;

			} while (_findnext(hFile, &c_file) == 0);
			_findclose(hFile);
			printf("\nКоличество файлов: %d\n", count);
		}
		t1 = clock();
		switch (sort)
		{
		case 1:
			bubbleSort(sizes, indexes, count, mode);
			break;
		}
		t2 = clock();
		tt = double(t1 - t2) / CLOCKS_PER_SEC;
		printf("FILE            SIZE\n", ' ');
		printf("----            ----\n", ' ');
		for (i = 0; i < count; i++)
		{
			printf("%-12.12s  %10ld\n", names[i], sizes[i]);
		}
		printf("Время сортировки: %d", tt);
		printf("Желаете отсортировать другой репозиторий?\n0 - да, 1 - нет.");
	}
	scanf_s("%i", &end);
}
=======
	long count = 0;
	int n = 0;
	int m = 0;
	int end;
	long i = 0;
	int sort, mode;
	clock_t t1, t2;
	double tt = 0;
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
					printf("%-12.12s   %10lu\n", c_file.name, c_file.size);
					count++;
				}
			} while (_findnext(hFile, &c_file) == 0);
		    _findclose(hFile);		
			do {
		        sort = 0;
		        mode = 0;			
			    printf("\nКоличество файлов: %d\n", count);
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
				case 2:
					t1 = clock();
					SelectSort(sizes, names, count);
					t2 = clock();
				case 3: 
					t1 = clock();
					InsertSort(sizes, names, count);
					t2 = clock();
				}
				printf("Отсортированный список файлов:\n\n");
				printf("FILE            SIZE\n", ' ');
				printf("----            ----\n", ' ');
				if (mode == 1)
				{
					for (i = 0; i < count; i++)
					{
						printf("%-12.12s %10lu\n", names[i], sizes[i]);
					}
				}
				else {
					for (i = count - 1; i >= 0; i--)
					{
						printf("%-12.12s %10lu\n", names[i], sizes[i]);
					}
				}
				tt = double (t2 - t1) / CLOCKS_PER_SEC;
				printf("Время сортировки: %f\n", tt);
				printf("Желаете изменить метод сортировки?\n0 - да, 1 - нет.\n");
				scanf_s("%i", &m);
				while ((m != 0) && (m != 1))
				{
					printf("Введите 0 или 1.\n");					
					scanf_s("%i", &m);
				}
			} while (m == 0);
			n = 1;			
		}
	}
}
>>>>>>> 399ea6102c3508ee8d350c139f0fc58b956b6db9

#define _CRT_SECURE_NO_WARNINGS
#define MAXSTACK 2048	
#define NFILES 5000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <string.h>
#include <locale.h>

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
		}
	}
}

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

int main(void)
{
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
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
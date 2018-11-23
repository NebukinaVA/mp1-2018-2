#define _CRT_SECURE_NO_WARNINGS
#define MAXSTACK 2048	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <string.h>
 
void BubbleSort(long size, unsigned long a[])
{
	long j, k = size - 1;
	long lb = 1, ub = size - 1; // ������� ����������������� ����� �������
	unsigned long x;
	do 
	{
		for (j = ub; j > 0; j--) // ������ ����� ����� 
		{
			if (a[j - 1] > a[j]) 
			{
				x = a[j - 1]; a[j - 1] = a[j]; a[j] = x;
				k = j;
			}
		}
		lb = k + 1;	
		for (j = 1; j <= ub; j++) // ������ ������ ���� 
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
	for (i = 0; i < size; i++)  	// i - ����� �������� ����
	{
		k = i; x = a[i];
		for (j = i + 1; j < size; j++)	// ���� ������ ����������� ��������
		{
			if (a[j] < x)
			{
				k = j; x = a[j];	        // k - ������ ����������� ��������
			}
			a[k] = a[i]; a[i] = x;   	// ������ ������� ���������� � a[i]
		}
	}
}

void insertSort(unsigned long a[], long size) 
{
	unsigned long x;
	long i, j;
	for (i = 0; i < size; i++)   // ���� ��������, i - ����� �������
		{
		x = a[i];
		// ����� ����� �������� � ������� ������������������ 
		for (j = i - 1; (j >= 0) && (a[j] > x); j--)
		{
			a[j + 1] = a[j];  	// �������� ������� �������, ���� �� �����
		}
		  // ����� �������, �������� �������
	    a[j + 1] = x; 
	}
}  

// ����� ��������

void QuickSort(unsigned long a[], long size) 
{
	long i, j;   			// ���������, ����������� � ����������
	long lb, ub;  		// ������� ������������ � ����� ���������
	long lbstack[MAXSTACK], ubstack[MAXSTACK]; // ���� �������� + ��. �������				
	long stackpos = 1;   	// ������� ������� �����
	long ppos;            // �������� �������
	unsigned long pivot;              // ������� �������
	unsigned long temp;
	lbstack[1] = 0;
	ubstack[1] = size - 1;
	do {
		lb = lbstack[stackpos]; // ����� ������� lb � ub �������� ������� �� �����.
		ub = ubstack[stackpos];
		stackpos--;
		do {
			ppos = (lb + ub) >> 1; // ��� 1. ���������� �� �������� pivot
			i = lb; j = ub; pivot = a[ppos];
			do {
				while (a[i] < pivot) i++;
				while (pivot < a[j]) j--;

				if (i <= j) 
				{
					temp = a[i]; a[i] = a[j]; a[j] = temp;
					i++; j--;
				}
			} while (i <= j); // ��. �������
			if (i < ppos)      // ������ ����� ������
			{
				if (i < ub)      //  ���� � ��� ������ 1 �������� - ����� 
				{
					stackpos++;       //  �����������, ������ � ����
					lbstack[stackpos] = i;
					ubstack[stackpos] = ub;
				}
				ub = j;             //  ��������� �������� ����������
									//  ����� �������� � ����� ������
			}
			else                  
// ����� ����� ������
			{       	    
				if (j > lb) 
				{
					stackpos++;
					lbstack[stackpos] = lb;
					ubstack[stackpos] = j;
				}
				lb = i;
			}
		} while (lb < ub);        // ���� � ������� ����� ����� 1 ��������
	} while (stackpos != 0);    // ���� ���� ������� � �����
}

int increment(long inc[], long size) 
{
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2) 
		{
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else 
		{
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);
	return s > 0 ? --s : 0;
}
void shellSort(unsigned long a[], long size) 
{
	long inc, i, j, seq[40];
	int s;
	s = increment(seq, size);   // ���������� ������������������ ����������
	while (s >= 0) 
	{
		inc = seq[s--];  // ���������� ��������� � ������������ inc[] 
		for (i = inc; i < size; i++) 
		{
			unsigned long temp = a[i];
			for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc)
			{
				a[j + inc] = a[j];
				a[j + inc] = temp;
			}
		}
	}
}

int main()
{
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	int count = 0;
	int i, j, n;

	// Find first .c file in directory c:\temp
	printf("�������� ����� ����������:\n1)��������\n2)�������\n3)���������\n4)��������\n");
	scanf_s("%i", n);
	printf("������� ��� ��������.\n");
	scanf_s("%s", path);
	if ((hFile = _findfirst("c:\\temp\\*.*", &c_file)) == -1L)
		printf("No files in current directory!\n");
	else
	{
		printf("Listing of .c files\n\n");
		printf("FILE         DATE %24c   SIZE\n", ' ');
		printf("----         ---- %24c   ----\n", ' ');
		do {
			char buffer[30];
			ctime_s(buffer, _countof(buffer), &c_file.time_write);
			if (count <= 20)
				printf("%-12.12s %.24s  %10ld\n", c_file.name, buffer, c_file.size);
			count++;
		} while (_findnext(hFile, &c_file) == 0);
		_findclose(hFile);
		printf("\ncount of files: %d", count);
	}

}
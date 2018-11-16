#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <string.h>

int main()
{
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];
	int count = 0;
	int i, j, n;

	// Find first .c file in directory c:\temp
	printf("¬ыберите метод сортировки:\n1)пузыьком\n2)выбором\n3)вставками\n4)сли€нием\n");
	scanf_s("%i", n);
	printf("¬ведите им€ каталога.\n");
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
	// !сортировка пузырьком!
	//  for( i=0; i < size; i++) {            // i - номер прохода
    //	for (j = size - 1; j > i; j--) {     // внутренний цикл прохода
	//	if (a[j - 1] > a[j]) {
	//		x = a[j - 1]; a[j - 1] = a[j]; a[j] = x; }

	//	


}
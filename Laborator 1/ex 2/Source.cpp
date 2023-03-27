#include <stdio.h>
#pragma warning(disable:4996)
int convert(char *numar)
{
	long nr = 0;
	while(*numar!='\n')
	{
		int c = *numar - '0';
		nr = nr*10  + c;
		numar++;
	}
	return nr;
}

int main()
{
	FILE* fptr;
	fptr = fopen("in.txt", "r");
	char a[100];

	long s = 0;

	if (fptr == nullptr)
	{
		printf("Error! opening file");
		return 1;

	}

	while (fgets(a, 100, fptr) != NULL)
	{	
		s=s+convert(a);
	}
	printf("Suma: %d\n", s);

	fclose(fptr);
	return 0;
}

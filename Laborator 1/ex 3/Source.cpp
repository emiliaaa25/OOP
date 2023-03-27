#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{
	int i, j, n=0, lungimi[100],aux1;
	char prop[256], mat[256][100], aux[256];
	scanf("%[^\n]", prop);
	i = 0;
	while (prop[i] != '\0')
	{
		while (prop[i] == ' ')
			i++;
		j = 0;
		while (prop[i] != '\0' && prop[i] != ' ')
		{
			mat[n][j] = prop[i];
			i++;
			j++;
		}
		mat[n][j] = '\0';
		lungimi[n] = j;
		n++;

	}

	for (i = 0;i < n - 1;i++)
		for (j = i + 1;j < n;j++)
			if (lungimi[i] < lungimi[j] || (lungimi[i] == lungimi[j] && strcmp(mat[i], mat[j]) < 0))
			{
				strcpy(aux, mat[i]);
				strcpy(mat[i], mat[j]);
				strcpy(mat[j], aux);
				aux1 = lungimi[i];
				lungimi[i] = lungimi[j];
				lungimi[j] = aux1;
			}
	for (int i = 0; i < n; i++) 
		printf("%s\n", mat[i]);
	
return 0;
			
}
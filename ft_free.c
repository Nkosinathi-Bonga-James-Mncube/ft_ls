#include "ft_ls.h"

void ft_free(char *x, char **arr, int total)
{
	int k;
	k = 0;
	if (arr != NULL)
	{
		while (k < total)	
		{
			free(arr[k]);
			k++;
		}
		free(arr);
	}
	if (x != NULL)
		free(x);
}

#include "ft_ls.h"

int ft_arv_count(char **arv)
{
	static int i;
	int k;
	k = 1;
	
	if (arv != NULL)
	{
		while (arv[k] && *arv[k]!= '\0')
		{
			if (arv[k][0]!= '-')
			i = i + 1;
			k++;
		}
	}
	return (i);
}

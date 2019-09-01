#include "ft_ls.h"

int	ft_find(char *s1, char *s2)
{
	int k;
	int j;

	k = 0;
	j = 0;
	while (s1[k] != '\0' || s2[j]!= '\0')
	{
		if (s1[k] != s2[j])
		{
			if(s1[k] > s2[j])
				return (s1[k]);
			else
				return (0);
		}
		if (s1[k] != '\0')
			k++;
		if (s2[j] != '\0')
			j++;
	}
	return (0);
}

void	ft_swap(char **s1, char **s2)
{
	char *temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

char **ft_bubble_sort(char **arr , int n)
{
	int i;
	int j;

	i = 0;	
	while ( i < n -1)
	{
		j = 0;
		while (j < (n - i-1))
		{
			if (ft_find(arr[j], arr[j+1]) > 0)
				ft_swap(&arr[j] , &arr[j +1]);
			j++;
		}
		i++;
	}
	j = 0;
	return (arr);
}

#include "ft_ls.h"

int ft_find(char *s1, char *s2)
{
	int k;
	k = 0;
	while (s1[k] != '\0' && s2[k]!= '\0')
	{
		if(s1[k] != s2[k])
		{
			//printf(" s1 %s %d\n" ,s1, s1[k]);
			//printf(" s2 %s %d\n" ,s2 ,s2[k]);
			return (s1[k]);
		}
		k++;
	}
	return(0);
}
void ft_swap(char **s1, char **s2)
{
	char *temp;
	//printf("before : %s\n" , *s1);
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
	//printf("after : %s\n" , *s2);
}

void ft_bubble_sort(char **arr , int n)
{
	int i;
	int j;
	int k;//not needed
	int x;

	k = 0;
	i= 0;
	//printf("%s" , arr[j+1]);
	while ( i < n -1)
	{
		//printf("im here1");
		j = 0;
		while (j < (n - i-1))
		{
			printf("%s\n" , arr[j]);
			if (ft_find(arr[j], arr[j+1]) > 0)
			{
				//printf("im herex");
				ft_swap(&arr[j] , &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
	while (k < n)
	{
		printf("%s\n" , arr[k]);
		k++;
	}
}

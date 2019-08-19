#include "ft_ls.h"

int ft_find1(char *s1, char *s2)
{
	int k;
	int j;
	struct stat b1;
	struct stat b2;
	static int i;
	k = 0;
	j = 0;

	while (s1[k] != '\0' || s2[j] != '\0')
	{
		i = i+ 1;
		stat(&s1[k],&b1);
		stat(&s2[j],&b2);
		if (s1[k] != s2[j])
		{
			if (b1.st_mtime <= b2.st_mtime)
			{
				//if (s1[k] > s2[j])
				//	return (s1[k]);
				if (b1.st_mtime == b2.st_mtime)
				{
					return(s2[j]);
				}
				else
				 return (s1[k]);
			}
		}
		if (s1[k] != '\0' || s2[j]!= '\0')
		{
			k++;
			j++;
		}
	}
	return (0);
}

void ft_swap1(char **s1, char **s2)
{
	char *temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;

}

void ft_bubble_sort1(char **arr, int n)
{
	int i;
	int j;
	struct stat b2;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < (n-i-1))
		{
			if (ft_find1(arr[j], arr[ j + 1]) > 0)
				ft_swap1(&arr[j], &arr[j +1]);
			j++;
		}
	i++;
	}
	j = 0;
	//stat(arr[j], &b2);
	while (j < n)
	{
		stat(arr[j], &b2);
		ft_putstr(arr[j]);
		printf("\n%s\n" ,ctime(&b2.st_mtime));
		ft_putchar('\n');
		j++;
	}
}
void ft_mod(char **arr, int total)
{
	struct group *b2;
	struct stat b1;
	struct stat b3;
	int i;
	int j;
	//time_t seconds;
	char *hold;

	i = 0;
	j = 0;
	printf("\n");
	while (i < total)
	{
		
		//struct stat b1 {0};
		stat(arr[i], &b1);
		//printf("%s\n" , arr[i]);
		//ft_bubble_sort1(arr,total);//<-test
		//b2 = getgrgid(b1.st_gid);
		//hold = ctime(&b1.st_mtime);
		//ft_date(b1, i);
		//struct stat b1;
		//printf("%ld\n" , b1.st_mtime);//epoch time
		//printf("%s\n" ,ctime(&b1.st_mtime));//last modified
		//printf("-----------\n");
		//printf("\n%ld->\n" , seconds);
		//seconds = time((char*)ctime(&b1.st_mtime));
		//ft_putstr(ctime(&b1.st_mtime));
		i++;
		//printf("\nvalue :%lld\n" , b1.st_size);
	}
	ft_bubble_sort1(arr,total);

}

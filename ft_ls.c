/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:55:00 by nmncube           #+#    #+#             */
/*   Updated: 2019/08/04 14:56:09 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>//if I remove this , the program doesnt work?
#include "libft/libft.h"

void ft_swap(char **s1 , char **s2)
{
	printf("Before : %s\n ", *s1);
	char *temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
	printf("After : %s\n" , *s1);
	printf("------\n");
}

int loop(char **arr, char *hold ,int low,int high)
{
	low = low -1;
	while (arr[low] <= arr[high])
	{
		if(arr[low] < hold)
			low++;
		if (arr[high] > 0 && arr[high] > hold)
			high--;
	
		ft_swap(&arr[low], &arr[high]);
	}
	ft_swap(&arr[low] , &arr[high]);
	return(low);
}

void ft_quick_sort(char **arr,int low, int high)
{
	char *hold;
   	int hold2;
	//printf("im here");
	if (low < high)
	{
		
		//printf("im here2");
		hold = arr[high];
		//printf("%s" , hold);
		hold2 = loop( arr ,hold,low, high);
		ft_quick_sort(arr, low, hold2 - 1);
		ft_quick_sort(arr, hold2 + 1 , high);
	}
}
void	ft_ls(int total)
{
	DIR				*dir;
	int				k;
	int				j;
	struct dirent	*dp;
	char			**arr;

	dir = opendir(".");
	k = 0;
	j = 0;
	if (dir == NULL)
	{
		perror("Cannot open");
		exit(1);
	}
	arr = (char**)malloc(total * sizeof(char*));
	while ((dp = readdir(dir)) != NULL && total > 0)
	{
		if (dp->d_name[0] != '.')
		{
			arr[k] = ft_strdup(dp->d_name);
			//printf("%s \t" , arr[k]);
			k++;
		}
	}
	ft_quick_sort(arr,0,total -1);//issue here?
	/*while (j < total)
	{
		printf("%s \t" , arr[j]);
		j++;
	}*/
}

int		ft_count(void)
{
	DIR				*dir;
	static int		k;
	struct dirent	*dp;

	dir = opendir(".");
	k = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.')
			k++;
	}
	return (k);
}

int		main(int argc, char**argv)
{
	static int total;

	//printf("zZz");
	if (argc == 2 && argv[1][0] == 'l' && argv[1][1] == 's')
	{
		//printf("inside");
		total = total + ft_count();
		ft_ls(total);
	}
		//if (argc =)
	
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:55:00 by nmncube           #+#    #+#             */
/*   Updated: 2019/08/02 17:04:18 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>//if I remove this , the program doesnt work?
#include "libft/libft.h"

void ft_swap(char *s1 , char *s2)
{
	char *temp;
	temp = s1;
	s1 = s2;
	s2 = temp;
}

int loop (char *arr, int low, int high)
{
	int hold;
	int j;
	int i;

	j = low;
	i = (low - 1);
	hold = arr[high];

	while (j <= high - 1)
	{
		if (arr[j] <= hold)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
	}
	ft_swap(&arr[i + 1] , &arr[high]);
	return (i + 1);
}
	
void ft_quick_sort(char *arr, int low, int high)
{
	int value;
	
	value = 0;
	if (low < high)
	{
		value = loop(arr, low,high);
		ft_quick_sort(arr, low, value - 1);			
		ft_quick_sort(arr, value + 1, high);
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

	//printf("im here");
	if (argc == 2 && argv[1][0] == 'l' && argv[1][1] == 's')
	{
		total = total + ft_count();
		ft_ls(total);
	}
		//if (argc =)
	
	return (0);
}

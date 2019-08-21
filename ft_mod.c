/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:09:15 by nmncube           #+#    #+#             */
/*   Updated: 2019/08/21 09:58:42 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_find1(char *s1, char *s2, struct stat b1, struct stat b2)
{
	int k;
	int j;

	k = 0;
	j = 0;
	while (s1[k] != '\0' || s2[j] != '\0')
	{
		if (s1[k] != s2[j])
		{
			if (b1.st_mtime <= b2.st_mtime)
			{
				if (b1.st_mtime == b2.st_mtime)
				{
					if (b1.st_mtimespec.tv_nsec <= b2.st_mtimespec.tv_nsec)
						return(s2[j]);
				}
				else
					return (s1[k]);
			}
		}
		if (s1[k++] != '\0' || s2[j++]!= '\0')
		{}
	}
	return (0);
}

void	ft_swap1(char **s1, char **s2)
{
	char *temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_bubble_sort1(char **arr, int n)
{
	int i;
	int j;
	struct stat b1;
	struct stat b2;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < (n - i - 1))
		{
			stat(ft_strjoin("libft/",arr[j]), &b1);
			stat(ft_strjoin("libft/",arr[j + 1]), &b2);
			if (ft_find1(arr[j], arr[j + 1] ,b1 , b2) > 0)
				ft_swap1(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	/////////////////////////////////////
	j = 0;
	printf("%s" , "\n-----------\n");
	while (j < n)
	{
		//stat(arr[j], &b1);
		ft_putstr(arr[j]);
		ft_putchar('\n');
		j++;
	}
}
void ft_mod(char **arr, int total)
{
	printf("\n");	
	ft_bubble_sort1(arr,total);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:09:15 by nmncube           #+#    #+#             */
/*   Updated: 2019/09/22 14:29:59 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void ft_swap1(char **s1, char **s2)
{
	char *temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void ft_find1(char **s1, char **s2, char *s3)
{
	struct stat b1;
	struct stat b2;
	char *x;
	char *y;

	
	x = ft_strjoin(s3,*s1);
	y = ft_strjoin(s3,*s2);
	stat(x,&b1);
	stat(y,&b2);
	if (b1.st_mtime < b2.st_mtime)
		ft_swap1(s1,s2);
	else
		if (b1.st_mtime == b2.st_mtime)
		{
			if (b1.st_mtimespec.tv_nsec < b2.st_mtimespec.tv_nsec)
				ft_swap1(s1, s2);
		}
	free(x);
	free(y);
}

char **ft_mod(char *folder,char **arr, int n)
{
	int j;
	int i;
	char *s3;

	s3 = ft_strjoin(folder,"/");
	i = 0;
		while (i < n - 1)
		{
			j = 0;
			while (j < (n - i - 1))
			{
				ft_find1(&arr[j], &arr[j + 1],s3);
				j++;
			}
			i++;
		};
	free(s3);
	return (arr);
}
